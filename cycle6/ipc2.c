#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

void main(){
	
	key_t key = ftok("shm",65);
	int shmid = shmget(key ,1024, 0666|);
	char *str = (char *)shmat(shmid , (void *)0, 0);
	printf("Data read from memory: %s\n",str );
	shmdt(str);
	shmctl(shmid, IPC_RMID, NULL);

}