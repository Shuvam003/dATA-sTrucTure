#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *head = NULL;
node *last = NULL;

// void find_last(){
//     if(head != NULL){
//         last = head;
//         while(last->next!=head){
//             last = last->next;
//         }
//     }
// }
void beginsert(){
    int data;
    printf("\nEnter data: ");
    scanf("%d",&data);
    node *temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    if(head == NULL){
        temp->next = temp;
        head = last = temp;
    }
    else{
        temp->next = head;
        last->next = temp;
        head = temp;
    }
    printf("\nNode Inserted\n");
}
void lastinsert(){
    int data;
    printf("\nEnter data: ");
    scanf("%d",&data);
    node *temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    if(head == NULL){
        temp->next = temp;
        head = last = temp;
    }
    else{
        last->next = temp;
        temp->next = head;
        last = temp;
    }
    printf("\nNode Inserted\n");
}
void randominsert(){
    int pos;
    printf("\nEnter the position where you want to insert the data: ");
    scanf("%d",&pos);
    if(pos==1){
        beginsert();
    }
    else{
        int data;
        printf("\nEnter data: ");
        scanf("%d",&data);
        node *temp = (node*)malloc(sizeof(node));
        temp->data = data;
        temp->next = NULL;
        if(head == NULL){
            temp->next = temp;
            head = last = temp;
        }
        else{
            int n = 1;
            node *ttm = head;
            while(n<pos-1 && ttm->next!=head){
                ttm = ttm->next;
                n++;
            }
            temp->next = ttm->next;
            ttm->next = temp;
            if(temp->next == head)
                last = temp;
        }
        printf("\nNode Inserted\n");
    }
}
void deletebegin(){
    if(head == NULL){
        printf("\nList is empty...\n");
    }
    else{
        if(head->next == head){
            head = last = NULL;
        }
        else{
            last->next = head->next;
            node *ttm = head;
            head = head->next;
            free(ttm);
        }
    }
}
void deletelast(){
    if(head == NULL){
        printf("\nList is empty...\n");
    }
    else{
        if(head->next = head){
            head = last = NULL;
        }
        else{
            node *ttm = head;
            while(ttm->next!=last){
                ttm = ttm->next;
            }
            ttm->next = head;
            free(last);
            last = ttm;
        }
    }
    printf("\nNode Deleted...\n");
}
void display(){
    node *temp = head;
    printf("\nValues in link list: [ ");
    while(temp!=last){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ]\n",temp->data);
}
int main(){
    int choice;
    while(choice!=8){
        //find_last();
        printf("\n-------->Main Menu<--------\n");
        printf("\n1.Insert at the begin.\n2,Insert at the last.\n3.Insert at specified place.\n4.Delete at begin.\n5.Delete at last.\n6.Delete at specified place.\n7.Show.\n8.Exit.\n");
        printf("Enter your choice: ");
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
            // case 6:
            //     deleterandom();
            //     break;
            case 7:
                display();
                break;
            case 8:
                printf("\nCode exit successfully...\n");
                exit(0);
            default:
                printf("\nYou enter a invalid choice!!\n");
        }
    }
    return 0;
}