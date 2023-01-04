#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL;

int max, count = 0, data;

int isEmpty()
{
    if (head == NULL)
    {
        printf("\nQUEUE IS EMPTY...\n");
        return 1;
    }
    else
        return 0;
}

int isFull()
{
    if (count == max)
    {
        printf("\nQUEUE IS FULL...\n");
        return 1;
    }
    else
        return 0;
}

void enqueue()
{
    if (!isFull())
    {
        printf("\nEnter data: ");
        scanf("%d", &data);
        node *newnode = (node *)malloc(sizeof(node));
        newnode->data = data;
        newnode->next = newnode;
        if (head == NULL)
            head = newnode;
        else
        {
            node *temp = head;
            while (temp->next != head)
                temp = temp->next;
            newnode->next = head;
            temp->next = newnode;
        }
        count++;
        printf("\n%d has been added to queue...\n", data);
    }
}

void dequeue()
{
    if (!isEmpty())
    {
        data = head->data;
        node *temp = head;
        if (head->next == head)
            head = NULL;
        else
        {
            while (temp->next != head)
                temp = temp->next;
            temp->next = head->next;
            temp = head;
            head = head->next;
        }
        free(temp);
        count--;
        printf("\n%d has been removed from queue...\n", data);
    }
}

void display()
{
    if (!isEmpty())
    {
        node *temp = head;
        printf("\nValues in queue: [  ");
        while (temp->next != head)
        {
            printf("%d  ", temp->data);
            temp = temp->next;
        }
        printf("%d  ]\n", temp->data);
    }
}

int main()
{
    printf("\nEnter the size of queue: ");
    scanf("%d", &max);
    int choice;
    while (choice != 4)
    {
        printf("\n-------->Main Menu<--------\n\n1.Enqueue.\n2.Dequeue.\n3.Display.\n4.Exit.\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\nCODE EXITED SUCCESSFULLY...\n");
            exit(0);
        default:
            printf("\nYou enter a invalid choice...\n");
            break;
        }
    }
    return 0;
}