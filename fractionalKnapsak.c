#include <stdio.h>
# define n 5
int capacity=15;
float baseprofit(float p[],float w[],float x[]);
float weigthprofit(float p[],float w[],float x[]);
float ratioprofit(float p[],float w[],float x[]);
int main()
{
    float p[5]={10,15,2,30,6},w[5]={4,5,2,3,5},x[5]={};
    float tp=baseprofit(p,w,x);
    printf("Base Profit,%f\n",tp); 
    float tp1=weigthprofit(p,w,x);
    printf("Weigth Profit,%f\n",tp1); 
    float tp2=ratioprofit(p,w,x);
    printf("Ratio Profit,%f",tp2); 
    return 0;
}
float baseprofit(float p[],float w[],float x[]){
    float temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(p[j]<p[j+1]){
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
                temp=w[j];
                w[j]=w[j+1];
                w[j+1]=temp;
            }
        }
    }
    float tp=0,W=0;
    int i=0;
    while(i<n){
        if(W+w[i]<=capacity){
            x[i]=1;
            W=W+w[i];
            i++;
        }
        else{
            x[i]=(capacity-W)/w[i];
            break;
        }
    }
    for(i=0;i<n;i++){
        tp=tp+p[i]*x[i];
    }
    return tp;
}
float weigthprofit(float p[],float w[],float x[]){
    float temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(w[j]>w[j+1]){
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
                temp=w[j];
                w[j]=w[j+1];
                w[j+1]=temp;
            }
        }
    }
    float tp=0,W=0;
    int i=0;
    while(i<n){
        if(W+w[i]<=capacity){
            x[i]=1;
            W=W+w[i];
            i++;
        }
        else{
            x[i]=(capacity-W)/w[i];
            break;
        }
    }
    for(i=0;i<n;i++){
        tp=tp+p[i]*x[i];
    }
    return tp;
}
float ratioprofit(float p[],float w[],float x[]){
    float temp;
    float ratio[n]={};
    for(int i=0;i<n;i++){
        ratio[i]=(p[i]/w[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(ratio[j]<=ratio[j+1]){
                temp=ratio[j];
                ratio[j]=ratio[j+1];
                ratio[j+1]=temp;
                
                temp=w[j];
                w[j]=w[j+1];
                w[j+1]=temp;
                
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    for(int k=0;k<n;k++){
    //printf("%f\t",ratio[k]);
    }
    //for(int k=0;k<n;k++)
   // printf("/%f\t",w[k]);
    float tp=0,W=0;
    int i=0;
    while(i<n){
        if(W+w[i]<=capacity){
            x[i]=1;
            W=W+w[i];
            i++;
        }
        else{
            x[i]=(capacity-W)/w[i];
            break;
        }
    }
    for(i=0;i<n;i++){
        tp=tp+p[i]*x[i];
    }
    return tp;
}
