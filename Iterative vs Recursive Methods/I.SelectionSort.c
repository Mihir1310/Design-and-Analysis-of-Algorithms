#include<stdio.h>


void main()
{
    int n=10000;
    printf("Itterative Selection Sort\n");
    printf("\nEnter number of elements : ");
    //scanf("%d",&n);
    printf("\nEnter array : ");
    int arr[n];
    for(int i=0; i<n; i++)
    {
        arr[i] = 10000-i;
    }

    int index;
    for(int i=0; i<n-1; i++)
    {
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
    }

    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
}
