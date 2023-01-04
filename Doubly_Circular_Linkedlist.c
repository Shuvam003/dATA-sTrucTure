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
        printf("\nOVERFLOW...\n");
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
        printf("\nNode is inserted at position: 1\nData: %d", data);
    }
}

void lastinsert()
{
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL)
    {
        printf("\nOVERFLOW...\n");
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
        printf("\nNode is inserted at position: %d\nData: %d", count, data);
    }
}

void randominsert()
{
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL)
    {
        printf("\nOVERFLOW...\n");
        return;
    }
    else
    {
        int pos;
        printf("\nEnter the position node will be inserted: ");
        scanf("%d", &pos);
        printf("\nEnter data: ");
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
        printf("\nNode is inserted at position: ");
        if (pos <= 1)
            printf("1");
        else if (pos <= count)
            printf("%d", pos);
        else
            printf("%d", count);
        printf("\nData: %d\n", data);
    }
}

void deletebegin()
{
    if (head == NULL)
    {
        printf("\nList is empty...\n");
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
        printf("\nOne node has been deleted at position: 1\nData: %d\n", data);
    }
}

void deletelast()
{
    if (head == NULL)
    {
        printf("\nList is empty...\n");
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
        free(temp);
        printf("\nOne node has been deleted at position: %d\nData: %d\n", count, data);
        count--;
    }
}

void deleterandom()
{
    if (head == NULL)
    {
        printf("\nList is empty...\n");
        return;
    }
    else
    {
        printf("\nEnter positon which you want to delete: ");
        int pos;
        scanf("%d", &pos);
        if (pos < 1)
        {
            printf("\nInvalid position...\n");
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
            printf("\nNode has been deleted at position: 1\nData: %d\n", data);
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
                printf("\nNode has been deleted at position: %d\nData: %d\n", pos, data);
            }
            else
            {
                printf("\nInvalid position...\n");
                return;
            }
        }
    }
}

void display()
{
    if (head == NULL)
    {
        printf("\nList is empty...\n");
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
        printf("]\n");
        printf("\nValues in linked list in backward: [  ");
        do
        {
            temp = temp->prev;
            printf("%d  ", temp->data);
        } while (temp != head);
        printf("]\n");
    }
}

int main()
{
    int choice;
    while (choice != 8)
    {
        printf("\n\n-------->Main Menu<--------\n");
        printf("\n1.Insert at beginning.\n2.Insert at last.\n3.Insert at specific position.\n4.Delete at beginning.\n5.Delete at last.\n6.Delete at specified position.\n7.Show.\n8.Exit.\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
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
            printf("\nCode exited successfully...\n\n");
            exit(0);
        default:
            printf("\nInvalid choice...\n");
        }
    }
    return 0;
}