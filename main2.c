#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}node;
node *head=NULL;
void beginsert(){
    int data;
    node *temp;
    temp = (node*)malloc(sizeof(node));
    printf("\nEnter data: ");
    scanf("%d",&data);
    temp->data = data;
    temp->link = head;
    head = temp;
    printf("node inserted.");
}
void lastinsert(){
    int data;
    node *temp,*ttm;
    temp= (node*)malloc(sizeof(node));
    printf("Enter data: ");
    scanf("%d",&data);
    temp->data = data;
    if(head == NULL){
        temp->link= NULL;
        head = temp;
        printf("node inserted.");
    }
    else{
        ttm = head;
        while(ttm->link!=NULL){
            ttm = ttm->link;
        }
        ttm->link = temp;
        temp->link = NULL;
        printf("node inserted.");
    }
}
void randominsert(){
    int n=0,position,data;
    node *temp, *ttm;
    temp = (node*)malloc(sizeof(node));

    printf("\nEnter the location after which you want to input the data: ");
    scanf("%d",&position);
    if(position == 0){
    beginsert();
    }
    else{
        printf("Enter data: ");
        scanf("%d",&data);
        temp->data = data;
        ttm = head;
        while(ttm->link!=NULL&&n<position){
            ttm = ttm->link;
            n++;
        }
        temp->link=ttm->link;
        ttm->link = temp;
    }
    printf("node inserted.");
}

void display(){
    node *temp;
    temp = head;
    printf("\nData in the list: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->link;
    }
}
int main()
{
    int choice;
    while(choice!=5){
        printf("\n\n--------Menu--------\n\n1. Insert in begin\n2. Insert at last\n3. Insert at random position\n4. Show the list\n5. exit\nEnter your choice from the above menu: ");        scanf("%d",&choice);
        switch(choice){
            case 1:
            beginsert(); break;
            case 2:
            lastinsert(); break;
            case 3:
            randominsert(); break;
            case 4:
            display(); break;
            default:
            printf("\nEnter a valid number.");
        }
    }
}
