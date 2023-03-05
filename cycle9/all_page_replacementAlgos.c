#include <stdio.h>

int pageIsFound(int f[],int count,int a){
    for(int i=0;i<count;i++){
        if(f[i]==a)
            return 1;
    }
    return 0;
}
void fifo(int arr[],int n, int f[],int fno){
    printf("\nFIFO Page Replacement\n");
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
    printf("Pages\n");
    for(i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
    printf("\nPage Frames\n");
    for(i=0;i<fno;i++){
        for(j=0;j<n;j++){
            if(fifoArr[i][j] != -1)
                printf("%d  ",fifoArr[i][j]);
            else 
                printf("   ");
        }
        printf("\n");
    }
    printf("Page Faults(in FIFO) = %d\n\n",p);
}

int recentAccessLRU(int arr[],int i,int a){
    int count=0;
    for(int j=i;j>=0;j--){
        count++;
        if(arr[j]==a)
            return count;
    }
}
void lru(int arr[],int n, int f[],int fno){
    int index,count=0,p=0,i,j,k,x,lruArr[fno][n];
    for( i=0;i<n;i++){
        if(pageIsFound(f,count,arr[i])){}
        else{
            p++;
            if(count == fno){
                int max = -1;
                for(j=0;j<fno;j++){
                    x = recentAccessLRU(arr,i,f[j]);
                    if(x > max){
                        index = j;
                        max = x;
                    }
                }
                f[index] = arr[i];
            }
            else{
                f[count++]=arr[i];
            }
        }
        for(j=0,k=0;j<fno;j++){
            if(k<count)
                lruArr[k++][i] = f[j];
            else 
                lruArr[k++][i] = -1;
        }
    }
    printf("Pages\n");
    for(i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
    printf("\nPage Frames\n");
    for(i=0;i<fno;i++){
        for(j=0;j<n;j++){
            if(lruArr[i][j] != -1)
                printf("%d  ",lruArr[i][j]);
            else 
                printf("   ");
        }
        printf("\n");
    }
    printf("Page Faults(in LRU) = %d\n\n",p);
}

int totalAccessed(int arr[],int i,int a){
    int count = 0;
    for(int j=i;j>=0;j--){
        if(arr[j]==a)
            count++;
    }
    return count;
}
int recentAccess(int arr[],int i,int a){
    int count=0;
    for(int j=i;j>=0;j--){
        count++;
        if(arr[j]==a)
            return count;
    }
}
void lfu(int arr[],int n, int f[],int fno){
    int index=-1,count=0,p=0,i,j,x,k,lfuArr[fno][n];
    int m1,m2;
    int temp[fno][2];
    for( i=0;i<n;i++){
        if(pageIsFound(f,count,arr[i])){}
        else{
            p++;
            if(count == fno){
                int min = n;
                for(k=0;k<fno;k++){
                    temp[k][1]=totalAccessed(arr,i,f[k]);
                    temp[k][2]=recentAccess(arr,i,f[k]);
                    if(min>temp[k][1]){
                        min = temp[k][1];
                        index = k;
                    }
                    else if(min == temp[k][1]){
                        if(temp[k][2] > temp[index][2])
                            index = k;
                    }
                }
                f[index] = arr[i];
            }
            else{
                f[count++]=arr[i];
            }
        }
        for(j=0,k=0;j<fno;j++){
            if(k<count)
                lfuArr[k++][i] = f[j];
            else 
                lfuArr[k++][i] = -1;
        }
    }
    printf("Pages\n");
    for(i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
    printf("\nPage Frames\n");
    for(i=0;i<fno;i++){
        for(j=0;j<n;j++){
            if(lfuArr[i][j] != -1)
                printf("%d  ",lfuArr[i][j]);
            else 
                printf("   ");
        }
        printf("\n");
    }
    printf("Page Faults(in LFU) = %d\n\n",p);
}

void main(){
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

    int choice;

    do{
        printf("Page Replacement Algorithms\n");
        printf("1. FIFO\n");
        printf("2. LRU\n");
        printf("3. LFU\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1: 

                fifo(arr,n ,F,frameNum);
                break;
            case 2:
                lru(arr,n ,F,frameNum);
                break;
            case 3: 
                lfu(arr,n ,F,frameNum);
                break;
            case 4:
                break;
        }
    }while(choice != 4);
}