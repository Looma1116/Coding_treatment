#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int len = 0;

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
    getNODE(&E);
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
    }
    E->right = R;
}

int lenLIST(node* p){
    node *E;
    getNODE(&E);
    int i = 1;
    E = p;
    while(E->right != NULL){
        E = E->right;
        i++;
    }
    return i;
}

void partition(node* p, node** L2){
    int L = lenLIST(p);
    node *E;
    getNODE(&E);

    E = p;
    for (int i = 1; i < L / 2;i++){
        E = E->right;
    }
    *L2 = E->right;
    E->right = NULL;
}

node* merge(node** L1, node** L2){
    node *L = NULL;

    while(*L1 != NULL && *L2 != NULL){
        if((*L1)->data <(*L2)->data){
            addNODE(&L, (*L1)->data);
            (*L1) = (*L1)->right;
        }
        else{
            addNODE(&L, (*L2)->data);
            (*L2) = (*L2)->right;;
        }
    }
    while(L1!=NULL){
        addNODE(L, L1->data);
        L1 = L1->right;

    }
    while(L2!=NULL){
        addNODE(L, L2->data);
        L2 = L2->right;
    }
    return L;
}


void printLIST(node* p){
    int L = lenLIST(p);
    node *E;
    getNODE(&E);
    E = p;
    for (int i = 0; i < L;i++){
        printf(" %d",E->data);
        E = E->right;
    }
}

void mergeSort(node* p){
    if(lenLIST(p)<=1){
        return;
    }
    node *L1, *L2;
    getNODE(&L1);
    getNODE(&L2);
    L1 = p;
    partition(p, &L2);
    printf("\nL1:");
    printLIST(L1);
    printf("\nL2:");
    printLIST(L2);
    mergeSort(L1);
    mergeSort(L2);
    p = merge(L1, L2);
    printf("\nmerged:");
    printLIST(p);
    return;
}

int main(){
    node* root;
    int n, data;
    root = NULL;
    scanf("%d", &n);
    if(n==0){
        return 0;
    }
    scanf("%d", &data);
    root->data = data;
    for (int i = 1; i < n; i++){
        scanf("%d", &data);
        addNODE(root, data);
    }
    mergeSort(root);
    printLIST(root);
    return 0;
}