#include <stdio.h>

int acessInOptimal(int arr[],int n,int i,int a);
void optimal(int arr[],int n, int f[],int fno);


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
    optimal(arr,n ,F,frameNum);
}



void printPageTable(int f[],int size){
    printf("Page Frames: ");
    for(int i=0;i<size;i++)
        printf("%d ",f[i]);
    printf("\n");
}

int pageIsFound(int f[],int count,int a){
    for(int i=0;i<count;i++){
        if(f[i]==a)
            return 1;
    }
    return 0;
}

int acessInOptimal(int arr[],int n,int i,int a){
    int count = 0;
    for(int j=i+1;j<n;j++){
        count++;
        if(arr[j]==a)
            return count;
    }
    return count+1;
}

void optimal(int arr[],int n, int f[],int fno){
    printf("\nOptimal Page Replacement Algorithm\n");
    int i,j,count=0,p=0,x,index;
    for(i=0;i<n;i++){
        printf("Page:%d => ",arr[i]);
        if(pageIsFound(f,count,arr[i])){
            printf("No Page Fault\n");
        }
        else{
            printf("Page Fault    => ");
            p++;
            if(count == fno){
                int max = -1;
                for(j=0;j<fno;j++){
                    x = acessInOptimal(arr,n,i,f[j]);
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
            printPageTable(f,count);
        }
    }
    printf("Number of page faults in Optimal Algorithm = %d\n",p);
}
