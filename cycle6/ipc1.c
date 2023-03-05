#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

void main(){

	key_t key = ftok("shm",65);
	int shmid = shmget(key,1024,0666|IPC_CREAT);
	char *str = (char *)shmat(shmid,(void*)0,0);
	printf("Write data: ");
	fgets(str,50,stdin);
	printf("Data written in memory: %s\n",str);
	shmdt(str);
	
}
