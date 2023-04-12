
#include <stdio.h>

# define n 3
# define op 1

int a[n][n], visited[n], queue[10], f=-1, r=-1, stack[10], top=-1;

int pop()
{
    int e = stack[top];
    top--;
    return e;
}

void DFS(int v)
{
    visited[v]=1;
    stack[++top]=v;
    printf("%d", v);
    for (int i=0 ; i<n ; i++)
    {
        if ((a[v][i]==1) && (!visited[i]))
        {
            DFS(i);
        }
    }
    int i,e,f;
    while (top!=-1)
    {
        f=0;
        e=stack[top];
        for (int i=0 ; i<n ; i++)
        {
            if ((a[e][i]) && (!visited[i]))
            {
                DFS(i);
                f=1;
            }
        }
        if (f==0)
        {
            pop();
        }
    }
}

void BFS(int v)
{
    visited[v]=1;
    printf("%d", v);
    for (int i=0 ; i<n ; i++)
    {
        if ((a[v][i]==1) && (!visited[i]))
        {
            queue[++r]=i;
            visited[i]=1;
        }
    }
    if (f<r)
    {
        BFS(queue[++f]);
    }
    //queue[++r]=v;
    //BFS(queue[++f]); ???
}

int main()
{   
    int v;
    printf("enter the matrix : \n");
    for (int i=0 ; i<n ; i++)
    {
        for (int j=0 ; j<n ; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i=0 ; i<n ; i++)
    {
        visited[i]=0;
        printf("\nenter stack vertex - ");
        scanf("%d", &v);
        if (op==0)
        {
            DFS(v);
        }
        if (op==1)
        {
            BFS(v);
        }
    }
    return 0;
}

