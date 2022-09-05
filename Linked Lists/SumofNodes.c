#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Node definition
typedef struct node{
   int data;
   struct node *next; 
}node;

node *np;
node *head;

int createnode(int x, int i)
{
    // First node
    if(i == 0)
    {
        // Node creation
        node *new = (node *)malloc(sizeof(node));
        new->data = x;
        new->next = NULL;

        // Assign first nodes' address to head
        head = new;
        np = new;
        
        return x;
    }
    
    // Node creation
    node *new = (node *)malloc(sizeof(node));

    new->data = x;
    new->next = NULL;

    // if this node is not first one then set previous nodes' link to this nodes' address
    np->next = new;
    
    // np now points to newly created node
    np = new;

    return x;

}

int  main()
{
    int n, x, sum = 0;

    np = NULL;
    head = NULL;

    printf("Enter number of elements to be stored: \n");
    scanf(" %d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("Element %d: ", i);
        scanf(" %d", &x);
        sum = sum + createnode(x, i);
    }

    printf("\nSum of nodes: %d\n", sum);

    return 0;
}