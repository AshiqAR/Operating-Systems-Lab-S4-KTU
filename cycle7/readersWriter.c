#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

sem_t wrt;
pthread_mutex_t mutex;
int x = 1,readcount = 0;

void reader(void *arg){
    int n = rand()%5;
    sleep(n);
    pthread_mutex_lock(&mutex);
    readcount++;
    if(readcount == 1)
        sem_wait(&wrt);
    pthread_mutex_unlock(&mutex);

    printf("Reader%d reads x = %d\n",*((int *)arg),x);

    pthread_mutex_lock(&mutex);
    readcount--;
    if(readcount==0)
        sem_post(&wrt);
    pthread_mutex_unlock(&mutex);
}

void writer(void *arg){
    int n = rand()%5;
    sleep(n);
    sem_wait(&wrt);
    x *= 2;
    printf("Writer%d writes x to %d\n",*((int *)arg),x);
    sem_post(&wrt);
}

void main(){
    int nr,nw;
    printf("Enter the number of readers and writers: ");
    scanf("%d %d",&nr,&nw);
    pthread_t r[nr],w[nw];
    
    sem_init(&wrt,0,1);
    pthread_mutex_init(&mutex,NULL);

    int a[20],i;
    for( i=0;i<20;i++)
        a[i] = i+1;
    
    for(i=0;i<nw;i++)
        pthread_create(&w[i], NULL, (void *)writer, (void *)&a[i]);

    for(i=0;i<nr;i++)
        pthread_create(&r[i], NULL, (void *)reader, (void *)&a[i]);

    for(i=0;i<nw;i++)
        pthread_join(w[i],NULL);
    for(i=0;i<nr;i++)
        pthread_join(r[i],NULL);

    sem_destroy(&wrt);
    pthread_mutex_destroy(&mutex);
}