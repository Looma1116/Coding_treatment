#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {  //노드 구조체
    struct node* prev;
    struct node* next;
    char elem;
}NODE;

typedef struct list {  //리스트 구조체
    NODE* H; //노드 포인터를 선언하는 이유는 그래야 돋보기로 노드를 훑으면 리스트에 반영되기 때문.
    NODE* T;
    int n;
}LIST;

void getNODE(NODE** q) { //노드를 할당해주는 함수
    *q = (NODE*)malloc(sizeof(NODE));
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

void visitList(LIST* A) { //리스트의 모든 원소를 출력하는 함수
    NODE* L;  //나는 돋보기 노드라고 부른다.
    getNODE(&L);
    L = A->H;

    for(int i = 0 ; i<A->n ; i++){
        L = L->next;
        printf("%c", L->elem);
    }
}

char visitNode(LIST* A, int r) { //특정 랭크 번째에 있는 노드의 원소 반환
    NODE* L;
    getNODE(&L);

    L = A->H;
    for (int i = 0; i < r; i++) {
        L = L->next; //해당 랭크까지 이동
    }

    return L->elem; //원소 반환
}

void addNode(LIST* A, int r, char e) { //해당 랭크에 해당 원소를 갖는 노드를 삽입
    NODE* L;
    NODE* N;

    getNODE(&L);
    getNODE(&N);


    L =A->H;
    for (int i = 0; i < r; i++) {
        L = L->next;
    }
    (L->prev)->next = N;  //새 노드를 연결해준다
    N->prev = L->prev;    //
    L->prev = N;                //
    N->next = L;                //

    A->n++; //리스트의 노드 개수 더하기 (헤러당 트레일러는 제외)

    N->elem = e;
}

void deleteNode(LIST* A, int r) {  //해당 랭크의 노드 제거
    NODE* L;
    getNODE(&L);
    L = A->H;

    for (int i = 0; i < r; i++) {
        L = L->next;
    }

    (L->prev)->next = L->next;  //해당 랭크의 노드 앞 뒤 노드끼리 연결
    (L->next)->prev = L->prev;
    A->n--;

    free(L); //해당 노드 메모리 해제
}
int main() {
    int n, r;
    char com, e;
    LIST* A;
    A = NULL;
    A = (LIST*)malloc(sizeof(LIST)); //리스트 A 만들기

    setList(A);

    scanf("%d", &n); //명령어 개수

    for (int i = 0; i < n; i++) {
        scanf("%c", &com); //명령 선택

        switch (com) { 
            case 'A': {
               scanf("%d %c", &r, &e);
               getchar();
               if (r == 0 || r > A->n+1) {
                   printf("invalid position\n");
                   break;
               }
               addNode(A, r, e);
               break;
             }
            case 'D': {
               scanf("%d", &r);
               getchar();
               if (r == 0 || r > A->n) {
                   printf("invalid position\n");
                   break;
               }
               deleteNode(A, r);
               break;
            }
            case 'G': {
               scanf("%d", &r);
               getchar();
               if (r == 0 || r > A->n) {
                   printf("invalid position\n");
                   break;
               }
               printf("%c", visitNode(A, r));
               printf("\n");
               break;
            }
            case 'P': {
               visitList(A);
               printf("\n");
               break;
            }
            default: {
               i--;
               continue;
            }
        }
    }

    return 0;
}

/**
입출력 예시

9
A 1 D
A 2 a
A 3 y
D 1
P
>>ay

G 3 
>>invalid position

A 1 S
P
>>Say

G 3
>>y

**/
