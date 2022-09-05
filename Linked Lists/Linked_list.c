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

void createnode(int x, int i)
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
        
        return;
    }
    
    // Node creation
    node *new = (node *)malloc(sizeof(node));

    new->data = x;
    new->next = NULL;

    // if this node is not first one then set previous nodes' link to this nodes' address
    np->next = new;
    
    // np now points to newly created node
    np = new;

}

int Print(node *temp, int count)
{
    
    // Normal printing
    printf(" %d\n", temp->data);
    count++;

    if(temp->next != NULL)
    {
        temp = temp->next;
        count = Print(temp, count);
        return count;
    } 
    
    return count;
    
    
    /* Reverse printing
    if(temp == NULL)
    {
        return 0;
    }
    
    count = Print(temp->next, count);
    count++;
    printf("%d\t%x\n", temp->data, temp);
    return count; */

}

int  main()
{
    int n, x;

    np = NULL;
    head = NULL;

    printf("Enter number of elements to be stored: \n");
    scanf(" %d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("Element %d: ", i);
        scanf(" %d", &x);
        createnode(x, i);
    }

    n = Print(head, 0);    //send first address of list, receive count of nodes

    printf("\nNumber of nodes: %d\n", n);

    return 0;
}