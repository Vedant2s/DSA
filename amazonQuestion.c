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
    int visited[10][3]={},u=0,count=0;
    for(int i=0;i<10;i++){
        for(int j=i+1;j<10;j++){
            for(int k=j+1;k<10;k++){
                if(ar[i]+ar[j]+ar[k]==0)
                {
                    if(u!=0){for(int y=0;y<u;y++){
                        for(int p=0;p<u;p++)
                        if(ar[i]==visited[y][p])
                        count++;
                        for(int p=0;p<u;p++)
                        if(ar[j]==visited[y][p])
                        count++;
                        for(int p=0;p<u;p++)
                        if(ar[k]==visited[y][p])
                        count++;
                        if(count<3)
                        count=0;
                    }
                    }
                    if(1){visited[u][0]=ar[i];
                    visited[u][1]=ar[j];
                    visited[u][2]=ar[k];
                    u++;}
                    if(count!=3)
                    printf("%d,%d,%d\n",ar[i],ar[j],ar[k]);
                    printf("count %d\n",count);
                    count=0;
                }
            }
        }
    }
    printf("%d",count);
    return 0;
}
