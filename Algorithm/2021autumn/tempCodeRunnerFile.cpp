#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findPivot(int l,int r){
    srand(time(NULL));
    return (rand()%r+l);
}

int inPlacePartition(int **L,int l, int r, int k){
    int *A = (*L);
    int p = A[k];
    int tmp;

    tmp = A[k];
    A[k] = A[r];
    A[r] = tmp;

    int i = l;
    int j = r-1;
    while(i<=j){
        while(i<=j && A[i]<=p){
            i++;
        }
        while(j>=i && A[j]>=p){
            j--;
        }
        if(i<j){
            tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    tmp = A[i];
    A[i] = A[r];
    A[r] = tmp;

    return i;
}

void inPlaceQuickSort(int** L, int l, int r){
    if(l<r){
    int k = findPivot(l, r);
    int i = inPlacePartition(L, l, r, k);
    inPlaceQuickSort(L, l, i-1);
    inPlaceQuickSort(L, i+1, r);
    }
}

int main(){
    int *A;
    int n, data;
    scanf("%d", &n);
    A = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++){
        scanf("%d", &data);
        A[i] = data;
    }

    inPlaceQuickSort(&A, 0, n-1);
    for (int i = 0; i < n; i++){
        printf(" %d", A[i]);
    }
    return 0;
}
