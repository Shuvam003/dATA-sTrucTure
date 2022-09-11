#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int coefficient;
    int power;
    struct node *next;
} node;

node *head = NULL;

void addNode()
{
    int power, coef;
    printf("\nEnter the degree of x: ");
    scanf("%d", &power);
    printf("\nEnter coefficient of x: ");
    scanf("%d", &coef);
    node *new = (node *)malloc(sizeof(node));
    new->power = power;
    new->coefficient = coef;
    new->next = NULL;
    if (head != NULL)
    {
        if (power < head->power)
        {
            node *temp = head;
            node *ptr = head;
            while (power < temp->power && temp->next != NULL)
            {
                ptr = temp;
                temp = temp->next;
            }
            if (power != temp->power)
            {
                new->next = ptr->next;
                ptr->next = new;
            }
            else
            {
                printf("\nYou already enter the coefficient of x^%d...\n", new->power);
                free(new);
                return;
            }
        }
        else if (power == head->power)
        {
            printf("\nYou already enter the coefficient of x^%d...\n", new->power);
            free(new);
            return;
        }
        else
        {
            new->next = head;
            head = new;
        }
    }
    else
    {
        head = new;
    }
}

void printpoly()
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->coefficient != 0)
        {
            if (temp->coefficient != 1)
                printf("%d", temp->coefficient);
            else
            {
                if (temp->power == 0)
                    printf("1");
            }
            if (temp->power != 0)
            {
                if (temp->power == 1)
                    printf("x");
                else
                    printf("x^%d", temp->power);
            }
        }
        if (temp->next != NULL)
            if (temp->coefficient != 0)
                printf(" + ");
        temp = temp->next;
    }
}

void deletelist()
{
    node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    head = NULL;
}
int main()
{
    char ch = 'y';
    while (ch == 'y' || ch == 'Y')
    {
        addNode();
        printf("\nAny more term((y/Y for YES)  /  (N/n for NO)): ");
        scanf("\n%c", &ch);
        if (ch == 'N' || ch == 'n')
            break;
    }
    printpoly();
    deletelist();
    return 0;
}