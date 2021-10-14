#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct NODE {
   struct NODE* next;
   int data;
}NODE;
void getNode(NODE** p) {
   *p = (NODE*)malloc(sizeof(NODE));
   (*p)->next = NULL;
}
void add(NODE* L, int e) {
   NODE* p= NULL;
   getNode(&p);
   p->data = e;

   while(L->next !=NULL) {
      L = L->next;
   }
   L->next = p;
   
}
void prt(NODE* L) {
   NODE* p = L;
   while (p != NULL) {
      printf(" %d", p->data);
      p = p->next;
   }
   printf("\n");
}
void partition(NODE* L, NODE** L1, NODE** L2, int k) {
   *L1 = L;
   NODE* p = L;
   for (int i = 0; i < k - 1; i++) {
      p = p->next;
   }
   *L2 = p->next;
   p->next = NULL;
}
NODE* merge(NODE** L1, NODE** L2) {
    NODE* p, * L = NULL, * A = *L1, * B = *L2;
    getNode(&L);
    if (A->data <= B->data) {
        L = A;
        A = A->next;
    }
    else {
        L = B;
        B = B->next;
    }
    p = L;
    while (A != NULL && B != NULL) {
        if (A->data <= B->data) {
            p->next = A;
            A = A->next;
        }
        else {
            p->next = B;
            B = B->next;
        }
        p = p->next;
    }
    while (A != NULL) {
        p->next = A;
        A = A->next;
        p = p->next;
    }
    while (B != NULL) {
        p->next = B;
        B = B->next;
        p = p->next;
    }
    return L;
}
void mergeSort(NODE** L, int n) {
   NODE* L1, * L2;
   if (n > 1) {
      partition(*L, &L1, &L2, n / 2);
      if (n % 2 == 0) {
         mergeSort(&L1, n / 2);
         mergeSort(&L2, n / 2);
      }
      else {
         mergeSort(&L1, n / 2);
         mergeSort(&L2, n / 2 + 1);
      }
      *L = merge(&L1, &L2);
   }
}
int main() {
   int n, e;
   NODE* L = NULL;
   getNode(&L);
   scanf("%d", &n);
   for (int i = 0; i < n; i++) {
      scanf("%d", &e);
      if(i==0){
         L->data = e;
         continue;
      }
      add(L, e);
   }
   mergeSort(&L, n);
   prt(L);
}