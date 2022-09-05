#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p;

    p = (int *)malloc(sizeof(int)); //creates pointer to an integer

    //assigning p values (can be done dynamically now)
    p[0] = 1;
    p[1] = 2;
    p[2] = 24139848;
    p[3] = 5453;
    p[4] = 59;
    p[5] = 4;

    for(int i = 0; i < 6; i++)
    {
        printf("P[%d] = %d\n", i, p[i]);
    }

    printf("%x", p);    //address of pointer

    return 0;

}