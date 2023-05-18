/*

heap sort

*/

#include <stdio.h>

int n;

void heapify (int a[], int i)
{
    int heap_size = n;
    int l,r,s,t;
    l= (2*i);
    r= (2*i) + 1 ;
    if ( (l<=heap_size) && (a[l]<a[i]) )
    {
        s=l;
    }
    else
    {
        s=l;
    }
    if ( (r<=heap_size) && (a[r]<a[i]) )
    {
        s=r;
    }
    if (s!=i)
    {
        t=a[s];     // exchange a[s],a[i]
        a[s]=a[i];
        a[i]=t;
        heapify(a,s);
    }
}

void build_min_heap(int a[])
{
    int i;
    int heap_size = n;
    for (i=(n/2) ; i>0 ; i--)
    {
        heapify(a,i);
    }
}

void heap_sort (int a[]) //(int a[], int i)
{
    int i,t;
    for (i=n ; i>1 ; i--)
    {
        t=a[1];     // swap a[1],a[i]
        a[1]=a[i];
        a[i]=t;
        heapify (a,1);
    }
}
void main()
{
    int i;
    printf("\nEnter the size of array - "); 
	scanf("%d", &n); 
	int a[n];
	printf("\nEnter elements of the array :\n");
	for (i=0 ; i<n ; i++)
    {
        scanf("%d", &a[i]);  
    }
    build_min_heap(a);
    heap_sort(a);
    printf("\ndiaplaying elements of the sorted array :\n");
	for (i=0 ; i<n ; i++)
    {
        printf("%d ", a[i]);  
    }
}

