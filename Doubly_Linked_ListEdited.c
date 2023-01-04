#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

node *head = NULL;
int data;
int count = 0;

void beginsert();
void lastinsert();
void randominsert();
void deletebegin();
void deletelast();
void deleterandom();
void display();
void deletelist();

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
        newnode->next = head;
        if (head != NULL)
            head->prev = newnode;
        newnode->prev = NULL;
        head = newnode;
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
        newnode->next = NULL;
        newnode->prev = NULL;
        if (head == NULL)
            head = newnode;
        else
        {
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->prev = temp;
        }
        count++;
        printf("Node is inserted at position: %d\nData: %d", count, newnode->data);
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
        printf("\nEnter position node will be inserted: ");
        scanf("%d", &pos);
        printf("Enter data: ");
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = NULL;
        newnode->prev = NULL;
        if (pos <= 1 || head == NULL)
        {
            newnode->next = head;
            if (head != NULL)
                head->prev = newnode;
            head = newnode;
        }
        else
        {
            node *temp = head;
            int n = 1;
            while (temp->next != NULL && n < pos - 1)
            {
                temp = temp->next;
                n++;
            }
            newnode->next = temp->next;
            newnode->prev = temp;
            if (temp->next != NULL)
                temp->next->prev = newnode;
            temp->next = newnode;
        }
        count++;
        printf("Node is inserted at position: ");
        if (pos <= 1)
            printf("1");
        else if (pos < count)
            printf("%d", pos);
        else
            printf("%d", count);
        printf("\nData: %d", data);
        return;
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
        node *temp = head;
        data = head->data;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
        count--;
        printf("\nNode has been deleted at position: 1\nData: %d", data);
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
        node *ptr = temp;
        while (temp->next != NULL)
        {
            ptr = temp;
            temp = temp->next;
        }
        ptr->next = NULL;
        data = temp->data;
        if (temp == head)
        {
            head = NULL;
        }
        free(temp);
        count--;
        printf("\nNode has been deleted at position: %d\nData: %d", count + 1, data);
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
        int pos;
        printf("\nEnter the position you want to delete: ");
        scanf("%d", &pos);
        if (pos < 1)
        {
            printf("Invalid position...");
            return;
        }
        else
        {
            node *temp = head;
            if (pos == 1)
            {
                data = head->data;
                head = head->next;
                if (head != NULL)
                    head->prev = NULL;
                free(temp);
                count--;
            }
            else
            {
                int n = 1;
                while (temp->next != NULL && n < pos)
                {
                    temp = temp->next;
                    n++;
                }
                if (n == pos)
                {
                    data = temp->data;
                    temp->prev->next = temp->next;
                    if (temp->next != NULL)
                        temp->next->prev = temp->prev;
                    free(temp);
                    count--;
                }
                else
                {
                    printf("Invalid position...");
                    return;
                }
            }
            printf("Node has been deleted at positoin: %d\nData: %d", pos, data);
            return;
        }
    }
}

void display()
{
    if (head == NULL)
    {
        printf("\nList is not created yet or deleted...");
        return;
    }
    else
    {
        node *temp = head;
        printf("\nValues in List: [  ");
        while (temp->next != NULL)
        {
            printf("%d  ", temp->data);
            temp = temp->next;
        }
        printf("%d  ]", temp->data);
    }
}

void reverse()
{
    node *temp = head;
    node *ttm = NULL;
    node *ptr;
    display();
    while (temp != NULL)
    {
        ptr = temp->next;
        temp->next = ttm;
        if (ttm != NULL)
            ttm->prev = temp;
        if (ptr != NULL)
            ptr->prev = ttm;
        ttm = temp;
        temp = ptr;
    }
    head = ttm;
    printf("\nLinked List has been reversed...");
    display();
}

void deletelist()
{
    if (head == NULL)
    {
        printf("\nList is empty...");
        return;
    }
    else
    {
        while (head != NULL)
        {
            node *temp = head;
            head = head->next;
            free(temp);
        }
        printf("\nWhole List is deleted...");
    }
}

int main()
{
    printf("\n-------->Main Menu<--------");
    printf("\n1.Insert at Beginning.               2.Insert at Last.\n3.Insert at a specified Index.       4.Delete at Beginning.\n5.Delete at Last.                    6.Delete at specified Index.\n7.Delete entire list                 8.Show.\n9.Reverse Linked List.               10.Exit.\n");
    int choice;
    while (choice != 10)
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
            printf("You choose to REVERSE ENTIRE LINKED LIST...");
            reverse();
            break;
        case 10:
            printf("\nCODE EXITED SUCCESSFULLY...\n");
            exit(0);
        default:
            printf("Invalid choice...");
        }
    }
    return 0;
}