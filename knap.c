#include<stdio.h>
int w[10],p[10],m,n;
int max(int a, int b)
{
    return a>b?a:b;
}

int knap(int i, int m)
{
    if(i==n)
    return w[i]>m?0:p[i];
    if(w[i]>m)
    return knap(i+1, m);
    return max(knap(i+1,m),knap(i+1,m-w[i])+p[i]);
}

int main()
{
   
    printf("Enter number");
    scanf("%d",&n);
    printf("Enter max capacoty");
    scanf("%d",&m);
    printf("Enter profit then weight");
    for(int i=0;i<n;i++)
    {
        scanf("%d %d", &p[i],&w[i]);
    }
    int max_pr= knap(0,m);
    printf("max is %d ", max_pr);
    
}
