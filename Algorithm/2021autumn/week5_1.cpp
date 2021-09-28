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

void partition(node* p, node** L1, node** L2){
    int Len = lenLIST(p);
    *L1 = p;
    for (int i = 1; i < Len / 2;i++){
        p = p->right;
    }
    *L2 = p->right;
    p->right = NULL;
}

node* merge(node** L1, node** L2){
    node *L,*E = NULL;
    getNODE(&L);
    if ((*L1)->data <= (*L2)->data) {
        L = (*L1);
        (*L1) = (*L1)->right;
    }
    else {
        L = (*L2);
        (*L2) = (*L2)->right;
    }
    E = L;
    while(*L1 != NULL && *L2 != NULL){
        if((*L1)->data <(*L2)->data){
            E->right = *L1;
            (*L1) = (*L1)->right;
        }
        else{
            E->right = *L2;
            (*L2) = (*L2)->right;;
        }
        E = E->right;
    }
    while(*L1!=NULL){
        E->right = *L1;
        (*L1) = (*L1)->right;
        E = E->right;
    }
    while(*L2!=NULL){
        E->right = *L2;
        (*L2) = (*L2)->right;
        E = E->right;
    }
    return L;
}


void printLIST(node* p, int L){
    node *E;
    getNODE(&E);
    E = p;
    for (int i = 0; i < L;i++){
        printf(" %d",E->data);
        E = E->right;
    }
}

void mergeSort(node** p){
    if(lenLIST(*p)<=1){
        return;
    }
    node *L1, *L2;
    partition(*p, &L1, &L2);
    mergeSort(&L1);
    mergeSort(&L2);
    *p = merge(&L1, &L2);
    return;
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
    mergeSort(&root);
    printLIST(root, n);
    return 0;
}