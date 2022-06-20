#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int a[], int low, int mid, int high)
{
      int n1 = mid - low + 1;
      int n2 = high - mid;

      int L[n1], M[n2];

      for (int i = 0; i < n1; i++)
        L[i] = a[low + i];
      for (int j = 0; j < n2; j++)
        M[j] = a[mid + 1 + j];

      int i, j, k;
      i = 0;
      j = 0;
      k = low;

      while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
          a[k] = L[i];
          i++;
        } else {
          a[k] = M[j];
          j++;
        }
        k++;
      }

      while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
      }

      while (j < n2) {
        a[k] = M[j];
        j++;
        k++;
  }
}

void mergeSort(int a[], int low, int high)
{
  if (low < high) {

    int mid = low + (high - low) / 2;

    mergeSort(a, low, mid);
    mergeSort(a, mid + 1, high);
    merge(a, low, mid, high);
  }
}

display(int a[],int size)
{
    for(int i=0; i<size; i++)
    {
        printf("%d ",a[i]);
    }
}

int main()
{
    FILE *fp;
    fp = fopen("Unsorted.txt","w");
    int n, arr[500];
    srand(time(NULL));
    for(int i = 0; i<500; i++)
    {
        n = rand();
        printf("%d ", n);
        fprintf(fp,"%d ",n);
    }
    fclose(fp);

    fp = fopen("Unsorted.txt","r");

    for(int n=0; n<10; n++)
    {
        for (int i= n*50; i<(50*(n+1)); i++)
        {
            fscanf(fp,"%d",&arr[i]);
        }
        printf("\n\n");

        mergeSort(arr,0,50*n+49);
        printf("\n\n%d array\n\n",50*(n+1));
        display(arr,50*(n+1));
    }
    fclose(fp);

    fp = fopen("Unsorted.txt","a");
    fprintf(fp,"\n\nSorted Array:\n");
    for(int i = 0; i<500; i++)
    {
        fprintf(fp,"%d ",arr[i]);
    }
    fclose(fp);
    return 0;
}
