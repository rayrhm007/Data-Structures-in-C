#include <stdio.h>
#include <stdlib.h>

typedef struct LTMat
{
    int size;
    int *p;
}LTMat;

void set_rmajor(LTMat *a, int n, int i)
{
    *(a->p + i) = n;
}

int get_elements(LTMat *a, int i, int j)
{
    int k;

    if(i >= j)
    {
        k = ( (i*(i - 1))/2 ) + (j - 1);
        return *(a->p + k); 
    }

    return 0;
}

int main()
{
    LTMat m1;
    int x, n;

    printf("Enter size of Matrix: ");
    scanf(" %d", &x);

    m1.size = x;
    m1.p = (int *)malloc( (x*(x + 1)/2)*sizeof(int) );
    printf("Enter elements to fill up lower triangular matrix: \n");
    
    for(int i = 0; i < (x*(x + 1))/2; i++)
    {
        scanf(" %d", &n);
        set_rmajor(&m1, n, i);
    }
    
    for(int i = 1; i <= x; i++)
    {
        for(int j = 1; j <= x; j++)
        {
            printf("%d\t", get_elements(&m1, i, j)); 
        }
        printf("\n");
    }

    return 0;
}

