#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	int key;
	struct NODE* left;
	struct NODE* right;
}node;

void getNode(node** p);
int listLen(node** p);
void insertNode(node** p, int key);
void partition(node* p, node** L1, node** L2);
void mergeSort(node** p);
node* merge(node** p, node** q);
void printList(node** p);

int main() {
	node* H = NULL;

	char command;
	int key, num;

	while (1) {
		scanf("%c", &command);
		if (command == 'i') {
			scanf("%d", &num);
			for (int i = 0; i < num; i++) {
				scanf("%d", &key);
				insertNode(&H, key);
			}
		}
		if (command == 'p') {
			mergeSort(&H);
			printList(&H);
		}
		if (command == 'q') {
			return 0;
		}
	}

	return 0;
}

void getNode(node** p) {
	(*p)= (node*)malloc(sizeof(node));
	(*p)->left = NULL;
	(*p)->right = NULL;
}

void printList(node** p) {
	node* ex = (*p);
	while (ex != NULL) {
		printf(" %d", ex->key);
		ex = ex->right;
	}
	printf("\n");
	return;
}
int listLen(node** p) {
	node* ex=(*p);
	int i = 0;

	while (ex->right != NULL) {
		ex = ex->right;
		i++;
	}
	return i;
}

void insertNode(node** p, int key) {
	node* ex = (*p);
	node* q;
	getNode(&q);
	q->key = key;
	if ((*p) == NULL) {
		(*p) = q;
		return;
	}
	while (ex->right != NULL) {
		ex = ex->right;
	}
	getNode(&q);
	q->key = key;
	ex->right = q;
	q->left = ex;
}

void partition(node* p, node** L1, node** L2) {
	int len = listLen(&p);
	(*L1) = p;
	node* ex = p;
	for (int i = 0; i < len / 2; i++) {
		ex = ex->right;

	}
	(*L2) = ex->right;
	ex->right = NULL;
	(*L2)->left = NULL;

	return;
}

void mergeSort(node** p) {
	if ((*p)->right == NULL) {
		return;
	}
	node* L1, * L2;
	getNode(&L1);
	getNode(&L2);
	partition((*p), &L1, &L2);
	mergeSort(&L1);
	mergeSort(&L2);
	(*p) = merge(&L1, &L2);
	return;
}

node* merge(node** p, node** q) {
	node* L, *ex;
	getNode(&L);
	if ((*p)->key > (*q)->key) {
		L = (*q);
		(*q) = (*q)->right;
	}
	else {
		L = (*p);
		(*p) = (*p)->right;
	}
	ex = L;
	while ((*p) != NULL && (*q) != NULL) {
		if ((*p)->key > (*q)->key) {
			ex->right = (*q);
			(*q) = (*q)->right;
		}
		else {
			ex->right = (*p);
			(*p) = (*p)->right;
		}
		ex = ex->right;
	}
	if (*p == NULL) {
		ex->right = (*q);
	}
	if (*q == NULL) {
		ex->right = (*p);
	}
	return L;

}