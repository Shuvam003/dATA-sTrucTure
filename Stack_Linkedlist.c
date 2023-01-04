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
void resize_stack();

int isEmpty()
{
    if (head == NULL)
    {
        printf("\nSTACK IS EMPTY...\n");
        return 1;
    }
    else
        return 0;
}

int isFull()
{
    if (top == max)
    {
        printf("\nSTACK IS FULL...\n");
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
        printf("\n%d has been pushed...\n", data);
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
        printf("\n%d has been popped...\n", data);
    }
}

void resize_stack()
{
    printf("\nUpdated size of the stack: ");
    int a = max;
    scanf("%d", &max);
    if(a>max){
        printf("\nMaximum size of stack can't decrease...\n");
        max = a;
    }
}

void peek()
{
    if (!isEmpty())
    {
        printf("\nTop Element of the stack = %d\n", head->data);
    }
}

int main()
{
    int a;
    printf("\nEnter size of stack: ");
    scanf("%d", &max);
    int choice;
    while (choice != 5)
    {
        printf("\n\n---Main Menu---\n\n1.Push\n2.Pop\n3.Peek\n4.Increase size of stack\n5.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            resize_stack();
            break;
        case 5:
            printf("\nCode Exited Successfully...\n");
            exit(0);
        }
    }
    return 0;
}