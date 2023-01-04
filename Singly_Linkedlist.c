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
        printf("\nOVERFLOW...\n");
        return;
    }
    else
    {
        printf("\nEnter Data:");
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = head;
        head = newnode;
        printf("\nNode inserted at position: 1\nData: %d\n", data);
        count++;
        return;
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
        printf("\nNode inserted at position: %d\nData: %d\n", count, data);
        return;
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
        printf("\nEnter the position where you want to insert the node: ");
        scanf("%d", &pos);
        printf("\nEnter data: ");
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
        printf("\nNode inserted at position: ");
        if (pos <= 1 || head == NULL)
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
            printf("\nA Invalid Postion!! Delete process doesn't occured...\n");
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
                printf("\nNode has been deleted at position: %d\nData: %d\n", pos, data);
                return;
            }
            else
            {
                printf("\nA Invalid Postion!! Delete process doesn't occured...\n");
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
            printf("\nNode has been deleted at position: 1\nData: %d\n", data);
            return;
        }
    }
    else
    {
        printf("\nList is empty...\n");
        return;
    }
}

void linearsearch()
{
    if (head == NULL)
    {
        printf("\nList is empty...\n");
        return;
    }
    else
    {
        printf("\nEnter element you want to search: ");
        scanf("%d", &data);
        int n = 1;
        int flag = 0;
        node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == data)
            {
                printf("\n%d is present in list at positon: %d\n", data, n);
                flag = 1;
            }
            temp = temp->next;
            n++;
        }
        if (flag == 0)
            printf("\n%d is not present in the list...\n", data);
        return;
    }
}

void binarysearch()
{
    if (head == NULL)
    {
        printf("\nList is empty...\n");
        return;
    }
    else
    {
        printf("\nEnter element you want to search: ");
        scanf("%d", &data);
        int low = 1;
        int high = count;
        int flag = 0;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            node *temp = head;
            int n = 1;
            while (temp->next != NULL && n < mid)
            {
                temp = temp->next;
                n++;
            }
            if (temp->data == data)
            {
                printf("\n%d found at: %d\n", data, mid);
                flag = 1;
                break;
            }
            else if (temp->data > data)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        if (flag == 0)
        {
            printf("\n%d is not present in list...\n", data);
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
        while (temp != NULL)
        {
            printf("%d  ", temp->data);
            temp = temp->next;
        }
        printf("]");
    }
}

void bubblesort()
{
    if (head == NULL)
    {
        printf("\nList is empty...\n");
    }
    else
    {
        printf("\nList before Sorting: \n");
        display();
        int swap;
        node *ptr1, *ptr2;
        do
        {
            swap = 0;
            node **temp = &head;
            while ((*temp)->next != NULL)
            {
                if ((*temp)->data > (*temp)->next->data)
                {
                    swap = 1;
                    ptr1 = *temp;
                    ptr2 = (*temp)->next;
                    ptr1->next = ptr2->next;
                    ptr2->next = ptr1;
                    *temp = ptr2;
                }
                temp = &((*temp)->next);
            }
        } while (swap);
        printf("\n\nLinked list is sorted using Bubble Sort...\n");
        printf("\nList after Sorting: \n");
        display();
    }
}

int main()
{
    int choice;
    while (choice != 11)
    {
        printf("\n\n-------->Main Menu<--------");
        printf("\n1.Insert at beginning.\n2.Insert at last.\n3.Insert at specific position.\n4.Delete at beginning.\n5.Delete at last.\n6.Delete at specified position.\n7.Show.\n8.Linear search of a element.\n9.Binary search of a element.\n10.Bubble Sort of the list.\n11.Exit.\n\n");
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
            linearsearch();
            break;
        case 9:
            binarysearch();
            break;
        case 10:
            bubblesort();
            break;
        case 11:
            printf("\nCode exited successfully...\n");
            exit(0);
        default:
            printf("\nInvalid choice...\n");
        }
    }
    return 0;
}