#include<stdio.h>
#include<stdlib.h>


int main(){
    int arr[6] = {20,10,8,30,11,16};
    printf("\nBefore sorting: ");
    for(int i = 0; i<6; i++){
        printf("%d ",arr[i]);
    }
    for(int i = 0; i<5; i++){
        for(int j = 0; j<5-i; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("\nAfter sorting: ");
    for(int i = 0; i<6; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}