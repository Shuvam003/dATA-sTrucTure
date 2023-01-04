#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define max 100
char stack[max];
int top = -1;

int isEmpty()
{
    if (top == -1)
    {
        printf("\nSTACK IS EMPTY...\n");
        return 1;
    }
    else
        return 0;
}

int isFull()
{
    if (top == max - 1)
    {
        printf("\nSTACK IS FULL...\n");
        return 1;
    }
    else
        return 0;
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
    if (x == '*' || x == '/' || x == '+' || x == '-' || x == '^')
        return 1;
    else
        return 0;
}

void push(char x)
{
    if (!isFull())
    {
        stack[++top] = x;
    }
}

char pop()
{
    if (!isEmpty())
    {
        return stack[top--];
    }
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

void infix_prefix(char *e)
{
    char prefix[100];
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
            while (stack[top] == '^')
            {
                prefix[++i] = pop();
            }
            push(*e);
        }
        else if (isOperator(*e) && *e != '^')
        {
            while (priority(*e) < priority(stack[top]))
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
        printf("\nEnter a expression: ");
        scanf("%s", exp);
        flag = 0;
        char *e;
        e = exp;
        int cop = 0, ccp = 0;
        printf("\nEquation in Infix Notation: ");
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
                printf("\nYour enter expression is invalid...\n");
                flag = 1;
                break;
            }
            e++;
        }
        if (cop != ccp)
        {
            printf("\nYour enter expression is invalid.\n");
            flag = 1;
        }
    } while (flag);
    revstr(exp);
    printf("\nAbove expression in prefix notation: ");
    infix_prefix(exp);
    printf("\n");
    return 0;
}