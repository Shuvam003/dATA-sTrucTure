#include <stdio.h>
#include <stdlib.h>

int *queue, max, front = -1, rear = -1, data;

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

void enqueue()
{
    if (!isFull())
    {
        printf("\nEnter data: ");
        scanf("%d", &data);
        rear = (rear + 1) % max;
        queue[rear] = data;
        if (front == -1)
            front = 0;
        printf("\n%d has been added to queue...\n", data);
    }
}

void dequeue()
{
    if (!isEmpty())
    {
        data = queue[front];
        if (rear == front)
            rear = front = -1;
        else
            front = (front + 1) % max;
        printf("\n%d has been removed from queue...\n", data);
    }
}

void display(){
    if(!isEmpty()){
        int i = front;
        printf("\nValues in queue:  [  ");
        while(i!=rear){
            printf("%d  ",queue[i]);
            i = (i+1)%max;
        }
        printf("%d  ]\n", queue[i]);
    }
}



int main()
{
    printf("\nEnter the size of queue: ");
    scanf("%d", &max);
    queue = (int *)malloc(max * sizeof(int));
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