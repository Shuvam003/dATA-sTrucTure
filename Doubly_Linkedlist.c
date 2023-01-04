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
void search();
void deletelist();

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
        newnode->next = head;
        if (head != NULL)
            head->prev = newnode;
        newnode->prev = NULL;
        head = newnode;
        count++;
        printf("\nNode is inserted at position: 1\nData: %d\n", data);
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
        printf("\nNode is inserted at position: %d\nData: %d\n", count, newnode->data);
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
        printf("\nEnter position node will be inserted: ");
        scanf("%d", &pos);
        printf("\nEnter data: ");
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
        printf("\nNode is inserted at position: ");
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
        printf("\nList is empty...\n");
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
        printf("\nNode has been deleted at position: 1\nData: %d\n", data);
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
        printf("\nNode has been deleted at position: %d\nData: %d\n", count + 1, data);
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
        int pos;
        printf("\nEnter the position you want to delete: ");
        scanf("%d", &pos);
        if (pos < 1)
        {
            printf("\nInvalid position...\n");
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
                    printf("\nInvalid position...\n");
                    return;
                }
            }
            printf("\nNode has been deleted at positoin: %d\nData: %d\n", pos, data);
            return;
        }
    }
}

void display()
{
    if (head == NULL)
    {
        printf("\nList is not created yet...\n");
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
        printf("%d  ]\n", temp->data);
        printf("\nValues in back order: [  ");
        while (temp != NULL)
        {
            printf("%d  ", temp->data);
            temp = temp->prev;
        }
        printf("]\n");
    }
}

void deletelist()
{
    if (head == NULL)
    {
        printf("\nList is empty...\n");
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
        printf("\nWhole List is deleted...\n");
    }
}

int main()
{
    int choice;
    while (choice != 9)
    {
        printf("\n\n-------->Main Menu<--------\n");
        printf("\n1.Insert at beginning.\n2.Insert at last.\n3.Insert at specific position.\n4.Delete at beginning.\n5.Delete at last.\n6.Delete at specified position.\n7.Show.\n8.Delete whole list.\n9.Exit.\n\n");
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
            deletelist();
            break;
        case 9:
            printf("\nCode exited successfully...\n\n");
            exit(0);
        default:
            printf("\nInvalid choice...\n");
        }
    }
    return 0;
}