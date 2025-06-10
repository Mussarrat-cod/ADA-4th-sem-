#include<stdio.h>
int knapsack(int n, int weights[], int values[], int W)
{
    int dp[n+1][W+1];
    for(int i=0;i<=n;i++)
    {
        for(int w=0;w<=W;w++)
        {
            if(i==0||w==0)
            {
                dp[i][w]=0;
            }
            else if(weights[i-1]<=w)
            {
                dp[i][w]=(values[i-1]+dp[i-1][w-weights[i-1]])>dp[i-1][w]?values[i-1]+dp[i-1][w-weights[i-1]]:dp[i-1][w];
                
            }
            else
            {
                dp[i][w]=dp[i-1][w];
            }
        }
    }
    return dp[n][W];
}


int main()
{
    int weights[10],values[10];
    int n, W;
    printf("Enter number");
    scanf("%d",&n);
    printf("Enter capacity");
    scanf("%d",&W);
    printf("Enter values");
    for(int i=0;i<n;i++){
        scanf("%d",&values[i]);
    }
     printf("Enter weights");
    for(int i=0;i<n;i++){
        scanf("%d",&weights[i]);
    }
    int max=knapsack(n,weights,values,W);
    printf("%d",max);
}
