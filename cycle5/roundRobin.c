#include<stdio.h>

typedef struct{
	int at,bt,wt,tt,pid,flag,new_bt;
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

void sort(Process p[],int n){
	for(int i=1;i<n;i++){
		for(int j=0;j<n-i;j++){
			if(p[j].at>p[j+1].at){
				swap(p,j,j+1);
			}
		}
	}
}

void main(){
	int time=0;
	printf("Round Robin Scheduling\n");
	printf("Enter the number of process: ");
	int n,i,j,q;
	scanf("%d",&n);
	Process p[n];
	
	for(i=0;i<n;i++){
		printf("Enter arrival time, burst time of P%d : ",i+1);
		scanf("%d %d",&p[i].at,&p[i].bt);
        p[i].new_bt = p[i].bt;
		p[i].pid = i+1;
		p[i].flag = 0;
        p[i].wt = 0;
        p[i].tt = 0;
	}

    printf("Enter the time Quantum : ");
    scanf("%d",&q);
    sort(p,n);

    int a = n;
    printf("\nGANTT CHART\n");
    while(a!=0){
        int b=0;
        for(i=0;i<n;i++){
            if(p[i].flag==0)
                b=1;
        }
        if(b==0)
            break;
        
        int id;
        int min_at = 10000;

        for(i=0;i<n;i++){
            if(p[i].at < min_at && p[i].flag==0){
                id = i;
                min_at = p[i].at;
            }
        }

        i = id;
        b = time;
        p[i].wt += time-p[i].at;
        if(p[i].new_bt <= q){
            time += p[i].new_bt;
            p[i].new_bt = 0;
            p[i].flag = 1;
            a--;
        }else{
            time += q;
            p[i].at = time;
            p[i].new_bt -= q;
        }
        printf("|%d  P%d  %d|",b,p[i].pid,time);
    }

    printf("\n");
    sortid(p,n);
    float wtavg = 0, ttavg = 0;
    printf("Pno  Arrival_time  Burst_time  Waiting_time  Turnaround_time\n");
    for(i=0;i<n;i++){
        p[i].tt = p[i].wt + p[i].bt;
        printf("%3d  %11d  %9d  %12d  %14d\n",p[i].pid,p[i].at,p[i].bt,p[i].wt,p[i].tt);
        wtavg += p[i].wt;
		ttavg += p[i].tt;
    }

    printf("Average waiting time = %f \n",wtavg/n);
	printf("Average turnaround time = %f \n",ttavg/n);
}
