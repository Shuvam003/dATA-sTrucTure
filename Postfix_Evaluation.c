#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

double stack[100];
int top = -1;

void push(double data)
{
    stack[++top] = data;
}

double pop()
{
    return stack[top--];
}

int isOperator(char x)
{
    if (x == '^' || x == '*' || x == '+' || x == '-' || x == '/')
        return 1;
    else
        return 0;
}

void postfix_evaluation(char *e)
{
    while (*e != '\0')
    {
        if (isdigit(*e))
        {
            double a = *e - '0';
            push(a);
        }
        else if (isOperator(*e))
        {
            double a = pop();
            double b = pop();
            double i;
            switch (*e)
            {
            case '+':
                i = a + b;
                push(i);
                break;
            case '-':
                i = b - a;
                push(i);
                break;
            case '*':
                i = b * a;
                push(i);
                break;
            case '/':
                i = b / a;
                push(i);
                break;
            case '^':
                double j = 1;
                for (int i = 0; i < a; i++)
                    j = j * b;
                push(j);
                break;
            }
        }

        e++;
    }
}

int main()
{
    char exp[100];
    printf("\nEnter a postfix expression: ");
    scanf("%s", exp);
    postfix_evaluation(exp);
    while (top != -1)
    {
        printf("\nResult = %lf", pop());
    }
    return 0;
}