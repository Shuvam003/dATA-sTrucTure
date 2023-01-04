#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
}node;
node *head;

void init()
{
    head=NULL;
}
void insertfirst(int element)
{
    node *New;
    New=(node*)malloc(sizeof(node));
    New->value=element;
    New->next=NULL;
    New->next=head;
    head=New;
}
void print()
{
    if(head==NULL)
    {
        printf("list is empty\n");
        return;
    }
    node *cur=head;            
    int count;
    count=0;
    while(cur!=NULL)                  //the loop traverse until it gets any NULL node
    {
        printf("%d->",cur->value);    
        count++;                      //counts the number of nodes or elements present in list
        cur=cur->next;                //moves cur pointer to next node to check and get value
    }
    printf("NULL\n");
    printf("number of nodes %d\n",count);
}

void deleteitem(int ele)
{
    if(head==NULL)
        printf("list is empty and nothing to delete\n");
    node* cur=head;
    node* prev=NULL;
    while(cur->value!=ele)
    {
        prev=cur;
        cur=cur->next;
    }
    if(prev!=NULL)
        prev->next=cur->next;       //the address of next node after the node containing element to be deleted is assigned to the previous node of the node containing the element to be deleted
    free(cur);                      //memory of the structure cur is deallocated
}

int searchitem(int ele)
{
    node* temp ;
	temp = head;
	while (temp != 0)
	{
		if (temp->value == ele)
            return 1 ;          //element is found
		temp = temp->next;
	}
	return 0 ;
}

void insertlast(int ele)    //insert at the last of linked list
{
    node *New, *temp;
    New = (node*)malloc(sizeof(node));
    if(New== NULL)
    {
        printf("Unable to allocate memory.");
        return;
    }
    else
    {
        New->value = ele;
        New->next = NULL;
        temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = New;
        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}

void deletelast()   //delete the last element
{
    if(head==NULL)
    {
        printf("list is empty and nothing to delete\n");
    }
    node* cur=head;
    node* prev=NULL;
    while(cur->next!=NULL)
    {
        prev=cur;
        cur=cur->next;
    }
    if(prev->next!=NULL)
        prev->next=NULL;
    free(cur);
}

void deletefirst()    //delete the first element
{
    node* cur;
    if(head==NULL)
        printf("list is empty and nothing to delete\n");
    cur=head;
    head=head->next;
    free(cur);
}

void insertafter(int elem, int num)   //inserts element for any given element present in linked list
{
    node* New;
    New=(node*)malloc(sizeof(node));
    New->value=elem;
    New->next=NULL;
    node* prev=head;
    while(prev->value!=num)
    {
        prev=prev->next;
    }
    New->next=prev->next;
    prev->next=New;
}

void printReverse(node* head)    //print the linked list in reverse way using recursion
{
    if (head == NULL)
       return;
    printReverse(head->next);
    printf("%d->", head->value);
}

void reverselist()    //reverse the linked list
{
    node* prev=NULL;
    node* cur=head;
    node* nxt;
    while(cur!=NULL)
    {
        nxt=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nxt;
    }
    head=prev;      //points the head pointer to prev as it the new head or beginning in reverse list
}

void sum()    //sum of elements of the linked list
{
    int s;
    node *cur=head;
    s=0;
    while(cur!=NULL)
    {
        s+=cur->value;
        cur=cur->next;
    }
    printf("Sum of elements is %d\n",s);
}


int main()
{
    init();

    int ch,element;
    while(1)
    {
        printf("\n1. Insert new item. 2. Delete item. 3. Search item. 4. Insert Last. 5. Print. 6.Delete Last 7.Delete First 8.Insert After 9.Print Linked List in Reverse way. 10.Sum 11.Make the linked list reverse 12.Exit\n--------------------------------------------------------------------------------------\n");
        printf("enter choice of input: ");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("enter element to list: ");
            scanf("%d",&element);
            insertfirst(element);
        }
        else if(ch==2)
        {
            int de;
            printf("enter element to delete ");
            scanf("%d",&de);
            deleteitem(de);
        }
        else if(ch==3)
        {
            int se,reply;
            printf("enter element to search ");
            scanf("%d",&se);
            reply=searchitem(se);
            if(reply==1)
                printf("element found\n");
            else
                printf("element not found\n");
        }
        else if(ch==4)
        {
            int le;
            printf("enter element to insert at last ");
            scanf("%d",&le);
            insertlast(le);
        }
        else if(ch==5)
        {
            print();
        }
        else if(ch==6)
        {
            deletelast();
        }
        else if(ch==7)
        {
            deletefirst();
        }
        else if(ch==8)
        {
            int ie,p;
            printf("enter element to insert: ");
            scanf("%d",&ie);
            printf("enter after which element to insert: ");
            scanf("%d",&p);
            insertafter(ie,p);
        }
        else if(ch==9)
        {
            printReverse(head);
        }
        else if(ch==10)
        {
            sum();
        }
        else if(ch==11)
        {
            reverselist();
        }
        else if(ch==12)
            return 0;
        else
            return 0;
    }
    return 0;
}