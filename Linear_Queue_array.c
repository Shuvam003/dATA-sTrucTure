#include <stdio.h>
#include <stdlib.h>

int *queue, front = -1, max, data, rear = -1;

int isEmpty()
{
    if (front > rear || front == -1)
    {
        printf("\nQUEUE IS EMPTY...\n");
        return 1;
    }
    else
        return 0;
}

int isFull()
{
    if (rear == max - 1)
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
        queue[++rear] = data;
        if (front == -1)
            front = 0;
        printf("\n%d has been added to queue...\n", data);
    }
}

void dequeue()
{
    if (!isEmpty())
    {
        data = queue[front++];
        printf("\n%d has been removed from queue...\n", data);
    }
}

void display()
{
    if (!isEmpty())
    {
        printf("\nElements in queue: [  ");
        for (int i = front; i <= rear; i++)
            printf("%d  ", queue[i]);
        printf("]\n");
    }
}

void In_limit()
{
    int a = max;
    printf("\nUpdated size of queue: ");
    scanf("%d", &max);
    if (max < a)
    {
        printf("\nNew size can't be lass than old size...\n");
        max = a;
    }
    else
        queue = (int *)realloc(queue, max);
}

int main()
{
    printf("\nEnter the size of queue: ");
    scanf("%d", &max);
    queue = (int *)malloc(max * sizeof(int));
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