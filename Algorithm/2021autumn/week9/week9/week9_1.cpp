#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node* next;
	struct node* prev;
}node;

typedef struct list {
	int key;
	node* header = NULL;
}list;

void getNode(node** p,int value) {
	(*p) = (node*)malloc(sizeof(node));
	(*p)->next = NULL;
	(*p)->prev = NULL;
	(*p)->value = value;
}
int hash(int value, int M) {
	return (value % M);
}
void insertNode(node* header, int value) {
	node* next = header->next;
	node* N;
	getNode(&N, value);
	
	header->next = N;
	if (next != NULL) {
		next->prev = N;
	}
	N->next = next;
	N->prev = header;
	
}

void searchNode(list* A, int value, int M) {
	node* ex;
	int index = hash(value, M);
	int level = 0;
	if (A[index].header != NULL) {
		ex = A[index].header->next;
		while (ex != NULL) {
			level++;
			if (ex->value == value) {
				printf("%d\n", level);
				return;
			}
			ex = ex->next;
		}
	}	
	printf("0\n");
	return;
}

void deleteNode(list* A, int value, int M) {
	node* ex;
	int index = hash(value, M);
	int level = 0;
	if (A[index].header != NULL) {
		ex = A[index].header->next;
		while (ex != NULL) {
			level++;
			if (ex->value == value) {
				printf("%d\n",level);
				(ex->prev)->next = ex->next;
				if (ex->next != NULL) {
					(ex->next)->prev = ex->prev;
				}
				free(ex);
				return;
			}
			ex = ex->next;
		}
	}
	printf("0\n");
	return;
}

void printList(list* A, int M) {
	node* ex;
	int flag=0;
	for (int i = 0; i < M; i++) {
		if (A[i].header != NULL) {
			ex = A[i].header->next;
			while (ex != NULL) {
				printf(" %d", ex->value);
				ex = ex->next;
				flag++;
			}
		}
	}
	if (flag == 0) {
		printf("0");
	}
	printf("\n");
}
void mapping(list* A, int value, int M) {
	int index;
	index = hash(value, M);
	insertNode(A[index].header, value);
}
int main() {
	int M,value;
	list* A;
	char com;

	scanf("%d", &M);
	A = (list*)malloc(sizeof(list) * M);
	for (int i = 0; i < M; i++) {
		getNode(&A[i].header,-1);
	}
	while (1) {
		scanf("%c", &com);
		if (com == 'i') {
			scanf("%d", &value);
			mapping(A, value, M);
		}
		if (com == 's') {
			scanf("%d", &value);
			searchNode(A, value, M);
		}
		if (com == 'd') {
			scanf("%d", &value);
			deleteNode(A, value, M);
		}
		if (com == 'p') {
			printList(A, M);
		}
		if (com == 'e') {
			break;
		}
	}
	return 0;
}