#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#define V 5
int minKey(int key[], bool mstSet[])
{
    int min=INT_MAX;
    int min_index;
    for(int v=0;v<V;v++)
    {
        if(mstSet[v]==false && key[v]<min)
        {
            min=key[v];
            min_index=v;
        }
    }
    return min_index;
}

void printMST(int parent[], int graph[V][V])
{
    int total=0;
    printf("Edge \t\t Weight");
    for(int i=1;i<V;i++)
    {
        printf("%d \t %d \t\t %d",parent[i], i, graph[i][parent[i]] );
        total  += graph[i][parent[i]];
    }
    printf("%d", total);
}
void prim(int graph[V][V])
{
    int key[V];
    int parent[V];
    bool mstSet[V];
    
    for(int i=0;i<V;i++)
    {
        key[i]=INT_MAX;
        mstSet[i]=false;
    }
    
    key[0]=0;
    parent[0]=-1;
    
    for(int count=0;count<V;count ++)
    {
        int u=minKey(key, mstSet);
        mstSet[u]=true;
        for(int v=0;v<V;v++)
            
    
        if(graph[u][v]&&mstSet[v] && key[v]>graph[u][v])
        {
            parent[v]=u;
            key[v]=graph[u][v];
        }
    }
    printMST(parent, graph);
}

int main()
{
    int graph[V][V]={{0,2,0,6,0},
    {2,0,3,8,5},
    {6,8,0,0,9},
    {0,5,7,9,0}};
    prim(graph);
    return 0;
}
