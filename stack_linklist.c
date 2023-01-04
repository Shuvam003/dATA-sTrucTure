#include <stdio.h>  
#include <stdlib.h>  
void push();  
void pop();  
void display();  
typedef struct node   
{  
int val;  
struct node *next;  
}node;  
node *head;  
  
void main ()  
{  
    int choice=0;     
    printf("\n****Stack operations using linked list****\n");  
    printf("\n----------------------------------------------\n");  
    while(choice != 4)  
    {  
        printf("\nChose one from the below options...\n");  
        printf("\n1.Push\n2.Pop\n3.Show\n4.Exit");  
        printf("\n Enter your choice \n");        
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            {   
                push();  
                break;  
            }  
            case 2:  
            {  
                pop();  
                break;  
            }  
            case 3:  
            {  
                display();  
                break;  
            }  
            case 4:   
            {  
                printf("Exiting....");  
                break;   
            }  
            default:  
            {  
                printf("Please Enter valid choice \n");  
            }   
    };  
}  
}  
void push ()  
{  
    int val;  
    node *ptr = (node*)malloc(sizeof(node)); 
        printf("Enter the value");  
        scanf("%d",&val);  
        ptr->val = val;  
        ptr -> next = NULL;  
        if(head==NULL)  
        {
            head=ptr;  
        }   
        else   
        {
            ptr->next = head;  
            head=ptr; 
        }  
        printf("Item pushed is: %d",val);  
}  
void pop()  
{  
    int item;  
    node *ptr;  
    if (head == NULL)  
    {  
        printf("Underflow");  
    }  
    else  
    {  
        item = head->val;  
        ptr = head;  
        head = head->next;  
        free(ptr);  
        printf("Item popped is: %d",item);  
          
    }  
}  
void display()  
{  
    int i;  
    node *ptr;  
    ptr=head;  
    if(ptr == NULL)  
    {  
        printf("Stack is empty\n");  
    }  
    else  
    {  
        printf("Printing Stack elements \n");  
        while(ptr!=NULL)  
        {  
            printf("%d\n",ptr->val);  
            ptr = ptr->next;  
        }  
    }  
} 