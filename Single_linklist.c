#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
node *head = NULL;
int count = 0;
void createRandomList()
{
    int n, i;
    printf("\nEnter how many node you need in the list: ");
    scanf("%d", &n);
    printf("\nEnter the data in linklist: ");
    for (i = 0; i < n; i++)
    {
        int data;
        node *ptr = (node *)malloc(sizeof(node));
        scanf("%d", &data);
        ptr->data = data;
        ptr->next = NULL;
        if (i == 0)
        {
            ptr->next = head;
            head = ptr;
        }
        else
        {
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
        }
        count++;
    }
}
void beginsert()
{
    int data;
    node *temp = (node *)malloc(sizeof(node));
    printf("\nEnter value: ");
    scanf("%d", &data);
    temp->data = data;
    temp->next = head;
    head = temp;
    printf("\nNode Inserted at the beginning of the list with data: %d.\n", data);
    count++;
}
void lastinsert()
{
    int data;
    node *temp = (node *)malloc(sizeof(node));
    printf("\nEnter value: ");
    scanf("%d", &data);
    temp->data = data;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        node *ttm = head;
        while (ttm->next != NULL)
            ttm = ttm->next;
        ttm->next = temp;
        temp->next = NULL;
    }
    printf("\nNode Inserted at last of the list with data: %d.\n", data);
    count++;
}
void randominsert()
{
    int i = 1, pos, data;
    node *ptr, *temp;
    ptr = (node *)malloc(sizeof(node));
    printf("\nEnter the location where you want to insert: ");
    scanf("%d", &pos);
    printf("\nEnter value: ");
    scanf("%d", &data);
    ptr->data = data;
    ptr->next = NULL;
    temp = head;
    if (head == NULL)
    {
        head = ptr;
    }
    else
    {
        while (i < pos - 1 && temp->next != NULL)
        {
            temp = temp->next;
            i++;
        }
        ptr->next = temp->next;
        temp->next = ptr;
    }
    count++;
    if (pos <= count)
        printf("\nNode inserted at the position %d with value: %d\n", pos, data);
    else
    {
        printf("\nYou insert a invalid position!! So, node inserted at the END...");
        printf("\nSo Node inserted at the position %d with value: %d\n", count, data);
    }
}
void begindelete()
{
    if (head == NULL)
        printf("\nList is Empty...\n");
    else
    {
        node *ttm = head;
        int val = head->data;
        head = head->next;
        free(ttm);
        count--;
        printf("\nNode Delete at beginning with data: %d.\n", val);
    }
}
void lastdelete()
{
    if (head == NULL)
        printf("\nList is Empty...\n");
    else
    {
        int val;
        if (head->next == NULL)
        {
            val = head->data;
            head = NULL;
        }
        else
        {
            node *ttm = head, *ptr;
            while (ttm->next != NULL)
            {
                ptr = ttm;
                ttm = ttm->next;
            }
            val = ttm->data;
            ptr->next = NULL;
            free(ttm);
        }
        count--;
        printf("\nNode Delete at the end with data: %d.\n", val);
    }
}
void randomdelete()
{
    int val;
    if (head == NULL)
    {
        printf("\nList is Empty...\n");
    }
    else
    {
        int pos, i = 1;
        printf("\nEnter the position where you want to delete: ");
        scanf("%d", &pos);
        node *ptr, *ttm = head;
        if (pos == 1)
        {
            ptr = head;
            head = head->next;
            val = ptr->data;
            free(ptr);
        }
        else
        {
            while (i < pos && ttm != NULL)
            {
                ptr = ttm;
                ttm = ttm->next;
                i++;
            }
            if (ttm == NULL)
            {
                printf("\nYou enter a invalid position!! So, delete process does not occured...\n");
                return;
            }
            ptr->next = ttm->next;
            val = ttm->data;
            free(ttm);
        }
        printf("\nNode Delete at the position %d with data: %d.\n", pos, val);
        count--;
    }
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
void linearsearch()
{
    if (head == NULL)
    {
        printf("\nList is Empty...\n");
    }
    else
    {
        int a, i = 0, flag = 0;
        node *ttm = head;
        printf("\nEnter number you want to search: ");
        scanf("%d", &a);
        while (ttm != NULL)
        {
            i++;
            if (ttm->data == a)
            {
                printf("\n%d is present at position %d\n", a, i);
                flag = 1;
            }
            ttm = ttm->next;
        }
        if (flag == 0)
            printf("\n%d is not present in the list.\n", a);
    }
}
void deleteWholeList()
{
    node *temp = head;
    node *ptr = NULL;
    while (temp != NULL)
    {
        ptr = temp;
        temp = temp->next;
        free(ptr);
    }
    head = NULL;
    printf("\nWhole list is deleted...\n");
    count = 0;
}
int binarysearch_recursion(int a, int low, int high)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;
        int i = 1;
        node *temp = head;
        while (temp->next != NULL && i < mid)
        {
            temp = temp->next;
            i++;
        }
        if (temp->data == a)
            return mid;
        else if (temp->data < a)
            return binarysearch_recursion(a, mid + 1, high);
        else
            return binarysearch_recursion(a, low, mid - 1);
    }
    else
        return -1;
}
void binarysearch()
{
    if (head == NULL)
    {
        printf("\nList is Empty...\n");
    }
    else
    {
        int n = 0;
        node *ttm = head;
        while (ttm->next != NULL)
        {
            node *ptr = ttm->next;
            while (ptr != NULL)
            {
                if (ttm->data >= ptr->data)
                {
                    n = 1;
                }
                ptr = ptr->next;
            }
            ttm = ttm->next;
        }
        if (n == 0)
        {
            int a;
            printf("Enter Number you want to search: ");
            scanf("%d", &a);
            int result = binarysearch_recursion(a, 1, count);
            if (result == -1)
            {
                printf("\n%d is not present at the list\n", a);
            }
            else
            {
                printf("\n%d is present at position: %d\n", a, result);
            }
        }
        else
            printf("\nData is not sorted in ascending order or Each data is not unique!! So, Binary searching is not possible...\n");
    }
}
void bubblesort_data()
{
    int swap, i;
    node *ptr, *temp = NULL;
    if (head == NULL)
    {
        printf("\nList is empty...\n");
        return;
    }
    do
    {
        swap = 0;
        ptr = head;
        while (ptr->next != temp)
        {
            if (ptr->data > ptr->next->data)
            {
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swap = 1;
            }
            ptr = ptr->next;
        }
        temp = ptr;
    } while (swap);
    printf("\nLink list sorted using Bubble Sort of data...\n");
}
void bubblesort_node()
{
    node **head_add = &head;
    int swap;
    node **temp, *ptr1, *ptr2;
    if (*head_add == NULL)
    {
        printf("\nList is empty...\n");
    }
    else
    {
        do
        {
            swap = 0;
            temp = head_add;
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
        printf("\nLink list sorted using Bubble Sort of node...\n");
    }
}
void selectionsort_data()
{
    if (head == NULL)
    {
        printf("\nList is empty...\n");
    }
    else
    {
        node *ttm;
        ttm = head;
        while (ttm != NULL)
        {
            node *temp = ttm->next;
            while (temp != NULL)
            {
                if (ttm->data > temp->data)
                {
                    int swap = ttm->data;
                    ttm->data = temp->data;
                    temp->data = swap;
                }
                temp = temp->next;
            }
            ttm = ttm->next;
        }
        printf("\nLink list sorted using Selection Sort of data...\n");
    }
}
void reverse_list()
{
    node *temp = head, *ttm = NULL, *ptr = NULL;
    if (head == NULL)
    {
        printf("\nList is empty...\n");
    }
    else
    {
        while (temp != NULL)
        {
            ttm = temp->next;
            temp->next = ptr;
            ptr = temp;
            temp = ttm;
        }
        head = ptr;
        printf("\nLink list is reverse...\n");
    }
}
int main()
{
    int choice;
    while (choice != 17)
    {
        printf("\n-------->Main Menu<--------\n");
        printf("\n1.Create a random list\n2.Insert at begin\n3.Insert al last\n4.Enter at random position\n5.Delete at begin\n6.Delete at last\n7.Delete at random position\n8.Delete whole list\n9.Show\n10.Show number of node\n11.Linear search of a number\n12.Binary search a number\n13.Bubble Sort through swapping data\n14.Bubble sort through swapping nodes\n15.Selection sort through swapping node\n16.Reverse the list\n17.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (head == NULL)
                createRandomList();
            else
                printf("Random list can create just for one time when no list is create. Try another choice!!!\n");
            break;
        case 2:
            beginsert();
            break;
        case 3:
            lastinsert();
            break;
        case 4:
            randominsert();
            break;
        case 5:
            begindelete();
            break;
        case 6:
            lastdelete();
            break;
        case 7:
            randomdelete();
            break;
        case 8:
            deleteWholeList();
            break;
        case 9:
            display();
            break;
        case 10:
            printf("\nNumber of node in the list: %d\n", count);
            break;
        case 11:
            linearsearch();
            break;
        case 12:
            if (head != NULL)
            {
                int d;
                printf("Enter data to be search: ");
                scanf("%d", &d);
                int pos = binarysearch_recursion(d, 1, count);
                ;
                if (pos != -1)
                    printf("\nPosition: %d\n", pos);
                else
                    printf("\nAbsent\n");
            }
            else
                printf("\nList is empty...\n");
            break;
        case 13:
            bubblesort_data();
            break;
        case 14:
            bubblesort_node();
            break;
        case 15:
            selectionsort_data();
            break;
        case 16:
            reverse_list();
            break;
        case 17:
            printf("\nCode Exit Successfully...\n\n");
            exit(0);
            break;
        default:
            printf("\nEnter a valid choice...\n");
        }
    }
    return 0;
}