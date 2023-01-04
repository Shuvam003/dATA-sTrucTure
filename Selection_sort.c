#include <stdio.h>
#include<stdlib.h>
int main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int *arr = (int*)malloc(n*sizeof(int));
    printf("Enter the element in array: ");
    for(int k = 0; k<n; k++)
        scanf("%d",&arr[k]);
    int i, j, position, swap;
    for (i = 0; i < (n - 1); i++) {
        position = i;
        for (j = i + 1; j < n; j++) {
            if (arr[position] > arr[j])
                position = j;
        }
        if (position != i) {
            swap = arr[i];
            arr[i] = arr[position];
            arr[position] = swap;
        }
    }
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}