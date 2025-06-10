#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#define V 4

int minDist(int dist[], bool sptSet[])
{
    int min=INT_MAX;
    int min_index;
    for(int i=0;i<V;i++)
    {
        if(sptSet[i]==false && min>dist[i])
        {
            min=dist[i];
            min_index=i;
        }
    }
    return min_index;
}

void print(int dist[])
{
    
   
    printf("Vertex \t Distance");
    for(int i=0;i<V;i++)
    {
        printf("\n%d \t\t%d",i,dist[i]);
    }
}

void dijkstra(int graph[V][V],int src)
{
    int dist[V];
    bool sptSet[V];
    
    for(int i=0;i<V;i++)
    {
        dist[i]=INT_MAX;
        sptSet[i]=false;
    }
    dist[src]=0;
    for(int count=0;count<V;count++)
    {
        int u=minDist(dist, sptSet);
        sptSet[u]=true;
        for(int v=0;v<V;v++)
        {
        if(!sptSet[v] && graph[u][v] && dist[u]!=INT_MAX && dist[v]>dist[u]+graph[u][v])
        {
            dist[v]=dist[u]+graph[u][v];
        }
        }
    }
    print(dist);
    
}

int main()
{
    int graph[V][V]={
        {0,10,6,5},
        {10,0,0,15},
        {6,0,0,4},
        {5,15,4,0}
    };
    dijkstra(graph, 0);
    return 0;
  }
