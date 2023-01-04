#include<stdio.h>
#include<stdlib.h>

int *queue;
int max;
int rear = -1; 
int front = -1;
int count = 0;

int isEmpty(){
    if(count == 0)
        return 1;
    else
        return 0;
}

int isFull(){
    if(count == max)
        return 1;
    else 
        return 0;
}

void display() {
    if (isEmpty()){
        printf("\nQueue is Empty...\n");
    }
    else {
        int i;
        printf("\nValues in Queue: [  ");
        for (i = front; i != rear; i = (i + 1) % max) {
        printf("%d  ", queue[i]);
        }
        printf("%d  ]\n", queue[i]);
    }
}

void enqueue(){
    if(!isFull()){
        int data;
        printf("\nEnter value: ");
        scanf("%d",&data);
        rear = (rear+1)%max;
        queue[rear] = data;
        if(front == -1)
            front = 0;
        count++;
    }
    else
        printf("\nQueue reached it's maximum limit...\n");
}

void dequeue(){
    if(!isEmpty()){
        int data;
        data = queue[front];
        front = (front+1)%max;
        printf("\nOne item is deleted \nData: %d\n",data);
        count--;
    }
    else
        printf("\nQueue is Empty...\n");
}

int main(){
	int choice;
    printf("\nEnter how many node you need in the queue: ");
    scanf("%d",&max);
    queue = (int*)malloc(max*sizeof(int));
	while(choice != 4){
	    printf("\n-------->Main Menu<--------\n\n1.Enqueue.\n2.Dequeue.\n3.Display.\n4.Exit.\n\nEnter your choice: ");
	    scanf("%d",&choice);
	    switch(choice){
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
	        exit(0);
        default:
            printf("\nYou enter a invalid choice...\n");
            break;
	    }
	}
    return 0;
}
