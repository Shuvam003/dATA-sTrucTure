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

int isEmpty()
{
    if (top == -1)
    {
        printf("\nSTACK IS EMPTY...");
        return 1;
    }
    else
        return 0;
}

int isFull()
{
    if (top == max - 1)
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
        stack[++top] = data;
        printf("%d has been pushed...", data);
    }
}

void pop()
{
    if (!isEmpty())
    {
        data = stack[top--];
        printf("\n%d has been popped...", data);
    }
}

void peek()
{
    if (!isEmpty())
    {
        printf("\nTop Element of the stack = %d", stack[top]);
    }
}

int main()
{
    int a;
    printf("\nEnter size of stack: ");
    scanf("%d", &max);
    stack = (int *)malloc(max * sizeof(int));
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