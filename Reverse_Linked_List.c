#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next, *prev;
} node;

node *head = NULL;

void display()
{
    node *temp = head;
    printf("Values in Linked List:  [  ");
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("]");
}

int main()
{
    int size, data;
    printf("\nEnter size of linked list: ");
    scanf("%d", &size);
    node *temp;
    printf("Enter values in linked list: ");
    for (int i = 1; i <= size; i++)
    {
        scanf("%d", &data);
        node *newnode = (node *)malloc(sizeof(node));
        newnode->data = data;
        newnode->next = NULL;
        newnode->prev = NULL;
        if (i == 1)
        {
            head = newnode;
            temp = head;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = temp->next;
        }
    }
    display();
    node *tmp = head;
    node *ptr;
    while (tmp != NULL)
    {
        ptr = tmp->next;
        tmp->next = tmp->prev;
        tmp->prev = ptr;
        tmp = ptr;
    }
    head = ttm;
    printf("\nLinked List has been reverse...\n");
    display();
    printf("\n");
    return 0;
}