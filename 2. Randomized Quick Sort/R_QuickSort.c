#include<stdio.h>
#include<time.h>

void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition (int a[], int l, int h)
{
    int pivot = a[l];
    int i=l, j=h;
    while(i<j)
    {
        do{
            i++;
        }
        while(a[i]<=pivot);
        do{
            j--;
        }
        while(a[j]>pivot);
        if(i<j)
            swap(&a[i],&a[j]);
    }
    swap(&a[l],&a[j]);
    printf("\nAfter Partition :\n ");
    display(a);
    return j;
}

int random_lh (int a[], int l, int h)
{
    srand(time(NULL));
    int random = l + rand() % (h - l);
    printf("Pivot is : %d",random);
    swap(&a[random], &a[l]);

    return partition(a, l, h);
}

void QuickSort(int a[], int l, int h)
{
    if(l<h)
    {
        int j = random_lh(a,l,h);
        QuickSort(a,l,j);
        QuickSort(a,j+1,h);
    }
}

void display(int a[])
{
    int i;
    for (i=0; i < 10; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int size=10;
    //printf("Enter size of array : ");
    //scanf("%d",&size);
    int a[size];
    //printf("Enter array :");

    for(int i=0; i<size; i++)
    {
        a[i] = 10-i;
    }
    printf("Original Array : \n");
    display(a);
    QuickSort(a, 0, size);
    printf("\nSorted array: \n");
    display(a);
    return 0;
}

