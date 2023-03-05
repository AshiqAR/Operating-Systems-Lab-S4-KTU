#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void main(){
	pid_t p = fork();
	printf("pid = %d\n",p);

	if(p==0){
		printf("It is the child process, pid = %d\n",getpid() );
		for(int i=0;i<5;i++)
			printf("%d\n",i);

		exit(0);

	}else if(p>0){
		printf("it is the parent process, pid = %d\n",getpid());
		int status;
		wait(&status);
	}
	else{
		printf("Error in forking\n");
		exit(EXIT_FAILURE);
	}
}
