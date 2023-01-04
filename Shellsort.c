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
    int gap, i, j, key;
    for (gap = size / 2; gap >= 1; gap = gap / 2)
    {
        for (i = gap; i < size; i++)
        {
            key = arr[i];
            for (j = i-gap; j >= 0 && arr[j] > key; j = j - gap)
            {
                arr[j + gap] = arr[j];
            }
            arr[j + gap] = key;
        }
    }
    printf("\nElements in array after sorting: [  ");
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("]\n");
}