#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c, d, e;
    printf("\nEnter the 5 different sizes of array: ");
    scanf("%d\n%d\n%d\n%d\n%d", &a, &b, &c, &d, &e);
    int *****arr = (int *****)malloc(a * sizeof(int ****));
    for (int i = 0; i < a; i++)
    {
        arr[i] = (int ****)malloc(b * sizeof(int ***));
        for (int j = 0; j < b; j++)
        {
            arr[i][j] = (int ***)malloc(c * sizeof(int **));
            for (int k = 0; k < c; k++)
            {
                arr[i][j][k] = (int **)malloc(d * sizeof(int *));
                for (int l = 0; l < d; l++)
                {
                    arr[i][j][k][l] = (int *)malloc(e * sizeof(int));
                    for (int m = 0; m < e; m++)
                    {
                        arr[i][j][k][l][m] = i + j + k + l + m;
                    }
                }
            }
        }
    }
    int n = 0;
    printf("\nElements in array: ");
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
            for (int k = 0; k < c; k++)
                for (int l = 0; l < d; l++)
                    for (int m = 0; m < e; m++)
                        printf("%d  ", arr[i][j][k][l][m]);
    printf("\n");
    return 0;
}