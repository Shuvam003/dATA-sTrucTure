#include<stdio.h>
#include<stdlib.h>
int main(){
    int *ptr, x = 10, y;
    ptr = &x;
    y = *ptr;
    printf("Value of variable x = %d\n",x);
    printf("value of variable pointed to by ptr = %d\n",*ptr);
    printf("Address of pointer x = %u\n",ptr);
    printf("value of variable y = %d\n",y);
}