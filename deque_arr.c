#include <stdio.h>
#include <stdlib.h>

int max, *queue, front = -1, rear = -1, data;

int isEmpty()
{
    if (front == -1)
    {
        printf("\nQUEUE IS EMPTY...\n");
        return 1;
    }
    else
        return 0;
}

int isFull()
{
    if (front == (rear + 1) % max)
    {
        printf("\nQUEUE IS FULL...\n");
        return 1;
    }
    else
        return 0;
}

void insert_at_front()
{
    if (!isFull())
    {
        printf("\nEnter data: ");
        scanf("%d", &data);
        if (front == -1)
        {
            front = rear = 0;
            queue[front] = data;
        }
        else if (front == 0)
        {
            front = max - 1;
            queue[front] = data;
        }
        else
        {
            queue[--front] = data;
        }
        printf("\n%d has been ADDED at FRONT of QUEUE...\n", data);
    }
}

void insert_at_rear()
{
    if (!isFull())
    {
        printf("\nEnter data: ");
        scanf("%d", &data);
        rear = (rear + 1) % max;
        queue[rear] = data;
        if (front == -1)
            front = 0;
    }
    printf("\n%d has been ADDED at REAR of QUEUE...\n", data);
}

void delete_at_front()
{
    if (!isEmpty())
    {
        data = queue[front];
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % max;
        printf("\n%d has been REMOVED from FRONT of QUEUE...\n", data);
    }
}

void delete_at_rear()
{
    if (!isEmpty())
    {
        data = queue[rear];
        if (front == rear)
            front = rear = -1;
        else
        {
            if (rear == 0)
                rear = max - 1;
            else
                rear--;
        }
        printf("\n%d has been REMOVED from REAR of QUEUE...\n", data);
    }
}

void display()
{
    if (!isEmpty())
    {
        printf("\nValues in queue:  [  ");
        int i;
        for (i = front; i != rear; i = (i + 1) % max)
        {
            printf("%d  ", queue[i]);
        }
        printf("%d  ]", queue[i]);
    }
}

int main()
{
    printf("\nEnter size of queue: ");
    scanf("%d", &max);
    queue = (int *)malloc(max * sizeof(int));
    int choice;
    while (choice != 6)
    {
        printf("\n\n----->Main Menu<-----\n\n1.Insert at front\n2.Insert at rear\n3.Delete at front\n4.Delete at rear\n5.Show\n6.Exit\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_at_front();
            break;
        case 2:
            insert_at_rear();
            break;
        case 3:
            delete_at_front();
            break;
        case 4:
            delete_at_rear();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("\nCODE EXITD SUCCESSFULLY...\n");
            exit(0);
        default:
            printf("\nEnter a valid choice...\n");
            break;
        }
    }
    return 0;
}