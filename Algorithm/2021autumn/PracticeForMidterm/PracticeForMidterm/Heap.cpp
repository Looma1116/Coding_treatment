#include <stdio.h>
#include <stdlib.h>



void insertItem(int** heap, int key);
void removeItem(int** heap, int key);
void upHeap(int** heap, int index);
void downHeap(int** heap, int index);
void searchNode(int** heap, int key);
void removeMin(int** heap);
void downHeap(int** heap, int index);
void printHeap(int** heap);
void inPlaceHeapSort(int** heap);
int num = 0;

int main() {
	int *heap, key;
	char command;
	heap = (int*)malloc(sizeof(int) * 101);
	while (1) {
		scanf("%c", &command);
		if(command == 'i'){
			scanf("%d", &key);
			insertItem(&heap, key);
			getchar();
		}
		if (command == 's') {
			scanf("%d", &key);
			searchNode(&heap, key);
			getchar();
		}
		if (command == 'r') {
			removeMin(&heap);
		}
		if (command == 'p') {
			printHeap(&heap);
		}
		if (command == 'q') {
			return 0;
		}
		if (command == 't') {
			inPlaceHeapSort(&heap);
			printHeap(&heap);
		}
	}
}

void insertItem(int** heap, int key) {
	num++;
	(*heap)[num]= key;
	upHeap(heap, num);
}

void upHeap(int** heap, int index) {
	if (index / 2 <= 0) {
		return;
	}
	if ((*heap)[index / 2] > (*heap)[index]) {
		return;
	}
	int tmp = (*heap)[index / 2];
	(*heap)[index / 2] = (*heap)[index];
	(*heap)[index] = tmp;
	upHeap(heap, index / 2);
}
void searchNode(int** heap, int key) {
	for (int i = 1; i <= num; i++) {
		if ((*heap)[i] == key) {
			printf("key : %d는 index : %d에 있습니다.\n",key,i);
			return;
		}
	}
	printf("존재하지 않는 값입니다.\n");
	return;
}
void removeMin(int** heap) {
	printf("제거된 값 :%d\n", (*heap)[1]);
	(*heap)[1] = (*heap)[num];
	num--;
	downHeap(heap, 1);
}

void downHeap(int** heap, int index) {
	if (index < 1) {
		return;
	}
	int bigChild = index*2;
	if (index * 2 > num || index * 2+1 > num) {
		return;
	}
	if ((*heap)[index * 2] < (*heap)[index * 2 + 1]) {
		bigChild = index *2 +1;
	}
	if ((*heap)[index] < (*heap)[bigChild]) {
		int tmp = (*heap)[bigChild];
		(*heap)[bigChild] = (*heap)[index];
		(*heap)[index] = tmp;
	}
	downHeap(heap, bigChild);
}

void printHeap(int** heap) {
	for (int i = 1; i <= num; i++) {
		printf(" %d", (*heap)[i]);
	}
	printf("\n");
}

void inPlaceHeapSort(int** heap) {
	for (int i = ; i <= num; i++) {
		int tmp = (*heap)[i];
		(*heap)[i] = (*heap)[1];
		(*heap)[1] = tmp;
		downHeap(heap, 1);
	}
}