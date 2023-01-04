#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next, *prev;
} node;

node *head = NULL;
node *last = NULL;
int count = 0;
int data;

void beginsert();
void lastinsert();
void randominsert();
void deletebegin();
void deletelast();
void deleterandom();
void display();

void beginsert()
{
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL)
    {
        printf("\nOVERFLOW...");
        return;
    }
    else
    {
        printf("\nEnter data: ");
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = newnode;
        newnode->prev = newnode;
        if (head == NULL)
        {
            head = last = newnode;
        }
        else
        {
            newnode->next = head;
            newnode->prev = last;
            last->next = newnode;
            head->prev = newnode;
            head = newnode;
        }
        count++;
        printf("Node is inserted at position: 1\nData: %d", data);
    }
}

void lastinsert()
{
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL)
    {
        printf("\nOVERFLOW...");
        return;
    }
    else
    {
        printf("\nEnter data: ");
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = newnode;
        newnode->prev = newnode;
        if (head == NULL)
        {
            head = last = newnode;
        }
        else
        {
            newnode->next = head;
            newnode->prev = last;
            last->next = newnode;
            head->prev = newnode;
            last = newnode;
        }
        count++;
        printf("Node is inserted at position: %d\nData: %d", count, data);
    }
}

void randominsert()
{
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL)
    {
        printf("\nOVERFLOW...");
        return;
    }
    else
    {
        int pos;
        printf("\nEnter the position node will be inserted: ");
        scanf("%d", &pos);
        printf("Enter data: ");
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = newnode;
        newnode->prev = newnode;
        if (head == NULL)
            last = head = newnode;
        else if (pos <= 1)
        {
            newnode->next = head;
            newnode->prev = last;
            last->next = newnode;
            head->prev = newnode;
            head = newnode;
        }
        else
        {
            node *temp = head;
            int n = 1;
            while (temp->next != head && n < pos - 1)
            {
                temp = temp->next;
                n++;
            }
            newnode->next = temp->next;
            newnode->prev = temp;
            temp->next = newnode;
            newnode->next->prev = newnode;
            if (temp == last)
                last = newnode;
        }
        count++;
        printf("Node is inserted at position: ");
        if (pos <= 1)
            printf("1");
        else if (pos <= count)
            printf("%d", pos);
        else
            printf("%d", count);
        printf("\nData: %d", data);
    }
}

void deletebegin()
{
    if (head == NULL)
    {
        printf("\nList is empty...");
        return;
    }
    else
    {
        data = head->data;
        node *temp = head;
        if (head == last)
        {
            head = last = NULL;
        }
        else
        {
            head = head->next;
            head->prev = last;
            last->next = head;
        }
        free(temp);
        count--;
        printf("\nOne node has been deleted at position: 1\nData: %d", data);
    }
}

void deletelast()
{
    if (head == NULL)
    {
        printf("\nList is empty...");
        return;
    }
    else
    {
        node *temp = head;
        if (last == head)
            last = head = NULL;
        else
        {
            while (temp->next != last)
                temp = temp->next;
            last = temp;
            temp = temp->next;
            last->next = head;
            head->prev = last;
        }
        data = temp->data;
        free(temp);
        printf("\nOne node has been deleted at position: %d\nData: %d", count, data);
        count--;
    }
}

void deleterandom()
{
    if (head == NULL)
    {
        printf("\nList is empty...");
        return;
    }
    else
    {
        printf("\nEnter positon which you want to delete: ");
        int pos;
        scanf("%d", &pos);
        if (pos < 1)
        {
            printf("Invalid position...");
            return;
        }
        else if (pos == 1)
        {
            data = head->data;
            node *temp = head;
            if (head == last)
            {
                head = last = NULL;
            }
            else
            {
                head = head->next;
                head->prev = last;
                last->next = head;
            }
            free(temp);
            count--;
            printf("Node has been deleted at position: 1\nData: %d", data);
        }
        else
        {
            node *temp = head;
            int n = 1;
            while (temp->next != head && n < pos - 1)
            {
                temp = temp->next;
                n++;
            }
            if (n == pos - 1 && temp->next != head)
            {
                if (temp->next == last)
                    last = temp;
                node *ptm = temp->next;
                temp->next = temp->next->next;
                temp->next->prev = temp;
                data = ptm->data;
                free(ptm);
                count--;
                printf("Node has been deleted at position: %d\nData: %d", pos, data);
            }
            else
            {
                printf("Invalid position...");
                return;
            }
        }
    }
}

void display()
{
    if (head == NULL)
    {
        printf("\nList is empty...");
        return;
    }
    else
    {
        node *temp = head;
        printf("\nValues in linked list: [  ");
        do
        {
            printf("%d  ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("]");
    }
}

void deletelist()
{
    while (head != last)
    {
        node *temp = head;
        head = head->next;
        free(temp);
        ;
    }
    free(head);
    head = last = NULL;
    printf("\nEntire Linked List has been deleted...");
    count = 0;
}

int main()
{
    printf("\n-------->Main Menu<--------");
    printf("\n1.Insert at Beginning.               2.Insert at Last.\n3.Insert at a specified Index.       4.Delete at Beginning.\n5.Delete at Last.                    6.Delete at specified Index.\n7.Delete entire list                 8.Show.\n9.Exit.\n");
    int choice;
    while (choice != 9)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("You choose to INSERT a node at BEGINNING...");
            beginsert();
            display();
            break;
        case 2:
            printf("You choose to INSERT a node at LAST...");
            lastinsert();
            display();
            break;
        case 3:
            printf("You choose to INSERT a node at SPECIFIED INDEX...");
            randominsert();
            display();
            break;
        case 4:
            printf("You choose to DELETE a node at BEGINNING...");
            deletebegin();
            display();
            break;
        case 5:
            printf("You choose to DELETE a node at LAST...");
            deletelast();
            display();
            break;
        case 6:
            printf("You choose to DELETE a node at SPECIFIED INDEX...");
            deleterandom();
            display();
            break;
        case 7:
            printf("You choose to DELETE ENTIRE LIST...");
            deletelist();
            display();
            break;
        case 8:
            printf("You choose to DISPLAY ENTIRE LIST...");
            display();
            break;
        case 9:
            printf("\nCODE EXITED SUCCESSFULLY...\n");
            exit(0);
        default:
            printf("Invalid choice...");
        }
    }
    return 0;
}