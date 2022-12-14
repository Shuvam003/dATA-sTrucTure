#include<stdio.h>
#include<stdlib.h>

int *stack;
int max;
int top=-1, data;

void push();
void pop();
void peek();
int isEmpty();
int isFull();

int main(){
    int choice=1;
    printf("\nEnter the capacity of stack: ");
    scanf("%d",&max);
    stack=(int*)malloc(max*sizeof(int));
    while(choice!=4){
        printf("\n----Main Menu----\n\n1.Push.\n2.Pop.\n3.Show the top element.\n4.Exit.\n\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                printf("\nCode Exited successfully...\n");
                exit(0);
            default:
                printf("\nInvallid choice...\n");
        }
    }
    free(stack);
    stack=NULL;
}

int isEmpty(){
    if(top == -1)
        return 1;
    else
        return 0;
}

int isFull(){
    if(top == max-1)
        return 1;
    else
        return 0;
}

void push(){
    if(isFull()){
        printf("\nStack Overflow...\n");
        return;
    }
    printf("\nEnter value: ");
    scanf("%d", &data);
    stack[++top] = data;
    printf("\nOne data is pushed.\nData: %d\n",data);
}

void pop(){
    if(isEmpty()){
        printf("\nStack is empty...\n");
        return;
    }
    data = stack[top--];
    printf("\nOne Data is popped\nData: %d\n", data);
}

void peek(){
    if(top==-1){
        printf("\nStack is empty...\n");
        return;
    }
    else{
        printf("\nTop element of the stack: %d\n",stack[top]);
    }
}
