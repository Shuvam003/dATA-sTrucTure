#include<stdio.h>
#include<stdlib.h>


int main(){
    int ****arr;
    arr = (int****)malloc(4*sizeof(int***));
    for(int i = 0; i < 4; i++){
        arr[i] = (int***)malloc(3*sizeof(int**));
        for(int j = 0; j < 3; j++){
            arr[i][j] = (int**)malloc(3*sizeof(int*));
            for(int k = 0; k < 3; k++){
                arr[i][j][k] = (int*)malloc(5*sizeof(int));
                for(int l = 0; l < 5; l++){
                    arr[i][j][k][l] = i+j+k+l;
                }
            }
        }
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                for(int l = 0; l < 5; l++){
                    printf("\narr[%d][%d][%d][%d] = %d", i, j, k, l, arr[i][j][k][l]);
                }
            }
        }
    }
    return 0;
}