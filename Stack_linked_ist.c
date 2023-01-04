#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *head;
int max;
int top, data;

void push();
void pop();
void peek();
int isEmpty();
int isFull();

int main(){
    read:
    int choice=1;
    head = NULL;
    top =0;
    printf("\nEnter the capacity of stack: ");
    scanf("%d",&max);
    while(choice!=4){
        printf("\n----Main Menu----\n\n1.Push.\n2.Pop.\n3.Show the top element.\n4.Exit.\n5.Create a new stack. \n\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
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
                printf("\nCode Exited successfully...\n");
                exit(0);
            case 5:
                while(head!=NULL){
                    node *temp = head;
                    head = head->next;
                    free(temp);
                }
                printf("\nYou stack memory is clear...\n");
                goto read;
                break;
            default:
                printf("\nInvallid choice...\n");
        }
    }
}

int isEmpty(){
    if(top == 0)
        return 1;
    else
        return 0;
}

int isFull(){
    if(top == max)
        return 1;
    else
        return 0;
}

void push(){
    if(isFull()){
        printf("\nStack Overflow...\n");
        return;
    }
    node *newnode = (node*)malloc(sizeof(node));
    if(newnode == NULL){
        printf("\nStack Overflow...\n");
        return;
    }
    printf("\nEnter value: ");
    scanf("%d", &data);
    newnode->data = data;
    newnode->next = head;
    head = newnode;
    top++;
    printf("\nOne data is pushed.\nData: %d\n",data);
}

void pop(){
    if(isEmpty()){
        printf("\nStack Underflow...\n");
        return;
    }
    node *temp = head;
    data = temp->data;
    head = head->next;
    if(head != NULL)
        free(temp);
    top--;
    printf("\nOne Data is popped\nData: %d\n", data);
}

void peek(){
    if(isEmpty()){
        printf("\nStack is empty...\n");
        return;
    }
    else{
        printf("\nTop element of the stack: %d\n",head->data);
    }
}
