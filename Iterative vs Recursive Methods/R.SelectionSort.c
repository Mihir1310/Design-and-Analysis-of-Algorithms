#include<stdio.h>

void RecSelectionSort(int arr[], int num, int n)
{
    int index,i;
    i=num;
    if(n<0)
        return;
    index = i;
    for(int j=i+1; j<n; j++)
    {
        if(arr[index]>arr[j])
        {
            index = j;
        }
    }

    int temp;
    temp = arr[i];
    arr[i] = arr[index];
    arr[index] = temp;

    RecSelectionSort(arr,num+1,n-1);
}

void main()
{
    int n=10000;
    printf("Recursive Selection Sort\n");
    printf("\nEnter number of elements : ");
    //scanf("%d",&n);
    printf("\nEnter array : ");
    int arr[n];
    for(int i=0; i<n; i++)
    {
        arr[i] = 10000-i;
    }
    int num=0;
    RecSelectionSort(arr, num, n);
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
}

