#include <stdio.h>

int getSeekTime(int a,int b){
	if(a>b)
		return a-b;
	return b-a;
}

void copy(int arr[],int temp[],int n){
	for(int i=0;i<n;i++)
		temp[i] = arr[i];
}

void swap(int arr[],int i,int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void sort(int arr[],int n){
	for(int i=1;i<n;i++){
		for(int j=0;j<n-i;j++){
			if(arr[j] > arr[j+1])
				swap(arr,j,j+1);
		}
	}
}

int getIndexIncreasing(int arr[],int n,int p){
	for(int i=0;i<n;i++){
		if(arr[i]>=p)
			return i;
	}
	return n-1;
}

int getIndexDecreasing(int arr[],int n,int p){
	for(int i=n-1;i>=0;i--){
		if(arr[i]<=p){
			return i;
		}
	}
	return 0;
}

void cscan(int arr[],int n,int p,int max){
	printf("\nCSCAN\n");
	int d,index,temp[n],i,seekTime = 0;
	copy(arr,temp,n);
	sort(temp,n);
	reread:
	printf("Direction of movement increasing(0) or decreasing (1): ");
	scanf("%d",&d);
	if(d==0){
		index = getIndexIncreasing(temp,n,p);
		printf("%d => ", p);
		seekTime += getSeekTime(p,max);
		for(i=index;i<n;i++){
			printf("%d => ",temp[i]);
			p = temp[i];
		}
		printf("%d => 0 => ",max );
		seekTime += getSeekTime(0,max);
		p=max;
		for(i=0;i<index;i++){
			printf("%d => ",temp[i]);
			p = temp[i];
		}
		printf("\n");
		seekTime += getSeekTime(temp[index-1],0);
	}

	else if(d==1){
		index = getIndexDecreasing(temp,n,p);
		printf("%d => ", p);
		seekTime += getSeekTime(p,0);
		for(i=index;i>=0;i--){
			printf("%d => ",temp[i]);
			p = temp[i];
		}
		printf("0 => %d => ",max);
		seekTime += getSeekTime(0,max);
		p=0;
		for(i=n-1;i>index;i--){
			printf("%d => ",temp[i]);
			p = temp[i];
		}
		printf("\n");
		seekTime += getSeekTime(max,p);
	}


	else{
		printf("Enter a valid option\n");
		goto reread;
	}

	printf("Total seekTime in CSCAN = %d\n",seekTime );
}

void scan(int arr[],int n,int p,int max){
	printf("\nSCAN\n");
	int d,index,temp[n],i,seekTime = 0;
	copy(arr,temp,n);
	sort(temp,n);
	reread:
	printf("Direction of movement increasing(0) or decreasing (1): ");
	scanf("%d",&d);
	if(d==0){
		index = getIndexIncreasing(temp,n,p);
		printf("%d => ", p);
		seekTime += getSeekTime(p,max);
		for(i=index;i<n;i++){
			printf("%d => ",temp[i]);
			p = temp[i];
		}
		printf("%d => ",max );
		p=max;
		for(i=index-1;i>=0;i--){
			printf("%d => ",temp[i]);
			p = temp[i];
		}
		printf("\n");
		seekTime += getSeekTime(temp[0],max);
	}

	else if(d==1){
		index = getIndexDecreasing(temp,n,p);
		printf("%d => ", p);
		seekTime += getSeekTime(p,0);
		for(i=index;i>=0;i--){
			printf("%d => ",temp[i]);
			p = temp[i];
		}
		printf("0 => ");
		p=0;
		for(i=index+1;i<n;i++){
			printf("%d => ",temp[i]);
			p = temp[i];
		}
		printf("\n");
		seekTime += getSeekTime(0,temp[n-1]);
	}


	else{
		printf("Enter a valid option\n");
		goto reread;
	}

	printf("Total seekTime in SCAN = %d\n",seekTime );
}

void fcfs(int arr[],int n,int p){
	printf("\nFCFS\n");
	int seekTime = 0;
	printf("%d => ",p);
	for(int i=0;i<n;i++){
		seekTime += getSeekTime(p,arr[i]);
		printf("%d => ",arr[i]);
		p = arr[i];
	}
	printf("\nTotal seekTime in FCFS = %d\n", seekTime);
}

void main(){
	int n,max,p,choice;
	printf("Enter the number of requests: ");
	scanf("%d",&n);
	printf("Enter the max value: ");
	scanf("%d",&max);
	printf("Enter the current head position: ");
	scanf("%d",&p);
	int arr[n];

	printf("Enter the requests\n");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	do{
		printf("1. FCFS\n");
		printf("2. SCAN\n");
		printf("3. C-SCAN\n");
		printf("4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				fcfs(arr,n,p);
				break;
			case 2:
				scan(arr,n,p,max);
				break;
			case 3:
				cscan(arr,n,p,max);
				break;
			case 4:
				break;
		}
	}while(choice != 4);
}