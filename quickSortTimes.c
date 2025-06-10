#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
    int t= *a;
    *a=*b;
    *b=t;
}

int partition(int a[], int low, int high)
{
    int pivot=a[low];
    int i=high;
    for(int j=high;j>low;j--)
    {
        if(a[j]<a[low])
        {
        swap(&a[j],&a[low]);
        i--;
        }
        swap(&a[i],&a[low]);
    }
}

void quickSort(int a[], int low, int high)
{
    if(low<=high)
    {
    int pi= partition(a, low, high);
    quickSort(a,low,pi-1);
    quickSort(a, pi+1,high);
    }
}

int generateRandomArray(int , int a[])
{
    int n;
    for(int i=0;i<n;i++)
    {
        a[i]= rand() % 100000;
    }
}
int main()
{
    int n;
    printf("Enter number of elements");
    scanf("%d", &n);
    if(n<5000)
    {
        printf("INVALID");
    }
    int *a = malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        a[i]=generateRandomArray(n,a);
    }
    
    clock_t start=clock();
    quickSort(a,0, n-1);
    clock_t end=clock();
    double times= (double)(end-start)/CLOCKS_PER_SEC;
    printf("Time taken for %d is %f", n, times );
    free(a);
    return 0;
    
}
