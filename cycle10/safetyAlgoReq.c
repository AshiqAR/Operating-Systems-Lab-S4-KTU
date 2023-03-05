// Deadlock Avoidance with resource Request 

#include <stdio.h>

int isRightAlloc(int Need[] , int RemainRes[] , int n);

void main(){
	printf("Banker's Resource Request Algorithm\n\n");
	int n,r,i,j;
	printf("Enter the number of Process: ");
	scanf("%d",&n);
	printf("Enter the number of Resource: ");
	scanf("%d",&r);

	int Alloc[n][r],Max[n][r];
	int TotalRes[r];

	printf("\n");
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

	char ch;
	printf("Is any process requesting for resources? (y/n) : ");
	scanf(" %c",&ch);

	int pno;
	int Req[r],Seq[n];;
	if(ch=='y' || ch=='Y'){
		readAgain:
		printf("Enter the ProcessNo. requesting for resource (0-%d): ",n-1);
		scanf("%d",&pno);
		if(pno > n-1){
			printf("Invalid ProcessNo!!\n");
			goto readAgain;
		}

		printf("Enter the resource request: \n");
		
		for(i=0;i<r;i++){
			scanf("%d",&Req[i]);
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

	if(ch=='y' || ch=='Y'){
		if(isRightAlloc(Req,RemainResource,r)==1){
			for(i=0;i<r;i++){
				RemainResource[i] -= Req[i];
				Need[pno][i] -= Req[i];
				Alloc[pno][i] += Req[i];
			}
		}
		else{
			printf("Request cannot be Servised\n");
			printf("Requested Resource not Available\n");
			goto eexit;
		}
	}

	printf("Need Matrix\n");
	for(i=0;i<n;i++){
		for(j=0;j<r;j++){
			printf("%d ",Need[i][j]);
		}
		printf("\n");
	}

	int count = n ,cycle=0, k=0,b;
	printf("\n");
	while(count != 0){
		for(i=0;i<n;i++){
			b=i;
			if(Flag[i]==0 && isRightAlloc(Need[i] ,RemainResource,r) == 1){
				Flag[i] = 1;
				count--;
				Seq[k++] = i;
				for(j=0;j<r;j++){
					RemainResource[j] += Alloc[i][j];
					Alloc[i][j] = 0;
					Need[i][j] = 0;
				}
				printf("Process P%d runs to completion\n",i);
				printf("Allocation Matrix\n");
				for(i=0;i<n;i++){
					for(j=0;j<r;j++){
						printf("%d ",Alloc[i][j]);
					}
					printf("\n");
				}
				printf("Need Matrix\n");
				for(i=0;i<n;i++){
					for(j=0;j<r;j++){
						printf("%d ",Need[i][j]);
					}
					printf("\n");
				}
				printf("Available Resources\n");
				for(j=0;j<r;j++){
					printf("%d ",RemainResource[j] );
				}
				printf("\n\n");
				cycle = 0;
			}
			cycle++;
			i=b;
		}
		if(cycle >= 2*n){
			break;
		}
	}

	eexit:
	if(count == 0){
		printf("Safe Allocation\nAllocation Sequence: ");
		for(i=0;i<n-1;i++){
			printf("P%d -> ",Seq[i]);
		}
		printf("P%d\n",Seq[i]);
	}
	else{
		printf("Unsafe Allocation\n");
	}

}

int isRightAlloc(int Need[] , int RemainRes[] , int n){
	for(int i=0;i<n;i++){
		if(Need[i]>RemainRes[i])
			return -1;
	}
	return 1;
}
