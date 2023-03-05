#include <stdio.h>

int isRightAlloc(int Need[] , int RemainRes[] , int n){
	for(int i=0;i<n;i++){
		if(Need[i]>RemainRes[i])
			return -1;
	}
	return 1;
}

void main(){
	int n,r,i,j;
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	printf("Enter the number of resources: ");
	scanf("%d",&r);

	int Alloc[n][r],Max[n][r];
	int TotalRes[r];

	for(i=0;i<r;i++){
		printf("Enter the total instances of R%d : ",i+1);
		scanf("%d",&TotalRes[i]);
	}

	printf("Enter the Allocation Matrix\n");
	for(i=0;i<n;i++){
		for(j=0;j<r;j++){
			scanf("%d",&Alloc[i][j]);
		}
	}

	int Flag[n];
	printf("Enter the Max Matrix\n");
	for(i=0;i<n;i++){
		Flag[i] = 0;
		for(j=0;j<r;j++){
			scanf("%d",&Max[i][j]);
		}
	}

	int Need[n][r];
	for(i=0;i<n;i++){
		for(j=0;j<r;j++){
			Need[i][j] = Max[i][j]-Alloc[i][j];
		}
	}

	int TotalUsed[r];

	for(j=0;j<r;j++){
		TotalUsed[j] = 0;
		for(i=0;i<n;i++){
			TotalUsed[j] += Alloc[i][j];
		}
	}

	int RemainResource[r];
	for(i=0;i<r;i++){
		RemainResource[i] = TotalRes[i]-TotalUsed[i];
	}

	int count = n ,cycle=0, k;
	int Seq[n];



	while(count != 0){
		for(i=0;i<n;i++){
			if(Flag[i]==0 && isRightAlloc(Need[i] ,RemainResource,r) == 1){
				Flag[i] = 1;
				count--;
				Seq[k++] = i;
				for(j=0;j<r;j++){
					RemainResource[j] += Need[i][j];
				}
				cycle = 0;
			}
			cycle++;
		}
		if(cycle >= 3*n){
			break;
		}
	}


	if(count == 0){
		printf("\nSafe Allocation\nAllocation Sequence:    ");
		for(i=0;i<n-1;i++){
			printf("P%d -> ",Seq[i]);
		}
		printf("P%d\n",Seq[i]);
	}
	else{
		printf("Unsafe Allocation\n");
	}

}