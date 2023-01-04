#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

int count = 0;
node *head = NULL;

void beginsert()
{
    int data;
    node *temp = (node *)malloc(sizeof(node));
    printf("\nEnter value: ");
    scanf("%d", &data);
    temp->data = data;
    temp->next = head;
    head = temp;
    count++;
    printf("\nNode Inserted at the beginning of the list with data: %d.\n", data);
}

int binarysearch(int high, int low, int data)
{
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
            return mid;
        else if (temp->data > data)
            return binarysearch(mid - 1, low, data);
        else
            return binarysearch(high, mid + 1, data);
    }
    return -1;
}

void display()
{
    if (head == NULL)
    {
        printf("\nList is not created yet!!\n");
    }
    else
    {
        node *temp;
        temp = head;
        printf("\n--Values in linklist--\n\n[ ");
        while (temp != NULL)
        {
            printf("%d  ", temp->data);
            temp = temp->next;
        }
        printf("]\n");
    }
}

int main()
{
    int choice;
    while (choice != 4)
    {
        printf("\n-------->Main Menu<--------\n");
        printf("\n1.Insert at begin\n2.Binary search a number\n3.Show\n4.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            beginsert();
            break;
        case 3:
            display();
            break;
        case 2:
            int d;
            printf("Enter data to be search: ");
            scanf("%d", &d);
            int pos = binarysearch(count, 1, d);
            if (pos != -1)
                printf("\nPosition: %d\n", pos);
            else
                printf("\nAbsent\n");
            break;
        case 4:
            printf("\nCode Exit Successfully...\n\n");
            exit(0);
            break;
        default:
            printf("\nEnter a valid choice...\n");
        }
    }
    return 0;
}