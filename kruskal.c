#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int u, v, weight;
}Edge;

int compare(const void* a, const void* b)
{
    return ((Edge*)a)->weight- ((Edge*)b)->weight;
}

int find(int parent[], int i)
{
    while(parent[i]!=i)
    {
        i=parent[i];
        
    }
    return i;
}

void kruskal(Edge edges[], int n, int e)
{
    qsort(edges, e, sizeof(Edge),compare);
    int *parent=malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    parent[i]=i;
    
    int maxCost=0;
    for(int i=0;i<e;i++)
    {
        int u_root=find(parent,edges[i].u);
        int v_root=find(parent,edges[i].v);
    
    if(u_root!=v_root)
    {
        printf(" %d--%d = %d\n", edges[i].u, edges[i].v, edges[i].weight);
        maxCost+=edges[i].weight;
        parent[v_root]=u_root;
    }
    }
    printf("\nMax cost is");
    printf("%d",maxCost);
    free(parent);
    
}

int main()
{
    Edge edges[]={
        {0,1,10},
        {0,2,6},
        {0,3,5},
        {1,3,15},
        {2,3,4}
    };
    int vertices=4;
    int edge_count=sizeof(edges)/sizeof(edges[0]);
    kruskal(edges, vertices, edge_count);
    return 0;
}
