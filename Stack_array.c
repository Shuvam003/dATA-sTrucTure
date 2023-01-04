#include <stdio.h>
#include <stdlib.h>

int *stack;
int top = -1;
int max, data;

void push();
void pop();
void peek();
int isFull();
int isEmpty();
void resize_stack();

int isEmpty()
{
    if (top == -1)
    {
        printf("\nSTACK IS EMPTY...\n");
        return 1;
    }
    else
        return 0;
}

int isFull()
{
    if (top == max - 1)
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
        stack[++top] = data;
        printf("\n%d has been pushed...\n", data);
    }
}

void pop()
{
    if (!isEmpty())
    {
        data = stack[top--];
        printf("\n%d has been popped...\n", data);
    }
}

void resize_stack()
{
    int a = max;
    printf("\nUpdated size of the stack: ");
    scanf("%d", &max);
    if (max < a)
    {
        printf("\nNew size can't be lass than old size...\n");
        max = a;
    }
    else
        stack = (int *)realloc(stack, max);
}

void peek()
{
    if (!isEmpty())
    {
        printf("\nTop Element of the stack = %d\n", stack[top]);
    }
}

int main()
{
    int a;
    printf("\nEnter size of stack: ");
    scanf("%d", &max);
    stack = (int *)malloc(max * sizeof(int));
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