#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p;
    p = (int *)malloc(30*sizeof(int));

    int key;

    printf("Enter the element to search for in the array: ");
    scanf(" %d", &key);

    for(int i = 0; i < 100; i++)
    {
        *(p + i) = i;
    }

    for(int i = 0; i < 100; i++)
    {
        if(key == *(p+i))
        {
            printf("Operation successful, found at index: %d", i);
            return 0;
        }
        else
        {
            continue;
        }
    }
    printf("Unsuccessful");
    return 1;
}