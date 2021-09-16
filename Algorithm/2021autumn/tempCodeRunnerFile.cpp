#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int H[101] = {0};
int n = 0;


void upHeap(int i){
    if(i == 1){
        return;
    }
    if (H[i] <= H[i / 2]){
        return;
    }
    int tmp = H[i];
    H[i] = H[i/2];
    H[i / 2] = tmp;
    upHeap(i / 2);
}
void downHeap(int i){
    if(i*2 > n && i*2+1 > n){
        return;
    }
        int big = i * 2;
        if ((i * 2 + 1) * 2 <= n)
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

void insertItem(int key){
    n += 1;
    H[n] = key;
    upHeap(n);
}

int removeMax(){
    int root = H[1];
    H[1] = H[n];
    n -= 1;
    downHeap(1);
    return root;
}

void printHeap(){
    for (int j = 1; j <= n; j++){
        printf(" %d", H[j]);
    }
}


int main(){
    char command;
    int key;

    scanf("%c", &command);
    while(command != 'q'){
        if(command == 'i'){
            scanf("%d", &key);
            insertItem(key);
            printf("0\n");
        }
        if(command == 'd'){
            printf("%d\n", removeMax());
        }
        if(command == 'p'){
            printHeap();
            printf("\n");
        }
        if(command == 'q'){
            return 0;
        }
        scanf("%c", &command);
    }
    return 0;
}

