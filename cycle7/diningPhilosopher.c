#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>

sem_t c[5];
pthread_t p[5];

void *dine(void *args){
    int i= *((int *)args);

    printf("P%d is hungry\n",i+1);
    sem_wait(&c[i]);
    sem_wait(&c[(i+1)%5]);
    printf("p%d has both chopsticks %d and %d\n",i+1,i,(i+1)%5);
    sleep(2);
    sem_post(&c[i]);
    sem_post(&c[(i+1)%5]);
    printf("p%d has released both chopsticks\n",i+1);
}

 
void main(){
    printf("Dining Philosopher problem\n\n");
    int i,a[5];

    for(i=0;i<5;i++){
        sem_init(&c[i],0,1);
        a[i] = i;
    }

    for(i=0;i<5;i++)
        pthread_create(&p[i],NULL,(void *)dine,(void *)&a[i]);
    for(i=0;i<5;i++)
        pthread_join(p[i],NULL);

    for(i=0;i<5;i++)
        sem_destroy(&c[i]);
}