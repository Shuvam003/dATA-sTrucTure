#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *head = NULL;
int max, data, top = 0;

void push();
void pop();
void peek();
int isFull();
int isEmpty();

int isEmpty()
{
    if (head == NULL)
    {
        printf("\nSTACK IS EMPTY...");
        return 1;
    }
    else
        return 0;
}

int isFull()
{
    if (top == max)
    {
        printf("\nSTACK IS FULL...");
        return 1;
    }
    else
        return 0;
}

void push()
{
    if (!isFull())
    {
        printf("\nEnter data: ");
        scanf("%d", &data);
        node *newnode = (node*)malloc(sizeof(node));
        newnode->data = data;
        newnode->next = head;
        head = newnode;
        top++;
        printf("%d has been pushed...", data);
    }
}

void pop()
{
    if (!isEmpty())
    {
        data = head->data;
        node *temp = head;
        head = head->next;
        free(temp);
        top--;
        printf("\n%d has been popped...", data);
    }
}

void peek()
{
    if (!isEmpty())
    {
        printf("\nTop Element of the stack = %d", head->data);
    }
}

int main()
{
    int a;
    printf("\nEnter size of stack: ");
    scanf("%d", &max);
    int choice;
    printf("---->Main Menu<----\n1.Push    2.Pop\n3.Peek    4.Exit\n");
    while (choice != 4)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("You choose to PUSH a data to stack...");
            push();
            peek();
            break;
        case 2:
            printf("You choose to POP a data from stack...");
            pop();
            peek();
            break;
        case 3:
            printf("You choose to show PEEK data of stack...");
            peek();
            break;
        case 4:
            printf("\nCODE EXITED SUCCESSFULLY...\n");
            exit(0);
        }
    }
    return 0;
}