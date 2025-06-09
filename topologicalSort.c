#include<stdio.h>
#define MAX 10
void topologicalSort(int n, int graph[MAX][MAX])
{
    int result[MAX],queue[MAX];
    int inDegree[MAX]={0};
    int front=0, rear=-1, count=0;
    int i, j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if (graph[i][j])
            {
                
                inDegree[j]++;
                }
        }
    }
    
    for(i=0;i<n;i++)
    if(inDegree[i]==0)
    {
        queue[++rear]=i;
    }
    
    while(front<=rear)
    {
        int u=queue[front++];
        result[count++]=u;
        for(int v=0;v<n;v++)
        {
            if(graph[u][v]&& --inDegree[v]==0)
            queue[++rear]=v;
        }
    }
    
    printf("topologicalSort");
    for(i=0;i<n;i++)
    {
        printf("%d",result[i]+1);
    }
    printf("\n");
}

int main()
{
    int n,i,j,graph[MAX][MAX];
    printf("Enter number of elemengs");
    scanf("%d",&n);
    printf("Enter Adjacency matrix");
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    {
        scanf("%d",&graph[i][j]);    }
    topologicalSort(n,graph);
}









