#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Array{
   int *p;
   int size;
   int length 
}Array;

void print_elements(Array *a)
{
    printf("Elements are: \n");

    for(int i = 0; i < a->length; i++)
    {
        printf("%d     %x\n", *(a->p + i), (a->p + i));
    }
}

void create(Array *A, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("Element %d: ", i);
        scanf(" %d", (A->p + i));    //accessing our Array structure's pointer p dynamically and storing 2 to those locations 
    }
    A->length = n;

    printf("\n");
}

void insert_delete(Array *A, int x, int n, int z)
{
    
    if(z == 1)
    {
        for(int i = A->length; i >= x; i--)
        {
            if(i == x)
            {
                *(A->p + i + 1) = *(A->p + i);  // Need to use dereferencing here because p itself is a pointer
                *(A->p + i) = n;
                break;
            }
            *(A->p + i + 1) = *(A->p + i);
        }
        A->length++; 
    }
    else
    {
        for(int i = x; i <= A->length; i++)
        {
            *(A->p + i) = *(A->p + i + 1);
        }
       
        *(A->p + A->length) = NULL;
        A->length--;
    }
    
}

int main(int argc, char *argv[])
{
    Array *A = (Array *)malloc(sizeof(Array));   //this pointer A points to a structure with allocated memory

    A->size = atoi(argv[1]);
    A->p = (int *)malloc(A->size*sizeof(int));

    int n, x, z;
    printf("Enter number of elements: ");
    scanf(" %d", &x);

    create(A, x);
    print_elements(A);

    printf("Do you want to insert/delete an element (1 for insert/0 for delete/2 to skip all)?: ");
    scanf(" %d", &z);

    if(z == 1)
    {
        printf("Enter index at which to insert: ");
        scanf(" %d", &x);
        printf("Enter element to insert: ");
        scanf(" %d", &n);
        insert_delete(A, x, n, z);
        print_elements(A);
    }
    else if(z == 0)
    {
        printf("Enter index at which to delete: ");
        scanf(" %d", &x);
        insert_delete(A, x, 0, z);
        print_elements(A);
    }

    
}