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
void quickSort(node** p,node**l,node**r);
void printList(node** p);
node* getLast(node** p);
node* inPlacePartition(node** p, node** l, node** r);

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
			node* r = getLast(&H);
			quickSort(&H,&H,&r);
			printList(&H);
		}
		if (command == 'q') {
			return 0;
		}
	}

	return 0;
}

void getNode(node** p) {
	(*p) = (node*)malloc(sizeof(node));
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
	node* ex = (*p);
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


void quickSort(node** p, node** l, node** r) {
	if ((*l)->right==NULL ||  (*r)->left==NULL) {
		return;
	}
	node* pivot = inPlacePartition(p, l, r);
	if (pivot->left != NULL) {
		quickSort(p, l, &(pivot->left));
	}
	if (pivot->right != NULL) {
		quickSort(p, &(pivot->right), r);
	}
	return;
}

node* inPlacePartition(node** p, node** l, node** r) {
	node* i, * j;

	int key = (*r)->key;
	i = (*l);
	j = (*r)->left;
	while (i->left != j) {
		while ( i->right != NULL && i->key <= key && i!=j) {
			i = i->right;
		}
		while (j->left != NULL && j->key >= key && i != j) {
			j = j->left;
		}
		if (i != j) {
			int tmp = j->key;
			j->key = i->key;
			i->key = tmp;
		}
	}
	int tmp = (*r)->key;
	(*r)->key = i->key;
	i->key = tmp;

	return i;
}

node* getLast(node** p) {
	node* ex = (*p);
	while (ex->right != NULL) {
		ex = ex->right;
	}
	return ex;
}

