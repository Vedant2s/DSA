#include <stdio.h>
int size=0;
void insert (int d);
void swap(int *a,int *b);
void heapify(int i,int size);
    int a[10]={};
    //maxheap 
int main()
{
   
    insert(3);
    insert(7);
    insert(2);
    insert(5);
    insert(4);
    for(int i=0;i<10;i++)
     printf("%d ",a[i]);
    return 0;
}
void insert (int d){
    if(size==0){
        a[size++]=d;
    }
    else{
    a[size++]=d;
    for(int i=size/2-1;i>=0;i--){
        heapify(i,size);
    }
    }
    
}
void swap(int *a1,int *b){
    int c=*a1;
    *a1=*b;
    *b=c;
}
void heapify(int i,int size){
    int max=i;
    int left,right;
    left=2*i+1;
    right=2*i+2;
    if(left<=size&&a[max]<a[left])
    max=left;
    if(right<=size&&a[max]<a[right])
    max=right;
    if(max!=i){
        swap(&a[max],&a[i]);
        heapify(max,size);
    }
}
