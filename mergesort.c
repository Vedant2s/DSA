#include <stdio.h>
void merge_s(int a[],int b,int e);
void merge(int a[],int b,int mid,int e);
int main()
{
    int n,b=0;
    printf("enter size of array\t");
    scanf("%d",&n);
printf("enter array\n");
int a[n];
for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
}
merge_s(a,b,n-1);
printf("sorted array\n");
for(int i=0;i<n;i++){
    printf("%d",a[i]);
}
    return 0;
}
void merge_s(int a[],int b,int e){
    int mid;
    if(b<e){
        mid=(b+e)/2;
        merge_s(a,b,mid);
        merge_s(a,mid+1,e);
        merge(a,b,mid,e);
    }
    
}
void merge(int a[],int b,int mid,int e){
    int i,j,k;
    int n1=mid-b+1;
    int n2=e-mid;
    int left[n1],right[n2];
    for( i=0;i<n1;i++){
        left[i]=a[b+i];
    }
    for( j=0;j<n2;j++)
    {
        right[j]=a[mid+1+j];
    }
    i=0;
    j=0;
    k=b;
    while(i<n1&&j<n2){
        if(left[i]>right[j]){
            a[k]=right[j];
            k++;
            j++;
        }
        else{
            a[k]=left[i];
            k++;
            i++;
        }
    }
    while(i<n1){
        a[k]=left[i];
        k++;
        i++;
    }
    while(j<n2){
        a[k]=right[j];
        j++;
        k++;
    }
    
}
