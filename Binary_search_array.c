#include<stdio.h>
#include<stdlib.h>

int binarysearch(int *arr, int low, int high, int data){
    while(low<=high){
        int mid = (low+high)/2;
        int a = arr[mid];
        if(a==data)
        return mid;
        else if(a<data)
        return binarysearch(arr, mid+1, high, data);
        else
        return binarysearch(arr, low, mid-1, data);
    }
    return -1;
}
int main(){
    int arr[6]={1,2,3,4,5,6};
    printf("\nEnter data: ");
    int data;
    scanf("%d",&data);
    int pos = binarysearch(arr, 0, 6, data);
    if(pos!=-1)
    printf("\nposition: %d",pos);
    else
    printf("\nAbsent");
    return 0;
}