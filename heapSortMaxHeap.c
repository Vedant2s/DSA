#include <stdio.h>
int size=0;
void insert (int d);
void swap(int *a,int *b);
void heapify(int i,int size);
    int a[10]={};
    void heap_sort ();
    //maxheap 
int main()
{
   
    insert(3);
    insert(7);
    insert(2);
    insert(5);
    insert(4);
    printf("The max heap is :: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    heap_sort();
    printf("\nThe sorted array is :: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
void insert (int d){
       int i = size;
    a[i] = d;
    size++;
    while (i > 0 && a[(i - 1) / 2] < a[i]) {
        swap(&a[(i - 1) / 2], &a[i]);
        i = (i - 1) / 2;
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
    if(left<size&&a[max]<a[left])
    max=left;
    if(right<size&&a[max]<a[right])
    max=right;
    if(max!=i){
        swap(&a[max],&a[i]);
        heapify(max,size);
    }
}
void heap_sort () 
{
    int i,t;
    for (i=size-1 ; i>=0 ; i--)
    {
        swap(&a[0], &a[i]);
        heapify (0,i);
    }
}
