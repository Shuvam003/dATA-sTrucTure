#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("\nEnter size of array: ");
    int size;
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));
    printf("\nEnter elements in array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nElements in array before sorting: [  ");
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("]\n");
    int i, j, position, swap;
    for (i = 0; i < (size - 1); i++) {
        position = i;
        for (j = i + 1; j < size; j++) {
            if (arr[position] > arr[j])
                position = j;
        }
        if (position != i) {
            swap = arr[i];
            arr[i] = arr[position];
            arr[position] = swap;
        }
    }
    printf("\nElements in array after sorting: [  ");
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("]\n");
}