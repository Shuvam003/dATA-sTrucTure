#include <stdio.h>
#include <stdlib.h>
int main()
{
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));
    printf("Enter the element in array: ");
    for (int k = 0; k < size; k++)
        scanf("%d", &arr[k]);
    printf("\nArray before sorting: [ ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("]\n");
    int i, j, position, swap;
    for (i = 0; i < (size - 1); i++)
    {
        position = i;
        for (j = i + 1; j < size; j++)
        {
            if (arr[position] > arr[j])
                position = j;
        }
        if (position != i)
        {
            swap = arr[i];
            arr[i] = arr[position];
            arr[position] = swap;
        }
    }
    printf("\nArray after sorting: [ ");
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("]\n");
    return 0;
}