#include <stdio.h>

typedef struct{
	int at,bt,wt,tt,pid,flag,pr;
}Process;

void swap(Process p[],int i,int j){
	Process temp;
	temp = p[i];
	p[i] = p[j];
	p[j] = temp;
}

void sortid(Process p[],int n){
	for(int i=1;i<n;i++){
		for(int j=0;j<n-i;j++){
			if(p[j].pid > p[j+1].pid)
				swap(p,j,j+1);
		}
	}
}

void main(){
	int time = 0;
	printf("Priority Scheduling\n");
	printf("Enter the number of process: ");
	int n,i,j;
	scanf("%d",&n);
	Process p[n];
	
	for(i=0;i<n;i++){
		printf("Enter arrival time, burst time ,priority of P%d : ",i+1);
		scanf("%d %d %d",&p[i].at,&p[i].bt,&p[i].pr);
		p[i].pid = i+1;
		p[i].flag = 0;
	}
	
	for(i=1;i<n;i++){
		for(j=0;j<n-i;j++){
			if(p[j].at>p[j+1].at){
				swap(p,j,j+1);
			}
			else if(p[j].at==p[j+1].at && p[j].pr > p[j+1].pr){
				swap(p,j,j+1);
			}
		}
	}

	int a = n;
	printf("\nGANTT CHART\n");
	while(a!=0){
		int b = 1;
		int pid = 0;
		int pri = 10000;
		int f=1;
		for(i=0;i<n;i++){
			if(p[i].flag ==0){
				f=0;
			}
			if(time >= p[i].at && p[i].pr<pri && p[i].flag ==0){
				pid = i;
				pri = p[i].pr;
				b=0;
			}
		}
		if(f==1)
			break;

		if (b==0){
			i=pid;
			p[i].wt = time-p[i].at;
			printf("|%d P%d(%d)  %d|",time,p[i].pid,p[i].pr,p[i].bt+time);
			p[i].tt = p[i].wt + p[i].bt;
			time += p[i].bt;
			p[i].flag = 1;
			a--;
		}else {
			printf("%d| * ",time );
			time++;
		}
	}

	printf("\n");
	sortid(p,n);
	float wtavg = 0, ttavg = 0;
	printf("Pno  Arrival_time  Burst_time  Waiting_time  Turnaround_time  Priority\n");
	for(i=0;i<n;i++){
		printf("%3d  %11d  %9d  %12d  %14d  %8d\n",p[i].pid,p[i].at,p[i].bt,p[i].wt,p[i].tt,p[i].pr);
		wtavg += p[i].wt;
		ttavg += p[i].tt;
	}

	printf("Average waiting time = %f \n",wtavg/n);
	printf("Average turnaround time = %f \n",ttavg/n);
}
