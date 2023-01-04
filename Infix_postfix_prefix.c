#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char prefix[100];

typedef struct node
{
    char data;
    struct node *next;
} node;

node *head = NULL;
int top = -1;

int isEmpty()
{
    if (head == NULL)
    {
        printf("\nUNDERFLOW...");
        return 1;
    }
    return 0;
}

void push(char x)
{
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL)
    {
        printf("\nOVERFLOW...");
        return;
    }
    newnode->data = x;
    newnode->next = head;
    head = newnode;
    top++;
}

char pop()
{
    if (!isEmpty())
    {
        char data = head->data;
        node *temp = head;
        head = head->next;
        free(temp);
        top--;
        return data;
    }
}

int is_operator(char x)
{
    if (x == '^' || x == '*' || x == '/' || x == '+' || x == '-' || x == '(' || x == ')')
        return 1;
    else
        return 0;
}

char peek()
{
    if (head == NULL)
        return '#';
    else
        return head->data;
}

void revstr(char *str)
{
    int len;
    int start, end;
    char temp;
    len = strlen(str);
    start = 0;
    end = len - 1;
    for (int i = 0; i < len / 2; i++)
    {
        temp = str[end];
        str[end] = str[start];
        str[start] = temp;
        start++;
        end--;
    }
}

int priority(char x)
{
    if (x == '^')
        return 3;
    else if (x == '*' || x == '/')
        return 2;
    else if (x == '+' || x == '-')
        return 1;
    else
        return 0;
}

int associatvity_righttoleft(char x)
{
    if (x == '^')
        return 1;
    else
        return 0;
}

void Infix_Postfix(char *e)
{
    while (*e != '\0')
    {
        if (isalnum(*e))
        {
            printf("%c ", *e);
        }
        else if (*e == '(')
            push(*e);
        else if (*e == ')')
        {
            char x;
            while ((x = pop()) != '(')
            {
                printf("%c ", x);
            }
        }
        else
        {
            while (priority(*e) <= priority(peek()))
            {
                if (associatvity_righttoleft(*e))
                    break;
                else
                    printf("%c ", pop());
            }
            push(*e);
        }
        e++;
    }
    while (top != -1)
    {
        printf("%c ", pop());
    }
}

void infix_prefix(char *e)
{
    int i = -1;
    while (*e != '\0')
    {
        if (*e == ')')
        {
            push(*e);
        }
        else if (*e == '(')
        {
            char x;
            while ((x = pop()) != ')')
            {
                prefix[++i] = x;
            }
        }
        else if (isalnum(*e))
        {
            prefix[++i] = *e;
        }
        else if (*e == '^')
        {
            while (peek() == '^')
            {
                prefix[++i] = pop();
            }
            push(*e);
        }
        else if (is_operator(*e))
        {
            while (priority(*e) < priority(peek()))
                prefix[++i] = pop();
            push(*e);
        }
        else
            return;
        e++;
    }
    while (top != -1)
    {
        prefix[++i] = pop();
    }
    revstr(prefix);
    printf("%s", prefix);
}

int main()
{
    char exp[100];
    int flag;
    do
    {
        printf("\nEnter a equation: ");
        scanf("%s", exp);
        flag = 0;
        char *e;
        e = exp;
        int cop = 0, ccp = 0;
        printf("\nEquation in INFIX NOTATION: ");
        while (*e != '\0')
        {
            printf("%c", *e);
            if (*e == '(')
            {
                ++cop;
            }
            if (*e == ')')
            {
                ++ccp;
            }
            if (!isalnum(*e) && *e != '^' && *e != '*' && *e != '/' && *e != '+' && *e != '-' && *e != '(' && *e != ')')
            {
                printf("\nYour enter equation is invalid...\n");
                flag = 1;
                break;
            }
            e++;
        }
        if (cop != ccp)
        {
            printf("\nYour enter equation is invalid.\n");
            flag = 1;
        }
    } while (flag);
    printf("\nAbove equation in POSTFIX NOTATION: ");
    Infix_Postfix(exp);
    revstr(exp);
    printf("\nAbove equation in PREFIX NOTATION: ");
    infix_prefix(exp);
    printf("\n");
    return 0;
}
