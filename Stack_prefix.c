#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define max 100
char stack[100];
int top = -1;

int isEmpty();
int isFull();
void push(char x);
char pop();
int priority(char x);
int isOperator(char x);
void infix_prefix(char *e);
void revstr(char *x);
int str_len(char *ptr);
char prefix[100];
int i = -1;

int main()
{
    char exp[100];
    int flag;
    do
    {
        printf("\nEnter a expression: ");
        scanf("%s", exp);
        flag = 0;
        char *e;
        e = exp;
        while (*e != '\0')
        {
            if (!isalnum(*e) && *e != '^' && *e != '*' && *e != '/' && *e != '+' && *e != '-' && *e != '(' && *e != ')')
            {
                printf("\nYour enter expression is invalid...\n");
                flag = 1;
                break;
            }
            e++;
        }
    } while (flag);
    revstr(exp);
    printf("\nAbove expression in prefix notation: ");
    infix_prefix(exp);
    printf("\n");
    return 0;
}

int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if (top == max - 1)
        return 1;
    else
        return 0;
}

void push(char x)
{
    if (isFull())
        printf("\nStack is Overflow...\n");
    else
        stack[++top] = x;
}

char pop()
{
    if (isEmpty())
        printf("\nStack is Empty...\n");
    else
        return stack[top--];
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

int isOperator(char x)
{
    if (x == '^' || x == '*' || x == '/' || x == '+' || x == '-' || x == '(' || x == ')')
        return 1;
    else
        return 0;
}

void infix_prefix(char *e)
{
    while (*e != '\0')
    {
        if (*e == ')')
            push(*e);
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
            while (stack[top] == '^')
            {
                prefix[++i] = pop();
            }
            push(*e);
        }
        else
        {
            while (priority(*e) < priority(stack[top]))
                prefix[++i] = pop();
            push(*e);
        }
        e++;
    }
    while (top != -1)
    {
        prefix[++i] = pop();
    }
    revstr(prefix);
    printf("%s", prefix);
}

void revstr(char *st)
{
    int len, i;
    char *start, *end, temp;
    len = str_len(st);
    start = st;
    end = st;
    for (i = 0; i < len - 1; i++)
        end++;
    for (i = 0; i < len / 2; i++)
    {
        temp = *end;
        *end = *start;
        *start = temp;
        start++;
        end--;
    }
}

int str_len(char *ptr)
{
    int i = 0;
    while (*ptr != '\0')
    {
        i++;
        ptr++;
    }
    return i;
}