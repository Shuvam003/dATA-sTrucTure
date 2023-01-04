#include <stdio.h>
#include <stdlib.h>

int *stack;
int top = -1;
int max, data;

void push(int data);
int pop();
int isFull();
int isEmpty();
void reverse(int arr[]);
void display(int arr[]);

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
        return 0;
}

int isFull()
{
    if (top == max - 1)
    {
        return 1;
    }
    else
        return 0;
}

void push(int data)
{
    if (!isFull())
    {
        stack[++top] = data;
    }
}

int pop()
{
    if (!isEmpty())
    {
        return stack[top--];
    }
}

void reverse(int arr[]){
    stack = (int*)malloc(max*sizeof(int));
    for(int i = 0; i<max; i++){
        push(arr[i]);
    }
    for(int i = 0; i<max; i++){
        arr[i] = pop();
    }
    free(stack);
    printf("\nArray has been reverse...");
}

void display(int arr[]){
    printf("\nValues in array:  [  ");
    for(int i = 0; i<max; i++){
        printf("%d  ",arr[i]);
    }
    printf("]");
}

int main(){
    printf("\nEnter Size of array: ");
    scanf("%d",&max);
    int *arr = (int*)malloc(max*sizeof(int));
    printf("Insert element in array: ");
    for(int i = 0; i<max; i++)
    scanf("%d",&arr[i]);
    display(arr);
    reverse(arr);
    display(arr);
}
