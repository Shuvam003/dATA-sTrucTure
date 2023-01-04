#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;
node *head = NULL;
int count = 0;
void createRandomList(){
    int n, i;
    printf("\nEnter how many node you need in the list: ");
    scanf("%d",&n);
    printf("\nEnter the data in linklist: ");
    for(i = 0; i<n; i++){
        int data;
        node *ptr=(node*)malloc(sizeof(node));
        scanf("%d",&data);
        ptr->data = data;
        ptr->next = NULL;
        if(i == 0){
            ptr->next = head;
            head = ptr;
        }
        else{
            node *temp = head;
            while (temp -> next != NULL){
                temp = temp -> next;
            }  
            temp->next = ptr;
        }
        count++;
    }
}
void pointer(node **head_add){
    printf("\n%d  %d  %d  %d  %d  %d  %d  %d  %d  %d\n",
    head_add,head,&head,&head_add,*head,&(*head_add),*(&head_add),&(*head_add),&(head->next),&((*head_add)->next));
}
//head_add = &head = *head = &(head->next)
int main(){
    int choice;
    while(choice!=3){
        printf("\n-------->Main Menu<--------\n");
        printf("\n1.Create a random list\n2.Check pointer\n3.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                if(head == NULL)
                    createRandomList();
                else
                    printf("Random list can create just for one time when no list is create. Try another choice!!!\n");
                break;
            case 2:
                pointer(&head);
                break;
            case 3:
                printf("\nCode Exit Successfully...\n\n");
                exit(0);
                break;
            default:
                printf("\nEnter a valid choice...\n");
        }
    }
    return 0;
}