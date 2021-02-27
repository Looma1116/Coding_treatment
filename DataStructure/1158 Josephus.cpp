#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct node {  //노드 구조체
    struct node* prev;
    struct node* next;
    int elem;
    int live;
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
    (*q)->live = 0;
}

void setList(LIST* A) { //리스트 초기 설정 함수
    A->H = NULL;
    A->T = NULL;
    getNODE(&(A->H));
    getNODE(&(A->T));
    A->H->next = A->T;
    A->T->prev = A->H;
    A->T->next = A->H;
    A->H->live = 0; //헤더랑 트레일러도 죽은자.
    A->T->live = 0;
    A->n = 0;
}

void push(LIST* A, int i) { //push
    NODE* L;
    NODE* a;
    getNODE(&L);
    getNODE(&a);
    L = A->T;
    a->elem =i+1;
    a->live = 1;

    a->next = L;
    L->prev->next = a;
    a->prev = L->prev;
    L->prev = a;
    A->n++;
}

void kill(LIST* A, int K) {
    NODE* L;
    getNODE(&L);

    L = A->H;
    printf("<");
    for (int j = 0; j < A->n; j++) {
        for (int l = 0; l < K; l++) { //K 칸씩 움직여야 하는데
            L = L->next;
            while (L->live != 1) { //죽은자는 말이 없다.
                L = L->next; //그러니 넘어가주자.
            }
        }
        L->live = 0; //죽어!
        printf("%d", L->elem); 
        if (j < A->n-1) printf(", ");
    }
    printf(">");
}


int main() {
	int N, K, alive, num=0;
    LIST J;
    setList(&J);
	
	scanf("%d %d", & N, &K);
    alive = N;
	if ((N > 0 && N < 5001) && (K > 0 && K < 5001)) {
        for (int i = 0; i < N; i++) {//순열 세팅
            push(&J, i);
        }
        kill(&J, K);
	}

}

/**
요세푸스는 40명의 결사대원과

지하 땅굴로 숨었지만 누군가 밀고하여

로마군은 항복을 요구했습니다.

결사대원들은 항복 대신 자결하기로 했는데

제사장이었던 요세푸스는 종교적인 이유로

자살은 안 된다고 주장합니다.

다른 결사대원들은 결정을 바꾸려 하지 않았고

요세푸스는 자살은 결코 안 되니

규칙을 정해 한 명씩 죽이고

마지막 남은 한 사람은 자결하자고 제안합니다.

1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고, 
양의 정수 K(≤ N)가 주어진다. 
이제 순서대로 K번째 사람을 제거한다.
한 사람이 제거되면 남은 사람들로 이루어진 원을 따라 이 과정을 계속해 나간다
이 과정은 N명의 사람이 모두 제거될 때까지 계속된다. 
원에서 사람들이 제거되는 순서를 (N, K)-요세푸스 순열이라고 한다. 
예를 들어 (7, 3)-요세푸스 순열은 <3, 6, 2, 7, 5, 1, 4>이다.
**/