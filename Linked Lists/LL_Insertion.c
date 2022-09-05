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
    
    if(i == 0)
    {   
        node *new = (node *)malloc(sizeof(node));
        new->data = x;
        new->next = NULL;

        head = new;
        np = new;
        
        return;
    }
    
    node *new = (node *)malloc(sizeof(node));

    new->data = x;
    new->next = NULL;

    np->next = new;
    
    np = new;

}

void Print(node *temp)
{
    
    printf(" %d\n", temp->data);

    if(temp->next != NULL)
    {
        temp = temp->next;
        Print(temp);
        return;
    } 
    
    return;

}

void Insert(int key, int i)
{
    if(i == 1)
    {
        // for inserting in 1st position create a node in 1st position of existing linked list
        node *tmp = (node *)malloc(sizeof(node));
        tmp->next = head;
        head = tmp;
        tmp->data = key;
        return;
    }

    node *tmp;
    tmp = head;

    for(int j = 1; j < i; j++)
    {
        tmp = tmp->next;
    }

    // create new node to push data into
    node *new = (node *)malloc(sizeof(node));
    new->data = key;

    // New node points to next node in chain. Previous node points to newly created node
    new->next = tmp->next;
    tmp->next = new;

    return;


}

int  main()
{
    int n, x, key;

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

    // Taking key for Node insertion
    printf("Enter the key to be inerted: ");
    scanf(" %d", &key);
    printf("Enter position to be inserted: ");
    scanf(" %d", &n);

    Insert(key, n);

    Print(head);

    return 0;
}