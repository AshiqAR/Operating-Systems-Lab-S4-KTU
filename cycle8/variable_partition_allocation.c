// Variable Partition Memory Allocation

#include <stdio.h>
#define m 30

typedef struct{
	int max,alloc[m],rem,avail;
} MemoryBlocks;

void printAllocation(MemoryBlocks B[],int n){
	printf("Memory Blocks Free\n");
	for(int i=0;i<n;i++){
		printf("b%d [%d] => ",i+1,B[i].rem);
	}
	printf("\nAllocated\n");
	for(int i=0;i<n;i++){
		printf("b%d : ",i+1);
		for(int j=0;j<B[i].avail;j++){
			printf("%d -> ",B[i].alloc[j]);
		}
		printf("\n");
	}
}

void takeInput(MemoryBlocks B[], int n){
	printf("Enter the block sizes\n");

	for(int i=0;i<n;i++){
		printf("Block b%d : ",i+1);
		scanf("%d",&B[i].max);
		for(int j=0;j<m;j++)
			B[i].alloc[j] = 0; 
		B[i].avail = 0;
		B[i].rem = B[i].max;
	}
}

void firstFit(MemoryBlocks B[],int a,int n){
	for(int i=0;i<n;i++){
		if(B[i].rem >= a ){
			B[i].alloc[(B[i].avail)] = a;
			B[i].avail++;
			B[i].rem -= a;
			printf("\nMemory request allocated in block b%d\n", i+1);
			printAllocation(B,n);
			return;
		}
	}
	printf("\nNo block to fit the memory request\n");
}

void bestFit(MemoryBlocks B[],int a,int n){
	int k=-1,bal,flag = 0,i;
	for( i=0;i<n;i++){
		if(B[i].rem == a){
			B[i].rem = 0;
			B[i].alloc[(B[i].avail)] = a;
			B[i].avail++;
			printf("\nMemory request allocated in block b%d\n", i+1);
			printAllocation(B,n);
			return;
		}
		else if(B[i].rem >= a){
			if(flag == 0){
				k = i;
				bal = B[i].rem-a;
				flag = 1;
			}
			if(B[i].rem - a < bal && B[i].rem >a){
				k = i;
				bal = B[i].rem-a;
			}
		}
	}
	if(k==-1)
		printf("\nNo block to fit the memory request\n");
	else{
		printf("\nMemory request allocated in block b%d\n", k+1);
		B[k].rem -= a;
		B[k].alloc[(B[k].avail)] = a;
		B[k].avail++;
		printAllocation(B,n);
	}
}

void worstFit(MemoryBlocks B[],int a,int n){
	int l = -1,k = -1,i;
	for( i=0;i<n;i++){
		if(l < B[i].rem){
			l = B[i].rem;
			k = i;
		}
	}
	if(B[k].rem < a){
		printf("\nNo block to fit the memory request\n");
		return;
	}
	if(B[k].rem >= a){
		B[k].rem -= a;
		B[k].alloc[(B[k].avail)] = a;
		B[k].avail++;
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
		printf("Enter the memory size: ");
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
