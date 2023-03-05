#include <stdio.h>

int isRightAlloc(int Need[] , int Work[] , int n);

void main(){
	int n,r,i,j;
	printf("Enter the number of Process: ");
	scanf("%d",&n);
	printf("Enter the number of Resource: ");
	scanf("%d",&r);

	int Alloc[n][r],Request[n][r],Available[r],Work[r];

	printf("\n");

	printf("Enter the Allocation Matrix\n");
	for(i=0;i<n;i++){
		for(j=0;j<r;j++){
			scanf("%d",&Alloc[i][j]);
		}
	}

	int Finish[n];
	printf("Enter the Request Matrix\n");
	for(i=0;i<n;i++){
		Finish[i] = 0;
		for(j=0;j<r;j++){
			scanf("%d",&Request[i][j]);
		}
	}

	printf("Enter the Resource Availablity\n");
	for(i=0;i<r;i++){
		printf("Resource R%d: ",i+1);
		scanf("%d",&Available[i]);
		Work[i] = Available[i];
	}

	int count = n ,cycle=0, k=0,b;
	printf("\n");
	while(count != 0){
		for(i=0;i<n;i++){
			b=i;
			if(Finish[i]==0 && isRightAlloc(Request[i] ,Work,r) == 1){
				Finish[i] = 1;
				count--;
				for(j=0;j<r;j++){
					Work[j] += Alloc[i][j];
					Alloc[i][j] = 0;
					Request[i][j] = 0;
				}
				cycle = 0;
			}
			cycle++;
			i=b;
		}
		if(cycle >= 2*n){
			break;
		}
	}
	if(count==0)
		printf("No Deadlock detected\n\n");
	else
		printf("DeadLock detected\n\n");
	
}


int isRightAlloc(int Need[] , int Work[] , int n){
	for(int i=0;i<n;i++){
		if(Need[i]>Work[i])
			return -1;
	}
	return 1;
}
