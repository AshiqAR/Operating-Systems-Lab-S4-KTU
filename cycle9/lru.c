#include <stdio.h>

int pageIsFound(int f[],int count,int a){
    for(int i=0;i<count;i++){
        if(f[i]==a)
            return 1;
    }
    return 0;
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
    for(i=0;i<fno;i++){
        for(j=0;j<n;j++){
            if(lruArr[i][j] != -1)
                printf("%d  ",lruArr[i][j]);
            else 
                printf("   ");
        }
        printf("\n");
    }
    printf("Page Faults(in LRU) = %d\n",p);
}

void main(){
    printf("LRU Page Replacement Algorithm\n");
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
    lru(arr,n ,F,frameNum);
}