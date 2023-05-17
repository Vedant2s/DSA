// Online C compiler to run C program online
#include <stdio.h>

int main() {
    // Write C code here
    //printf("Hello world");
    int arr[10]={100,100,50,50,25,25,20,10,5,5};//make the array in descending order
    int sum=0,count=0;
    int visited[10]={};
    for(int i=0;i<10;i++){
        sum=sum+arr[i];
        visited[i]=1;
        if(sum==320)
        {
            for(int j=0;j<10;j++){
                if(visited[j]==1)
                printf("%d ",arr[j]);
            }
            sum=sum-arr[i];
            visited[i]=0;
            printf("\n");
        }
        if(sum>320){
            sum=sum-arr[i];
            visited[i]=0;
           
        }
        count++;
        if(count<10&&i==9){
            visited[count]=0;
            i=count;
           
        }
    }
    return 0;
}
