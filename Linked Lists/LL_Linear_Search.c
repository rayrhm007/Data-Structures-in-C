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

node *Find(node *tmp, node *pp, int key)
{
    if(tmp->data == key)
    {
        pp->next = tmp->next;
        tmp->next = head;
        head = tmp;
        return tmp;
    }
    
    if(tmp->next == NULL)
    {
        return NULL;
    }

    return Find(tmp->next, tmp, key);

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

    printf("\nEnter Key to search: ");
    scanf(" %d", &x);
    np = Find(head, NULL, x);

     if(np == NULL)
     {
        printf("Not found");
     }
     else
     {
        printf("Key found at %x\n", np);
     }

     n = Print(head, 0);
     

    return 0;
}