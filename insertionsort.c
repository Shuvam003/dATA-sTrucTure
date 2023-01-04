#include<stdio.h>
#include<stdlib.h>

int main(){
    printf("\nEnter size of array: ");
    int size;
    scanf("%d", &size);
    int *arr = (int*)malloc(size*sizeof(int));
    printf("\nEnter elements in array: ");
    for(int i = 0; i<size; i++){
        scanf("%d",&arr[i]);
    }
    printf("\nElements in array before sorting: [  ");
    for(int i = 0; i<size; i++){
        printf("%d  ",arr[i]);
    }
    printf("]\n");
    int i, j;
    for(i = 1; i<size; i++){
        int key = arr[i];
        for(j = i-1; arr[j]>key && j>=0; j--){
            arr[j+1] = arr[j];
        }
        arr[j+1] = key;
    }
    printf("\nElements in array after sorting: [  ");
    for(int i = 0; i<size; i++){
        printf("%d  ",arr[i]);
    }
    printf("]\n");
}