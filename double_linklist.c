#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next, *prev;
}node;
node *head = NULL;
int count = 0;
void beginsert(){
    int data;
    printf("\nEnter value: ");
    scanf("%d",&data);
    node *temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = head;
    temp->prev = NULL;
    head = temp;
    count++;
    printf("\nNode enter successfully at beginning.\nData: %d\n",data);
}
void lastinsert(){
    int data;
    printf("\nEnter value: ");
    scanf("%d",&data);
    node *temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    if(head == NULL)
        head = temp;
    else{
        node *ttm = head;
        while(ttm->next != NULL)
            ttm = ttm->next;
        ttm->next = temp;
        temp->prev = ttm;
    }
    count++;
    printf("\nNode enter successfully at end.\nData: %d\n",data);
}
void randominsert()
{
    int data,pos;
    printf("\nEnter the position you want to insert the node: ");
    scanf("%d",&pos);
    printf("\nEnter value: ");
    scanf("%d",&data);
    node *temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        if(pos == 1){
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        else{
            node *ttm = head;
            int n = 1;
            while(ttm->next != NULL && n<pos-1)
            {
                ttm = ttm->next;
                n++;
            }
            temp->prev = ttm;
            temp->next = ttm->next;
            ttm->next = temp;
            if(temp->next!=NULL)
                temp->next->prev = temp;
        }
    }
    count++;
    if(pos<count)
        printf("\nNode enter successfully at position: %d",pos);
    else
        printf("\nNode enter successfully at position: %d",count);
    printf("\nData: %d\n",data);
}
void deletebegin(){
    if(head == NULL)
        printf("\nList is empty...\n");
    else{
        int data = head->data;
        node *ptr = head;
        head = head->next;
        head->prev = NULL;
        free(ptr);
        count--;
        printf("\nNode delete successfully at beginning\nData: %d\n",data);
    }
}
void deletelast(){
    if(head == NULL)
        printf("\nList is Empty...\n");
    else{
        int val;
        if(head->next == NULL){
            val = head->data;
            free(head);
            head = NULL;
        }
        else{
            node *ttm = head,*ptr;
            while(ttm->next!=NULL){
                ptr = ttm;
                ttm = ttm->next;
            }
            val = ttm->data;
            ptr->next = NULL;
            free(ttm);
        }
        count--;
        printf("\nNode delete successfully at end\nData: %d\n",val);
    }
}
void deleterandom(){
    if(head == NULL)
        printf("\nList is empty...\n");
    else{
        int pos;
        printf("\nEnter the position you want to delete: ");
        scanf("%d",&pos);
        node *ptr;
        if(pos == 1){
            ptr = head;

            head = head->next;
            head->prev = NULL;
            ptr->next = NULL;
            free(ptr);
        }
        else{
            node *ttm = head;
            int n = 1;
            while(ttm->next != NULL && n<pos){
                ttm = ttm->next; 
                n++;
            }
            if(ttm->next == NULL){
                printf("\nYou enter a invalid position!! So, delete process does not occured...\n");
                return;
            }
            // else{
            //     node *ptr = ttm->prev;
            //     ptr->next = ttm->next;
            //     if()
            // }
        }
    }
}
void display(){
    node *ttm = head;
    printf("\nValues of link list: [ ");
    while(ttm!=NULL){
        printf("%d ",ttm->data);
        ttm = ttm->next;
    }
    printf("]\nNumber of node in list: %d\n",count);
}
int main(){
    int choice;
    while(choice!=8)
    {
        printf("\n-------->Main Menu<--------\n");
        printf("\n1.Insert at begin.\n2.Insert at last.\n3.Insert at random position.\n4.Delete at begin.\n5.Delete at last.\n6.Delete at random position.\n7.Show.\n8.Exit.\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
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
                printf("\nCode exit successfully...\n");
                exit(0);
            default:
                printf("\nInvalid choice!!\n");
        }
    }
    return 0;
}