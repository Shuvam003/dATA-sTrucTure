#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *front = NULL;
node *rear = NULL;
int max;
int count = 0;

int isEmpty(){
    if(front == NULL)
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

void enqueue(){
    if(!isFull()){
        int data;
        printf("\nEnter value: ");
        scanf("%d",&data);
        node *newnode = (node*)malloc(sizeof(node));
        newnode->data = data;
        if(front == NULL)
            front = rear = newnode;
        else{
            rear->next = newnode;
            rear = newnode;
        }
        count++;
        printf("\nA node inserted in queue.\nData: %d\n",data);
    }
    else
        printf("\nMaximum limit of queue is exceded...\n");
}

void dequeue(){
    if(!isEmpty()){
        int data = front->data;
        node *temp = front;
        front = front->next;
        count--;
        printf("\nA node deleted.\nData: %d\n",data);
    }
    else
        printf("\nQueue is Empty...\n");
}

void display(){
    if(!isEmpty()){
        node *temp = front;
        printf("\nValues in queue: [  ");
        while(temp!=NULL){
            printf("%d  ",temp->data);
            temp = temp->next;
        }
        printf("]\n");
    }
    else
        printf("\nQueue is empty...\n");
}
int main(){
	int choice;
    printf("\nEnter how many node you need in the queue: ");
    scanf("%d",&max);
	while(choice != 4){
	    printf("\n-------->Main Menu<--------\n\n1.Enqueue.\n2.Dequeue.\n3.Display.\n4.Exit.\n5.Increase limit of queue.\n\nEnter your choice: ");
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
            printf("\nCode exited successfully...\n");
	        exit(0);
        default:
            printf("\nYou enter a invalid choice...\n");
            break;
	    }
	}
    return 0;
}