#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;
    printf("\nEnter size of array: ");
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));
    printf("\nEnter elements in array: ");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    printf("\nElements in array before sorting: [  ");
    for(int i = 0; i<size; i++)
    printf("%d  ",arr[i]);
    printf("]\n");
    for(int i = 0; i<size-1; i++){
        for(int j = 0; j<size-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("\nElements in array after sorting: [  ");
    for(int i = 0; i<size; i++)
    printf("%d  ",arr[i]);
    printf("]\n");
    return 0;
}