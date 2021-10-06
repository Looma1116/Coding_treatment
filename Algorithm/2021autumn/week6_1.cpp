#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void binarySearch(int* A, int k,int l, int r){
    int mid = (l + r) / 2;
    if(l>r){
        printf(" %d", l-1);
        return;
    }
    if(A[mid]==k){
        printf(" %d", mid);
        return;
    }
    if(A[mid]>k){
        binarySearch(A, k, l, mid - 1);
    }
    else{
        binarySearch(A, k, mid + 1, r);
    }
}

int main(){
    int n,k,input,i;
    int *array;
    scanf("%d %d", &n, &k);
    array = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i ++){
        scanf("%d", &input);
        array[i] = input;
    }
    binarySearch(array, k, 0, n-1);
}