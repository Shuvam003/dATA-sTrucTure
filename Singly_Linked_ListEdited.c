#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL;
int data;
int count = 0;

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
        printf("\nEnter Data:");
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = head;
        head = newnode;
        printf("Node inserted at position: 1\nData: %d", data);
        count++;
        return;
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
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        count++;
        printf("Node inserted at position: %d\nData: %d", count, data);
        return;
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
        printf("\nEnter the position where you want to insert the node: ");
        scanf("%d", &pos);
        if (pos > 0 && pos <= count + 1)
        {
            printf("Enter data: ");
            scanf("%d", &data);
            newnode->data = data;
            newnode->next = NULL;
            if (head == NULL || pos <= 1)
            {
                newnode->next = head;
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
                temp->next = newnode;
            }
            count++;
            printf("Node inserted at position: ");
            if (pos <= 1 || head == NULL)
                printf("1");
            else if (pos < count)
                printf("%d", pos);
            else
                printf("%d", count);
            printf("\nData: %d", data);
            return;
        }
        else
        {
            printf("\nInvalid Position...");
            return;
        }
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
        head = head->next;
        free(temp);
        printf("\nNode has been deleted at position: 1\nData: %d", data);
        count--;
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
        data = temp->data;
        if (temp == head)
            head = NULL;
        else
            ptr->next = NULL;
        free(temp);
        printf("\nNode has been deleted at position: %d\nData: %d", count, data);
        count--;
    }
}

void deleterandom()
{
    if (head != NULL)
    {
        int pos;
        printf("\nEnter position of the node you want to delete: ");
        scanf("%d", &pos);
        if (pos < 1)
        {
            printf("\nA Invalid Postion!! Delete process doesn't occured...");
            return;
        }
        else if (pos > 1)
        {
            node *temp = head;
            int n = 1;
            while (temp->next != NULL && n < pos - 1)
            {
                temp = temp->next;
                n++;
            }
            if (n == pos - 1 && temp->next != NULL)
            {
                node *ptr = temp->next;
                temp->next = ptr->next;
                data = ptr->data;
                free(ptr);
                count--;
                printf("Node has been deleted at position: %d\nData: %d", pos, data);
                return;
            }
            else
            {
                printf("A Invalid Postion!! Delete process doesn't occured...");
                return;
            }
        }
        else
        {
            node *temp = head;
            data = head->data;
            head = head->next;
            free(temp);
            count--;
            printf("Node has been deleted at position: 1\nData: %d", data);
            return;
        }
    }
    else
    {
        printf("\nList is empty...");
        return;
    }
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
        printf("\nEntire Linked List has been deleted...");
        count = 0;
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
        while (temp != NULL)
        {
            printf("%d  ", temp->data);
            temp = temp->next;
        }
        printf("]");
    }
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
            lastinsert();\
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