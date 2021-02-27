#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct node {  //��� ����ü
    struct node* prev;
    struct node* next;
    int elem;
    int live;
}NODE;

typedef struct list {  //����Ʈ ����ü
    NODE* H; //��� �����͸� �����ϴ� ������ �׷��� ������� ��带 ������ ����Ʈ�� �ݿ��Ǳ� ����.
    NODE* T;
    int n;
}LIST;

void getNODE(NODE** q) { //��带 �Ҵ����ִ� �Լ�
    *q = (NODE*)malloc(sizeof(NODE));
    (*q)->prev = NULL;
    (*q)->next = NULL;
    (*q)->live = 0;
}

void setList(LIST* A) { //����Ʈ �ʱ� ���� �Լ�
    A->H = NULL;
    A->T = NULL;
    getNODE(&(A->H));
    getNODE(&(A->T));
    A->H->next = A->T;
    A->T->prev = A->H;
    A->T->next = A->H;
    A->H->live = 0; //����� Ʈ���Ϸ��� ������.
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
        for (int l = 0; l < K; l++) { //K ĭ�� �������� �ϴµ�
            L = L->next;
            while (L->live != 1) { //�����ڴ� ���� ����.
                L = L->next; //�׷��� �Ѿ����.
            }
        }
        L->live = 0; //�׾�!
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
        for (int i = 0; i < N; i++) {//���� ����
            push(&J, i);
        }
        kill(&J, K);
	}

}

/**
�似Ǫ���� 40���� �������

���� ������ �������� ������ �а��Ͽ�

�θ����� �׺��� �䱸�߽��ϴ�.

��������� �׺� ��� �ڰ��ϱ�� �ߴµ�

�������̾��� �似Ǫ���� �������� ������

�ڻ��� �� �ȴٰ� �����մϴ�.

�ٸ� ��������� ������ �ٲٷ� ���� �ʾҰ�

�似Ǫ���� �ڻ��� ���� �� �Ǵ�

��Ģ�� ���� �� �� ���̰�

������ ���� �� ����� �ڰ����ڰ� �����մϴ�.

1������ N������ N���� ����� ���� �̷�鼭 �ɾ��ְ�, 
���� ���� K(�� N)�� �־�����. 
���� ������� K��° ����� �����Ѵ�.
�� ����� ���ŵǸ� ���� ������ �̷���� ���� ���� �� ������ ����� ������
�� ������ N���� ����� ��� ���ŵ� ������ ��ӵȴ�. 
������ ������� ���ŵǴ� ������ (N, K)-�似Ǫ�� �����̶�� �Ѵ�. 
���� ��� (7, 3)-�似Ǫ�� ������ <3, 6, 2, 7, 5, 1, 4>�̴�.
**/