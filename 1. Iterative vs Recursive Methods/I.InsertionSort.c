#include<stdio.h>
#include<time.h>
void main()
{
    int n=10000;
    clock_t t;
    printf("Itterative Insertion Sort\n");
    printf("\nEnter number of elements : ");
    //scanf("%d",&n);
    //printf("\nEnter array : ");
    int arr[n];
    for(int i=0; i<n; i++)
    {
        arr[i] = 10000-i;
    }
    t = clock();
    for(int i=0; i<n-1; i++)
    {
        for(int j=i; j>=0; j--)
        {
            if(arr[j+1]<arr[j])
            {
                int temp;
                temp = arr[j+1];
                arr[j+1]=arr[j];
                arr[j] = temp;
            }
        }
    }
    t=clock()-t;
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\nExecution Time : %f", time_taken);

}
