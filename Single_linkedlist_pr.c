#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

int count = 0;
node *head = NULL;

void beginsert(){
    int data;
    node *newnode = (node*)malloc(sizeof(node));
    printf("\nEnter value: ");
    scanf("%d",&data);
    newnode->data = data;
    newnode->next = head;
    head = newnode;
    count++;
    printf("\nNode inserted at position: 1\nData: %d\n",data);
}
void lastinsert(){
    int data;
    printf("\nEnter value: ");
    scanf("%d",&data);
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    if(head == NULL){
        head = newnode;
    }
    else{
        node *temp = head;
        while(temp -> next!=NULL)
            temp = temp->next;
        temp->next = newnode;
    }
    count++;
    printf("\nNode inserted at the position: %d\nData: %d\n",count,data);
}
void randominsert(){
    int data, pos;
    printf("\nEnter the position you want to insert the node: ");
    scanf("%d",&pos);
    printf("\nEnter value: ");
    scanf("%d",&data);
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    if(head==NULL){
        head = newnode;
        printf("\nNode inserted at the position: 1\n");
        count++;
    }
    else{
        if(pos<=1){
            newnode->next = head;
            head = newnode;
        }
        else{
            node *temp = head;
            int n = 1;
            while(n<pos-1 && temp->next != NULL){
                temp = temp->next;
                n++;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
        count++;
        if(pos>count)
            printf("\nNode inserted at positon: %d\n",count);
        else if(pos<1)
            printf("\nNode inserted at position: 1\n");
        else
            printf("\nNode inserted at position: %d\n",pos);
    }
    printf("Data: %d\n",data);
}
void deletebegin(){
    if(head == NULL)
        printf("\nList is not created yet...\n");
    else{
        int data;
        node *temp = head;
        data = temp->data;
        head = head->next;
        free(temp);
        count--;
        printf("\nNode deleted at position: 1\nData: %d\n",data);
    }
}
void deletelast(){
    int data;
    if(head == NULL)
        printf("\nList is not created yet...\n");
    else if(head->next == NULL){
        data = head->data;
        head=NULL;
        printf("\nNode deleted at position: 1\nData: %d\n",data);
        count--;
    }
    else{
        node *temp = head, *ptr;
        while(temp->next->next!=NULL){
            temp = temp->next;
        }
        ptr = temp->next;
        data = ptr->data;
        temp->next = NULL;
        free(ptr);
        printf("\nNode deleted at position: %d\nData: %d\n",count,data);
        count--;
    }
}
void deleterandom(){
    if(head == NULL)
        printf("\nList is not created yet...\n");
    else{
        int pos;
        printf("\nEnter the position of node you want to delete: ");
        scanf("%d",&pos);
        if(pos == 1)
            deletebegin();
        else if(pos<1)
            printf("\nYou enter a invalid position...\n");
        else{
            node *temp = head;
            int n=1;
            while(temp->next!=NULL && n<pos-1){
                temp = temp->next;
                n++;
            }
            if(temp->next!=NULL){
                node *ptr = temp->next;
                temp->next = ptr->next;
                int data = ptr->data;
                free(ptr);
                count--;
                printf("\nNode deleted at position: %d\nData: %d\n",pos,data);
            }
            else
                printf("\nYou Enter a invalid position...\n");
        }
    }
}
void display(){
    if(head == NULL)
        printf("\nList is not created yet...\n");
    else{
        node *temp = head;
        printf("\nValues in linked list: [ ");
        while(temp != NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("]\n");
    }
}
void search(){
    int data,n = 1, flag = 0;
    printf("\nEnter search data: ");
    scanf("%d",&data);
    node *temp=head;
    while(temp!=NULL){
        if(temp->data == data){
            printf("\n%d is present at position: %d\n",data, n);
            flag = 1;
        }
        n++;
        temp = temp->next;
    }
    if(flag == 0)
        printf("\n%d is absent at linked list...\n",data);
}
void bubblesort(){
    if(head == NULL)
        printf("\nList is empty...\n");
    else{
        node **head_add = &head;
        int swap;
        node **temp;
        do{
            swap = 0;
            temp = head_add;
            while((*temp)->next != NULL){
                if((*temp)->data>(*temp)->next->data){
                    swap = 1;
                    node *ptr1 = *temp, *ptr2 = (*temp)->next;
                    ptr1->next = ptr2->next;
                    ptr2->next = ptr1;
                    *temp = ptr2;
                }
                temp = &((*temp)->next);
            }
        }while(swap);
        printf("\nLinked list is sorted using Bubble Sort of node...\n");
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
        printf("\n9.Search.\n");
        printf("10.Bubble sort of node.\n");
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
            case 9:
                search();
                break;
            case 10:
                bubblesort();
                break;
            default:
                printf("\nEnter a valid choice...\n");
        }
    }
    return 0;
}