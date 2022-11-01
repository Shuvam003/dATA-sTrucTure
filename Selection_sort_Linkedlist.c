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

int main(){
    createRandomList();
    printf("\nList before sorting: ");
    display();
    selectionsort_data();
    printf("\nList after sorting: ");
    display();
    return 0;
}