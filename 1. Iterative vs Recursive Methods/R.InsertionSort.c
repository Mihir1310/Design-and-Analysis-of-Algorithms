#include<stdio.h>
#include<time.h>

void RecSelectionSort(int arr[], int num, int n)
{
    int i = num;
    if(n<0)
        return;
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
    RecSelectionSort(arr,num+1,n-1);
}

void main()
{
    int n=10000;
    printf("Recursive Insertion Sort\n");
    //printf("\nEnter number of elements : ");
    //scanf("%d",&n);
    //printf("\nEnter array : ");
    int arr[n];
    for(int i=0; i<n; i++)
    {
        arr[i]=10000-i;
    }

    int num=0;
    clock_t t;
    t = clock();
    RecSelectionSort(arr, num, n);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds





    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\nExecution Time : %f", time_taken);


}

