#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct diag_MAT
{
    int *p;
    int dimension;
}diag_MAT;

void setdata(diag_MAT *a, int x, int k)
{
    *(a->p + k) = x;
}

void print(diag_MAT *a)
{
    printf("Elements are: \n");

    for(int i = 0; i < a->dimension; i++)
    {   
        for(int j = 0; j < a->dimension; j++)
        {       
            if(i == j)
            {
                printf("%d\t", *(a->p + j), (a->p + j));
                continue;
            }
            printf("0\t");
        }
        printf("\n");
    }
}

int main()
{
    int n;

    printf("Enter the size of the square matrix: ");
    scanf(" %d", &n);

    diag_MAT m1;

    m1.dimension = n;
    m1.p = (int *)malloc(n*sizeof(int));

    for(int i = 0; i < n; i++)
    {
        printf("Enter the diagonal element %d of the square matrix: ", i + 1);
        scanf(" %d", &n);
        setdata(&m1, n, i);
    }

    print(&m1);
    return 0;

}
