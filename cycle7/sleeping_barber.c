// Sleeping Barber Problem

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

sem_t customer,barber;
pthread_mutex_t seat;
int freeSeats;

void barbe(void *args){
    printf("barber is sleeping\n");
    sem_wait(&customer);
    printf("Barber wakes up\n");
    pthread_mutex_lock(&seat);
    freeSeats++;
    sem_post(&barber);
    pthread_mutex_unlock(&seat);
}

void custome(void *args){
    int n = *((int *)args);
    pthread_mutex_lock(&seat);
    if(freeSeats > 0){
        printf("customer %d is waiting for hair cut\n",n);
        freeSeats--;
        sem_post(&customer);
        pthread_mutex_unlock(&seat);
        sem_post(&barber);
        printf("customer %d hair cut\n",n);
    }
    else{
        pthread_mutex_unlock(&seat);
        printf("customer %d leaves\n",n);
    }
}

void main(){
    int nc,ns,i;
    printf("Enter the numnber of customers: ");
    scanf("%d",&nc);
    printf("Enter the numnber of seats: ");
    scanf("%d",&ns);

    pthread_t c[nc],b;
    sem_init(&customer,0,0);
    sem_init(&barber,0,0);
    pthread_mutex_init(&seat,NULL);
    freeSeats = ns;
    int a[nc];
    for(i=0;i<nc;i++)
        a[i] = i+1;
    pthread_create(&b,NULL,(void *)barbe,NULL);
    for(i=0;i<nc;i++)
        pthread_create(&c[i],NULL,(void *)custome, (void *)&a[i]);
        sleep(1);

    for(i=0;i<nc;i++)
        pthread_join(c[i],NULL);
        sleep(1);
    pthread_join(b,NULL);

    sem_destroy(&customer);
    sem_destroy(&barber);
    pthread_mutex_destroy(&seat);

    printf("barber sleeps\n");
}

/*
Algorithm


barber(){
    wait(&customer);
    wait(&seat);
        seats++;
    signal(&barber);
    signal(&seat);
}

customer(){
    wait(&seat);
    if(seats > 0){
            seats--;
        signal(&customer);
        signal(&seat);
        signal(&barber);
    }
    else{
        signal(&seat);
    }
}

*/