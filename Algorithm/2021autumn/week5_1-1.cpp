#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void merge(int** L, int l, int m, int r){
    int *A = *L;
    int *B;
    B = (int *)malloc(sizeof(int) * (r+1));
    int i = l;
    int k = l;
    int j = m + 1;
    while(i<=m && j<=r){
        if(A[i]<=A[j]){
            B[k] = A[i];
            k++;
            i++;
        }
        else{
            B[k] = A[j];
            k++;
            j++;
        }
    }
    while(i<=m){
        B[k] = A[i];
        k++;
        i++;
    }
    while(j<=r){
        B[k] = A[j];
        k++;
        j++;
    }
    for (k = l; k <= r;k++){
        A[k] = B[k];
    }
    free(B);
}

void rMergeSort(int**L,int l, int r){
    if(l<r){
        int m = (l + r) / 2;
        rMergeSort(L, l, m);
        rMergeSort(L, m + 1, r);
        merge(L, l, m, r);
    }
}

void mergeSort(int**L,int n){
    rMergeSort(L, 0, n - 1);
}

int main(){
    int n, data;
    scanf("%d", &n);
    int *L;
    L = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++){
        scanf("%d", &data);
        L[i] = data;
    }
    mergeSort(&L,n);
    for (int i = 0; i < n; i++){
        printf(" %d", L[i]);

    }
    return 0;
}