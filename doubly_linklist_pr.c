#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next, *prev;
}node;

node *head = NULL;

void beginsert(){
    int data;
    printf("\nEnter value: ");
    scanf("%d",&data);
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = head;
    newnode->prev = NULL;
    head = newnode;
    printf("\nNode inserted...\n");
}

void lastinsert(){
    int data;
    printf("\nEnter value:");
    scanf("%d",&data);
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    if(head == NULL)
        head = newnode;
    else{
        node *temp = head;
        while(temp->next!=NULL)
            temp = temp->next;
        temp->next = newnode;
        newnode->prev = temp;
    }
    printf("\node inserted...\n");
}

void randominsert(){
    int pos;
    printf("\nEnter the position you want to input: ");
    scanf("%d",&pos);
    if(pos<1 || head==NULL)
        beginsert();
    else{
        
    }
}
int main(){
    int choice;
    while(choice != 8){
        printf("\n---------->Main Menu<----------\n");
        printf("\n1.Insert at the beginning.");
        printf("\n2.Insert at the last.");
        printf("\n3.Insert at speified place.");
        printf("\n4.Delete beginning node");
        printf("\n5.Delete last node.");
        printf("\n6.Delete node at specified place.");
        printf("\n7.Show.");
        printf("\n8.Exit.");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                beginsert();
                break;
            case 2:
                lastinsert();
                break;
            case 3:
                randominsert();
                break;
            case 4:
                deletebegin();
                break;
            case 5:
                deletelast();
                break;
            case 6:
                deleterandom();
                break;
            case 7:
                display();
                break;
            case 8:
                printf("\nCode exited successfully...\n");
                exit(0);
            default:
                printf("\nEnter a valid choice...\n");
        }
    }
    return 0;
}