#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
    int data;
    NODE *right;
} node;

void getNODE(node** p){
    *p = (node *)malloc(sizeof(node));
    (*p)->right = NULL;
}

void addNODE(node **p, int data){
    node *E, *R;
    getNODE(&R);

    R->data = data;
    E = (*p);
    if((*p)==NULL){
        (*p) = R;
    }
    else{
        while(E->right!= NULL){
            E = E->right;
        }
    E->right = R;
    }
}

void printLIST(node* p,int L){
    node *E;
    getNODE(&E);
    E = p;
    for (int i = 0; i < L;i++){
        printf(" %d",E->data);
        E = E->right;
    }
}

int main(){
    node* root;
    int n, data;
    root = NULL;
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        scanf("%d", &data);
        addNODE(&root, data);
    }
    
    printLIST(root, n);
    return 0;
}
