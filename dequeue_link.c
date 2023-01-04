#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *head = NULL;
node *last = NULL;
int max, count = 0, data;

int isEmpty(){
    if(head == NULL){
        printf("\nQUEUE IS EMPTY...\n");
        return 1;
    }
    else return 0;
}

int isFull(){
    if(count == max){
        printf("\nQUEUE IS FULL...\n");
        return 1;
    }
    else return 0;
}

void insert_at_front(){
    if(!isFull()){
        node *newnode = (node*)malloc(sizeof(node));
        printf("\nEnter data: ");
        scanf("%d",&data);
        newnode->data = data;
        newnode->next = newnode;
        if(head == NULL)
        head = last = newnode;
        else{
            newnode->next = head;
            last->next = newnode;
            head = newnode;
        }
        count++;
        printf("\n%d has been ADDED at FRONT of QUEUE...\n", data);
    }
}

void insert_at_rear(){
    if(!isFull()){
        node *newnode = (node*)malloc(sizeof(node));
        printf("\nEnter data: ");
        scanf("%d",&data);
        newnode->data = data;
        newnode->next = newnode;
        if(head == NULL)
            head = last = newnode;
        else{
            newnode->next = head;
            last->next = newnode;
            last = newnode;
        }
        count++;
        printf("\n%d has been ADDED at REAR of QUEUE...\n", data);
    }
}

void delete_at_front(){
    if(!isEmpty()){
        data = head->data;
        node *temp = head;
        if(head == head->next)
        head = last = NULL;
        else{
            head = head->next;
            last->next = head;
        }
        free(temp);
        printf("\n%d has been REMOVED from FRONT of QUEUE...\n", data);
        count--;
    }
}

void delete_at_rear(){
    if(!isEmpty()){
        data = last->data;
        node *temp = head;
        if(head == head->next)
        head = last = NULL;
        else{
            while(temp->next!=last){
                temp = temp->next;
            }
            last = temp;
            temp = temp->next;
            last->next = head;
        }
        free(temp);
        count--;
        printf("\n%d has been REMOVED from REAR of QUEUE...\n", data);
    }
}

void display(){
    if(!isEmpty()){
        node *temp = head;
        printf("\nValues in queue:  [  ");
        do{
            printf("%d  ",temp->data);
            temp = temp->next;
        }while(temp != head);
        printf("]\n");
    }
}

int main()
{
    printf("\nEnter size of queue: ");
    scanf("%d", &max);
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
            ;
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