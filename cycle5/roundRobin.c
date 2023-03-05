#include <stdio.h>

typedef struct{
	int pid,at,bt,wt,tt,flag,nat,nbt;
}Process;

void TakeInput(Process p[],int n){
	for(int i=0;i<n;i++){
		printf("Arrival Time, Burst time of P%d : ",i);
		scanf("%d %d",&p[i].at,&p[i].bt);
		p[i].pid = i;
		p[i].flag = 0;
		p[i].nbt = p[i].bt;
		p[i].nat = p[i].at;
	}
}

void swap(Process p[],int i , int j){
	Process temp;
	temp = p[i];
	p[i] = p[j];
	p[j] = temp;
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

void sort(Process p[],int n){
	for(int i=1;i<n;i++){
		for(int j=0;j<n-i;j++){
			if(p[j].nat > p[j+1].nat){
				swap(p,j,j+1);
			}
		}
	}
}

void display(Process p[],int n){
	printf("\nRound Robin\n\n");
	printf("Process  AT  BT  WT  TT\n");
	float w=0,t=0;
	for(int i=0;i<n;i++){
		printf("P%d      %3d %3d %3d %3d\n",p[i].pid,p[i].at,p[i].bt,p[i].wt,p[i].tt);
		t +=p[i].tt;
		w +=p[i].wt;
	}
	w = w/n; t=t/n;
	printf("Average waiting time = %f\n", w);
	printf("Average waiting time = %f\n", t);
}

int pRemain(Process p[],int n){
	for(int i=0;i<n;i++){
		if(p[i].flag == 0)
			return 1;
	}
	return 0;
}

int minNextAt(Process p[],int n, int t){
	int min = 999;
	for(int i=0;i<n;i++){
		if((p[i].flag==0) && (p[i].nat > t) && (p[i].nat < min)){
			min = p[i].nat;
		}
	}
	return min;
}

void RoundRobin(Process p[],int n,int q){
	int t=0,test;
	while(pRemain(p,n)){
		test = 0;
		for(int i=0;i<n;i++){
			if((p[i].nat <= t) && (p[i].flag==0)){
				test = 1;
				printf("%d| P%d |",t,p[i].pid);
				if(p[i].nbt <= q){
					t += p[i].nbt;
					p[i].flag = 1;
					p[i].tt = t - p[i].at;
					p[i].wt = p[i].tt - p[i].bt;
					p[i].nbt = 0;
				}
				else{
					t += q;
					p[i].nbt -= q;
				}
				p[i].nat = t;
				break;
			}
		}
		if(test==0){
			printf("%d|",t);
			t = minNextAt(p,n,t);
			printf(" * |");
		}
		sort(p,n);
	}
	printf("%d",t );
}

void main(){
	int n,q;
	printf("Enter the number of process: ");
	scanf("%d",&n);
	printf("Enter the time quantum: ");
	scanf("%d",&q);
	Process p[n];
	TakeInput(p,n);
	sort(p,n);
	RoundRobin(p,n,q);
	sortPid(p,n);
	display(p,n);
}
