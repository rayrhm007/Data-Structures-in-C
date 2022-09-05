#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack
{
    int element;
    struct Stack *next;
}Stack;

Stack *top = NULL;

void PUSH(int x)
{
    Stack *tmp = (Stack *)malloc( sizeof(Stack));

    tmp->element = x;
    tmp->next = top;
    top = tmp;
}

void POP()
{
    Stack *tmp;

    if(top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("%d popped\n", top->element);
    
    tmp = top->next;

    free(top);
}

int main()
{
    char str[5];
    int x; 

    while(1)
    {
        printf("Do you want to enter an element? (Yes/No):");
        
        // Replacement of gets()
        fgets(str, sizeof(str), stdin);
        str[strlen(str) - 1]='\0';  // This line removes the newline that fgets() automatically absorbs
                                    // so that strcmp() works 

        if(strcmp(str, "No") == 0)
        {
            break;
        } 
        
        printf("\nEnter the element: ");
        scanf(" %d", &x);
        
        // This scanf removes \n from buffer, otherwise fgets() will be skipped
        scanf("%c");
        PUSH(x);
    }

    POP();

    return 0; 

}