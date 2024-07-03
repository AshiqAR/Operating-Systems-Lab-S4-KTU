#include <stdio.h>

typedef struct{
	int pid,at,bt,wt,tt;
}Process;

void TakeInput(Process p[],int n){
	for(int i=0;i<n;i++){
		printf("Arrival Time, Burst time of P%d : ",i);
		scanf("%d %d",&p[i].at,&p[i].bt);
		p[i].pid = i;
	}
}

void swap(Process p[],int i , int j){
	Process temp;
	temp = p[i];
	p[i] = p[j];
	p[j] = temp;
}

void sort(Process p[],int n){
	for(int i=1;i<n;i++){
		for(int j=0;j<n-i;j++){
			if(p[j].at > p[j+1].at){
				swap(p,j,j+1);
			}
		}
	}
}

void sortPid(Process p[],int n){
	for(int i=1;i<n;i++){
		for(int j=0;j<n-i;j++){
			if(p[j].pid > p[j+1].pid){
				swap(p,j,j+1);
			}
		}
	}
}

void display(Process p[],int n){
	printf("\nFCFS\n\n");
	printf("Process  AT  BT  WT  TT\n");
	float w=0,t=0;
	for(int i=0;i<n;i++){
		printf("P%d      %3d %3d %3d %3d\n",p[i].pid,p[i].at,p[i].bt,p[i].wt,p[i].tt);
		t +=p[i].tt;
		w +=p[i].wt;
	}
	w = w/n; t=t/n;
	printf("Average waiting time = %f\n", w);
	printf("Average turn around time = %f\n", t);
}

void main(){
	int n;
	printf("Enter the number of process: ");
	scanf("%d",&n);
	Process p[n];
	TakeInput(p,n);
	sort(p,n);
	int t=0;
	for(int i=0;i<n;i++){
		if(p[i].at > t){
			printf("%d| ** |",t);
			t = p[i].at;
		}

		printf("%d| P%d |",t,p[i].pid);
		t = t + p[i].bt;
		p[i].tt = t-p[i].at;
		p[i].wt = p[i].tt - p[i].bt;
	}
	printf("%d\n",t);
	sortPid(p,n);
	display(p,n);
}
