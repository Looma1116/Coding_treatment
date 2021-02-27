#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {  //노드 구조체
    struct node* prev;
    struct node* next;
    int elem;
}NODE;

typedef struct list {  //리스트 구조체
    NODE* H; //노드 포인터를 선언하는 이유는 그래야 돋보기로 노드를 훑으면 리스트에 반영되기 때문.
    NODE* T;
    int n;
}LIST;

void getNODE(NODE** q) { //노드를 할당해주는 함수
    *q = (NODE*)malloc(sizeof(NODE));
    (*q)->prev = NULL;
    (*q)->next = NULL;
}

void setList(LIST* A) { //리스트 초기 설정 함수
    A->H = NULL;
    A->T = NULL;
    getNODE(&(A->H));
    getNODE(&(A->T));
    (A->H)->next = (A->T);
    (A->T)->prev = (A->H);
    A->n = 0;
}

void push(LIST* A) { //push
    int p;
    NODE* L;
    NODE* a;
    getNODE(&L);
    getNODE(&a);
    L = A->T;

    scanf("%d", &p);
    if (p <= 100000 && p >= 1) { //linking the new node through the Trailer
        a->elem = p;
        a->next = L;
        L->prev->next = a;
        a->prev = L->prev;
        L->prev = a;
    }
}

void pop(LIST* A) {
    NODE* L;
    getNODE(&L);
    L = A->H;

    if (L->next == A->T) {
        printf("-1\n");
        return;
    }
    else { //print front node and free it;
        printf("%d\n", L->next->elem);
        L->next = L->next->next;
        free(L->next -> prev);
        L->next->prev = L;
    }
}

int size(LIST* A) {
    NODE* L;
    int size=0;
    getNODE(&L);

    L = A->H;
    while (L->next->next != NULL) { //H to T-1
        L = L->next;
        size++;
    }

   return size;
}

void front(LIST* A) {
    NODE* L;
    getNODE(&L);
    L = A->H;

    if (L->next == A->T) {
        printf("-1\n");
        return;
    }
    else {
        printf("%d\n", L->next->elem);
    }
}

void back(LIST* A) {
    NODE* L;
    getNODE(&L);
    L = A->T;

    if (L->prev == A->H) {
        printf("-1\n");
        return;
    }
    else {
        printf("%d\n", L->prev->elem);
    }
}

int main() {
    LIST Q;
    setList(&Q);

    int num_c;
    char c[10] = { NULL };
    scanf("%d", &num_c);

    if (num_c < 1 || num_c >10000) return 0;

    for (int i = 0; i < num_c; i++) {
        scanf("%s", c);
        if (strcmp(c, "push") == 0) {
            push(&Q);
        }
        if (strcmp(c, "pop") == 0) {
            pop(&Q);
        }
        if (strcmp(c, "size") == 0) {
            printf("%d\n", size(&Q));
        }
        if (strcmp(c, "empty") == 0) {
            if (size(&Q)) printf("0\n");
            else printf("1\n");
        }
        if (strcmp(c, "front") == 0) {
            front(&Q);
        }
        if (strcmp(c, "back") == 0) {
            back(&Q);
        }
    }

    return 0;
}

/**
input
>
15
push 1
push 2
front
back
size
empty
pop
pop
pop
size
empty
pop
push 3
empty
front

output
<
1
2
2
0
1
2
-1
0
1
-1
0
3
**/