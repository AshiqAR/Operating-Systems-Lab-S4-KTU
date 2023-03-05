// Producer Consumer Problem

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

sem_t empty,full;
pthread_mutex_t mutex;
int buffer[5],count=0;

void producer(void *args){
    sem_wait(&empty);
    pthread_mutex_lock(&mutex);
    buffer[count] = rand()%50;
    printf("Producer %d produces %d count = %d\n",*((int *)args),buffer[count],count);
    count++;
    pthread_mutex_unlock(&mutex);
    sem_post(&full);
}

void consumer(void *args){
    sem_wait(&full);
    pthread_mutex_lock(&mutex);
    long int i = (long int) args;
    count--;
    printf("Consumer %d consumed %d\n",*((int *)args),buffer[count]);
    pthread_mutex_unlock(&mutex);
    sem_post(&empty);
}

void main(){
    int np,nc;
    printf("Enter the number of producers: ");
    scanf("%d",&np);
    printf("Enter the number of consumers: ");
    scanf("%d",&nc);
    pthread_t p[np],c[nc];

    sem_init(&full,0,0);
    sem_init(&empty,0,5);
    pthread_mutex_init(&mutex,NULL);
    int i;
    int a[20];
    for(i=0;i<20;i++)
        a[i] = i+1;

    for(i=0;i<np;i++)
        pthread_create(&p[i],NULL,(void *) producer,(void *)&a[i]);
    
    for(i=0;i<nc;i++)
        pthread_create(&c[i],NULL,(void *) consumer,(void *)&a[i]);

    for(i=0;i<np;i++)
        pthread_join(p[i],NULL);
    for(i=0;i<nc;i++)
        pthread_join(c[i],NULL);

    sem_destroy(&full);
    sem_destroy(&empty);
    pthread_mutex_destroy(&mutex);
    
}