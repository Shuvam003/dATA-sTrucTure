#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct node
{
    double data;
    struct node *next;
} node;

node *head = NULL;
int top = 0;

int isEmpty()
{
    if (top == 0)
        return 1;
    else
        return 0;
}

void push(double x)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = x;
    newnode->next = head;
    head = newnode;
    top++;
}

double pop()
{
    if (!isEmpty())
    {
        node *temp = head;
        double x = temp->data;
        head = head->next;
        free(temp);
        top--;
        return x;
    }
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
    double result;
    while (*e != '\0')
    {
        if (isdigit(*e))
        {
            int a = *e - '0';
            push(a);
        }
        else if (isOperator(*e))
        {
            double val1 = pop();
            double val2 = pop();
            switch (*e)
            {
            case '+':
                push(val2 + val1);
                break;
            case '-':
                push(val2 - val1);
                break;
            case '*':
                push(val2 * val1);
                break;
            case '/':
                push(val2 / val1);
                break;
            case '^':
                double x = 1;
                for (int i = 0; i < val1; i++)
                    x = x * val2;
                push(x);
                break;
            }
        }
        else if (*e == ' ')
        {
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
    printf("\nResult = %lf", pop());
}