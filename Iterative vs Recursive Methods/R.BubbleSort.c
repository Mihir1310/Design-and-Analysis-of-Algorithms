#include <stdio.h>
#include<time.h>

void BubbleSortRecursion(int a[],int num)
{
int i,j,temp;

i=num;
if(i>0)
{
for(j=0; j<num-1; j++)
{
if(a[j]>a[j+1])
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
BubbleSortRecursion(a,num-1);
}
else
{
return;
}
}

void printArray(int arr[], int size)
{
int i;
for (i=0; i < size; i++)
printf("%d ", arr[i]);
printf("\n");

}

int main()
{
int no=10000;
int j = no;
int arr[no];
for(int i=0;i<no;i++)
{
arr[i]=no-j;
j--;
}
int n = sizeof(arr)/sizeof(arr[0]);
BubbleSortRecursion(arr, n);
printf("Sorted array: \n");
printArray(arr, n);
return 0;
}
