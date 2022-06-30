#include<stdio.h>
#include<string.h>
#define MAX(X, Y) (X > Y ? X : Y)

void main()
{
    char X[20], Y[20];
    printf("Enter 1st String : ");
    gets(X);
    printf("\nEnter 2nd String : ");
    gets(Y);
    printf("\n1st : %s",X);
    printf("\n2nd : %s",Y);

    int m = strlen(X);
    int n = strlen(Y);
    printf("\n%d", m);
    printf("\n%d\n", n);

    int matrix[m+1][n+1];

    for(int i = 0; i<m+1; i++)
    {
        for(int j=0; j<n+1; j++)
        {
            if (i==0 || j==0)
            {
                matrix[i][j] =0;
            }
        }
    }



    for(int i = 0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(X[i] == Y[j])
            {
                matrix[i+1][j+1] = matrix[i][j] + 1;
            }
            else
            {
                matrix[i+1][j+1] = MAX(matrix[i][j+1], matrix[i+1][j]);
            }
        }
    }

    printf("\nFinal Mat : \n");
    for(int i=0; i<m+1; i++)
    {
        printf("\n");
        for(int j=0; j<n+1; j++)
        {
            printf("%d ",matrix[i][j]);
        }
    }
    printf("\n\nLongest Common Sequence is : ");
    //Back Propagation
    int i = m; //6
    int j = n; //4

    do
    {
        if(matrix[i][j] == matrix[i][j-1])
        {
            j--;
        }
        else if(matrix[i][j] == matrix[i-1][j])
        {
            i--;
        }
        else
        {
            printf("%c ", X[i-1]);
            i--;
            j--;
        }
    }while(i!=0 && j!=0);


}

/*
Output:

Enter 1st String : abcdefghi

Enter 2nd String : cfiabdgh

1st : abcdefghi
2nd : cfiabdgh
9
8

Final Mat :

0 0 0 0 0 0 0 0 0
0 0 0 0 1 1 1 1 1
0 0 0 0 1 2 2 2 2
0 1 1 1 1 2 2 2 2
0 1 1 1 1 2 3 3 3
0 1 1 1 1 2 3 3 3
0 1 2 2 2 2 3 3 3
0 1 2 2 2 2 3 4 4
0 1 2 2 2 2 3 4 5
0 1 2 3 3 3 3 4 5

Longest Common Sequence is : h g d b a

*/
