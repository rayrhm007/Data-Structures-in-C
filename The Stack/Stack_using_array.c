#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack
{
    int size;
    int top;
    int *p;
}Stack;

int PUSH(Stack *st, int x)
{
    // Incase user fills stack
    if( st->top == (st->size - 1) )
    {
        printf("Stack Overflow\n");
        return 1;
    }

    st->top++;
    st->p[st->top] = x;

    return 0;
}

void POP(Stack *st)
{
    printf("%d\n", st->p[st->top]);
    st->top--;
}

void PEEK(Stack *s1, int i)
{
    printf( "The element at position %d is: %d\n", i, s1->p[s1->top - i + 1] ); 
}

int main()
{
    int n, x, y;
    Stack s;

    printf("Enter full size of stack: ");
    scanf(" %d", &s.size);

    s.p = (int *)malloc( sizeof(int)*(s.size) );
    s.top = -1;

    printf("Enter number of elements (must be smaller than or equal to stack size): ");
    scanf(" %d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("Element: ");
        scanf(" %d", &x);
        if(PUSH(&s, x) == 1)
        {
            break;
        }
    }

    PEEK(&s, 3);

    while(s.top != -1)
    {
        POP(&s);
    }

    return 0;

}