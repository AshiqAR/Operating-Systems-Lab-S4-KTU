// Fixed Block Memory Allocation

#include <stdio.h>
#define m 30

typedef struct{
	int size,rem,flag;
} MemoryBlocks;

void printAllocation(MemoryBlocks B[],int n){
	printf("Block   MaxSize   Allocated\n");
	for(int i=0;i<n;i++){
		printf("b%d      %7d",i+1,B[i].size);
		if(B[i].flag == 1)
			printf("   %d",B[i].size-B[i].rem);
		else
			printf("   -");
		printf("\n");
	}
}

void takeInput(MemoryBlocks B[], int n){
	printf("Enter the block sizes\n");

	for(int i=0;i<n;i++){
		printf("Block b%d : ",i+1);
		scanf("%d",&B[i].size);
		B[i].flag = 0;
		B[i].rem = B[i].size;
	}
}

void firstFit(MemoryBlocks B[],int a,int n){
	for(int i=0;i<n;i++){
		if(B[i].size >= a && B[i].flag==0){
			B[i].flag = 1;
			B[i].rem -= a;
			printf("\nMemory request allocated in block b%d\n", i+1);
			printAllocation(B,n);
			return;
		}
	}
	printf("\nNo block to fit the memory request\n");
}

void bestFit(MemoryBlocks B[],int a,int n){
	int min,k=-1;
	for(int i=0;i<n;i++){
		if(B[i].size >= a && B[i].flag == 0){
			if(k==-1){
				min = B[i].size;
				k=i;
			}
			else{
				if(min > B[i].size){
					k=i;
					min = B[i].size;
				}
			}
		}
	}
	if(k==-1)
		printf("\nNo block to fit the memory request\n");
	else{
		printf("\nMemory request allocated in block b%d\n", k+1);
		B[k].rem -= a;
		B[k].flag = 1;
		printAllocation(B,n);
	}
}

void worstFit(MemoryBlocks B[],int a,int n){
	int l = -1,k = -1,i;
	for( i=0;i<n;i++){
		if(l < B[i].size && B[i].flag==0){
			l = B[i].size;
			k=i;
		}
	}
	if(B[k].rem < a){
		printf("\nNo block to fit the memory request\n");
		return;
	}
	else{
		B[k].rem -= a;
		B[k].flag = 1;
		printf("\nMemory request allocated in block b%d\n", k+1);
		printAllocation(B,n);
	}
}

void main(){
	int n,i,a,choice;
	char ch;
	printf("Enter the number of Memory Blocks : ");
	scanf("%d",&n);
	MemoryBlocks B[n];

	takeInput(B, n);

	do{
		printf("Enter the requesting memory size: ");
		scanf("%d",&a);
		printf("Alocation Strategies\n");
		printf("1. First Fit\n");
		printf("2. Best Fit\n");
		printf("3. Worst Fit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice){
			case 1:
				firstFit(B,a,n);
				break;
			case 2: 
				bestFit(B,a,n);
				break;
			case 3: 
				worstFit(B,a,n);
				break;
			default: 
				printf("Enter valid choice!\n");
				break;
		}
		printf("Do you want to continue(y/n) : ");
		scanf(" %c",&ch);
	}
	while(ch != 'n');
}
