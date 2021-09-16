#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int H[101] = {0};
int n = 0;


void downHeap(int i){
    if(i*2 > n && i*2+1 > n){
        return;
    }
        int big = i * 2;
        if ((i * 2 + 1) <= n)
        {
            if (H[i * 2 + 1] > H[big])
            {
                big = i * 2 + 1;
            }
    }
    if(H[i]>= H[big]){
        return;
    }
    int tmp = H[i];
    H[i] = H[big];
    H[big] = tmp;
    downHeap(big);
}

//재귀
void rBuildHeap(int i){
    if (i > n){
        return;
    }
    rBuildHeap(2*i);
    rBuildHeap(2*i + 1);
    downHeap(i);
    return;
}

//비재귀
void buildHeap(){
    for (int i = n / 2; i > 0;i--){
        downHeap(i);
    }
    return;
}

void printHeap(){
    for (int j = 1; j <= n; j++){
        printf(" %d", H[j]);
    }
}


int main(){
    char command;
    int key, N;
    scanf("%d", &N);
    n = N;
    for (int i = 1; i <= N;i++){
        scanf("%d", &key);
        H[i] = key;
    }

    buildHeap();
    printHeap();
    return 0;
}

