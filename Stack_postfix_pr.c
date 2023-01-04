#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define max 100

char stack[100];
int top = -1;

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

int is_operator(char x)
{
    if (x == '^' || x == '*' || x == '/' || x == '+' || x == '-' || x == '(' || x == ')')
        return 1;
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
            while (priority(*e) <= priority(stack[top]))
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

int main()
{
    int flag = 0;
    char exp[100];
    do
    {
        printf("\nEnter a expression: ");
        scanf("%s", exp);
        char *e;
        e = exp;
        while (*e != '\0')
        {
            if (!isalnum(*e) && !is_operator(*e))
            {
                printf("\nYour enter expression is invalid...\n");
                flag = 1;
                break;
            }
            else
            {
                flag = 0;
            }
            e++;
        }
    } while (flag);
    printf("\nAbove expression in postfix notation: ");
    Infix_Postfix(exp);
    printf("\n");
    return 0;
}