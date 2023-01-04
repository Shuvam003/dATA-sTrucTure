#include<stdio.h>
#include<stdlib.h>
#include<alloca.h>

typedef struct node{
    int coeff;
    int power;
    struct node *next;
}node;

void addnode(node **ptr, int coef, int powe){
    node *temp = (node*)malloc(sizeof(node));
    temp->coeff = coef;
    temp->power = powe;
    temp->next = NULL;
    if(*ptr == NULL)
        *ptr = temp;
    else{
        temp->next = *ptr;
        *ptr = temp;
    }
}

void readpoly(node **p){
    int coef, powe;
    char ch;
    printf("\n----Enter the terms in the ascending order off power----");
    while(ch == 'Y' || ch == 'y'){
        printf("\nEnter the degree of x: ");
        scanf("%d", &powe);
        printf("\nEnter its coefficient: ");
        scanf("%d", &coef);
        addnode(p, coef, powe);
        printf("\nAny more term((y/Y for YES)  /  (N/n for NO)): ");
        scanf("%c", &ch);
        if(ch == 'n' || ch == 'N'){
            return;
        }
    }
}

void printpoly(node *ptr){
    if(ptr != NULL)
        printf("%dx^%d",ptr->coeff, ptr->power);
    for(ptr = ptr->next; ptr != NULL; ptr = ptr->next){
        if(ptr->coeff>0)
            printf(" + ");
        if(ptr->power == 0)
            printf("%d",ptr->coeff);
        else if(ptr->power == 1)
            printf("%dx",ptr->coeff);
        else
            printf("%dx%d",ptr->coeff, ptr->power);
    }
}

void deletepoly(node **ptr){
    node *temp;
    while(*ptr != NULL){
        temp = *ptr;
        *ptr = (*ptr)->next;
        free(temp);
    }
}

void addpoly(node *ptr1, node *ptr2, node **ptr3){
    int powe;
    float coef;
    while((ptr1 != NULL) && (ptr2 != NULL)){
        if(ptr1->power > ptr2->power){
            coef = ptr1->coeff;
            powe = ptr1->power;
            ptr1 = ptr1->next;
        }
        else if(ptr1->power < ptr2->power){
            coef = ptr2->coeff;
            powe = ptr2->power;
            ptr2 = ptr2->next;
        }
        else{
            coef = ptr1->coeff;
            powe = ptr1->power;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        if(coef != 0)
            addnode(ptr3, coef, powe);
    }
    if(ptr1 == NULL){
        for(; ptr2 != NULL; ptr2 = ptr2->next)
            addnode(ptr3, ptr2->coeff, ptr2->power);
    }
    else if(ptr2 == NULL){
        for(;ptr1 != NULL; ptr1 = ptr1->next)
            addnode(ptr3, ptr1->coeff, ptr1->power);
    }
}

int main(){
    node *poly1, *poly2, *poly3;
    int choice, element, after, before;
    poly1 = poly2 = poly3 = NULL;
    printf("\nProgram to add two polynomials...");
    printf("\n+++++++++++++++++++++++++++++++++\n");
    printf("Enter first polynomial: ");
    readpoly(&poly1);
    printf("\nEnter second polynomial: ");
    readpoly(&poly2);
    addpoly(poly1, poly2, &poly3);
    printf("\nSum of polynomials\n");
    printpoly(poly1);
    printf("\nand\n");
    printpoly(poly2);
    printf("\nis\n");
    printpoly(poly3);
    deletepoly(&poly1);
    deletepoly(&poly2);
    deletepoly(&poly3);
    return 0;
} 