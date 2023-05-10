#include <stdio.h>

int main()
{
    // printf("Hello World\n");
    // int arr[7]={1,3,6,2,5,1,7};
    // //printf("%d",arr[0]);
    // int max=0,profit=0;
    // for(int i=0;i<7;i++){
    //     for(int j=i;j<7;j++){
    //         if(arr[j]-arr[i]>=max)
    //         max=arr[j]-arr[i];
    //     }
    // }
    // printf("%d",max);
    int ar[10]={-7,-1,-6,3,7,1,5,-1,-10,9};
    int visited[10]={},u=0,count=0;
    for(int i=0;i<10;i++){
        for(int j=i+1;j<10;j++){
            for(int k=j+1;k<10;k++){
                if(ar[i]+ar[j]+ar[k]==0)
                {
                    if(u==0){visited[u]=ar[i];
                    u++;
                    visited[u]=ar[j];
                    u++;
                    visited[u]=ar[k];
                    u++;}
                    if(u!=0){
                        for(int p=0;p<u;p++)
                        if(ar[i]==visited[p])
                        count++;
                        for(int p=0;p<u;p++)
                        if(ar[j]==visited[p])
                        count++;
                        for(int p=0;p<u;p++)
                        if(ar[k]==visited[p])
                        count++;
                    }
                    if(count!=3)
                    printf("%d,%d,%d\n",ar[i],ar[j],ar[k]);
                    count=0;
                }
            }
        }
    }
    return 0;
}
