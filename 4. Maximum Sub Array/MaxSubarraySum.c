#include<stdio.h>
#include<stdlib.h>

int crossarray(int arr[], int low, int mid, int high)
{
    int sum = 0;
    int ls = 0;
    //left_max
    for(int i=mid; i>=low; i--)
    {
        sum = sum + arr[i];
        if(sum > ls)
            ls = sum;
    }
    //right_max
    sum = 0;
    int rs = 0;
    for(int i = mid+1; i <= high; i++)
    {
        sum = sum + arr[i];
        if(sum > rs)
            rs = sum;
    }

    int max = (ls>rs) ? (ls>(ls+rs)?ls:(ls+rs)) : (rs>(ls+rs)?rs:(ls+rs));
    //return max(left_max,right_max, left_max+right_max)
    return  max;
}

int subarray(int arr[], int low, int high)
{

    if(low == high)
        return arr[low];

    int mid = (low + high)/2;

    printf("%d->%d\n",arr[low],arr[high]);

    int x = subarray(arr, low, mid);
    int y = subarray(arr, mid+1, high);
    int z = crossarray(arr, low, mid, high);

    int max = (x>y) ? (x>z?x:z) : (y>z?y:z);
    return max;
}

void main()
{
    int size;
    printf("Enter size of array : ");
    scanf("%d",&size);
    int arr[size];
    //For random inputs
    /*for (int i = 0; i<size; i++)
    {
        arr[i] = rand()%30 - 15;
    }*/

    for (int i = 0; i<size; i++)
    {
        printf("Enter a[%d] : ",i);
        scanf("%d",&arr[i]);
    }

    printf("\nArray is : ");
    for (int i = 0; i<size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    int mss = subarray(arr, 0, size-1);
    printf("Max Sub Array is %d",mss);
}
