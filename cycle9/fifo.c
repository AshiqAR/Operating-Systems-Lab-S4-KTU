#include <stdio.h>

int pageIsFound(int f[],int count,int a){
    for(int i=0;i<count;i++){
        if(f[i]==a)
            return 1;
    }
    return 0;
}

void fifo(int arr[],int n, int f[],int fno){
    int fifoArr[fno][n];
    int front=0,count=0,p=0,j,k,i;
    for(i=0;i<n;i++){
        if(pageIsFound(f,count,arr[i])){}
        else{
            p++;
            f[front] = arr[i];
            front = (front+1)%fno;
            if(count != fno)
                count++;
        }
        for(j=0,k=0;j<fno;j++){
            if(k<count)
                fifoArr[k++][i] = f[j];
            else 
                fifoArr[k++][i] = -1;
        }

    }
    for(i=0;i<fno;i++){
        for(j=0;j<n;j++){
            if(fifoArr[i][j] != -1)
                printf("%d  ",fifoArr[i][j]);
            else 
                printf("   ");
        }
        printf("\n");
    }
    printf("Page Faults(in FIFO) = %d\n",p);
}

void main(){
    printf("FIFO Page Replacement Algorithm\n");
    int n,i,frameNum;
    printf("Enter the number of frames: ");
    scanf("%d",&frameNum);
    printf("Enter the number of page requests: ");
    scanf("%d",&n);
    printf("Enter the page string each seperated by a space\n");
    int arr[n],F[frameNum];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("\nPages\n");
    for(i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
    printf("\nPage Frames\n");
    fifo(arr,n ,F,frameNum);
}