#include <stdio.h>
#include <stdlib.h>

int *queue, max, rear = -1, front = -1, data;

int isEmpty()
{
    if (front > rear || front == -1)
    {
        printf("\nQueue is not created...\n");
        return 1;
    }
    else
        return 0;
}

int isFull()
{
    if (rear == (max - 1))
    {
        printf("\nQueue reached it's maximum limit...");
        return 1;
    }
    else
        return 0;
}

void display()
{
    if (!isEmpty())
    {
        printf("\nValues in Queue: [  ");
        for (int i = front; i <= rear; i++)
            printf("%d  ", queue[i]);
        printf("]");
    }
}

void enqueue()
{
    if (!isFull())
    {
        printf("\nEnter value: ");
        scanf("%d", &data);
        queue[++rear] = data;
        if (rear == 0)
            front = 0;
        printf("One element has been added...\nData: %d",data);
    }
}

void dequeue()
{
    if (!isEmpty())
    {
        data = queue[front++];
        printf("\nOne item is deleted...\nData: %d", data);
    }
}

int main()
{
    int choice;
    printf("\nEnter how many node you need in the queue: ");
    scanf("%d", &max);
    queue = (int *)malloc(max * sizeof(int));
    printf("-------->Main Menu<--------\n1.Enqueue.\n2.Dequeue.\n3.Display.\n4.Exit.\n");
    while (choice != 4)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("You choose to ENQUEUE...");
            enqueue();
            display();
            break;
        case 2:
            printf("You choose to DEQUEUE...");
            dequeue();
            display();
            break;
        case 3:
            printf("You choose to DISPLAY QUEUE...");
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("\nYou enter a invalid choice...\n");
            break;
        }
    }
    return 0;
}
