#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL;
int max, data, count = 0;

int isEmpty()
{
    if (count == 0 || head == NULL)
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
        newnode->next = NULL;
        if (head == NULL)
            head = newnode;
        else
        {
            node *temp = head;
            while (temp->next != NULL)
                temp = temp->next;
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
        head = head->next;
        free(temp);
        printf("\n%d has been removed from queue...\n", data);
    }
}

void display()
{
    if (!isEmpty())
    {
        node *temp = head;
        printf("\nValues in queue:  [  ");
        while (temp != NULL)
        {
            printf("%d  ", temp->data);
            temp = temp->next;
        }
        printf("]\n");
    }
}

void In_limit(){
    printf("\nUpdated size of the queue: ");
    int a = max;
    scanf("%d", &max);
    if(a>max){
        printf("\nMaximum size of queue can't decrease...\n");
        max = a;
    }
}

int main()
{
    printf("\nEnter the size of queue: ");
    scanf("%d", &max);
    int choice;
    while (choice != 5)
    {
        printf("\n-------->Main Menu<--------\n\n1.Enqueue.\n2.Dequeue.\n3.Display.\n4.Increase limit of queue.\n5.Exit.\n\nEnter your choice: ");
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
            In_limit();
            break;
        case 5:
            printf("\nCODE EXITED SUCCESSFULLY...\n");
            exit(0);
        default:
            printf("\nYou enter a invalid choice...\n");
            break;
        }
    }
    return 0;
}