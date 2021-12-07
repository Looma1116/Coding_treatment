#include <stdio.h>
#include <stdlib.h>

int hash(int value, int M) {
	return (value % M);
}

int hash2(int value, int q) {
	return (q - (value % q));
}

void insert(int A[], int value, int M, int q) {
	int index = hash(value, M);
	if (A[index] == 0) {
		A[index] = value;
		printf("%d\n", index);
	}
	else {
		int stride = hash2(value, q);
		while(A[index]!=0){
			index += stride;
			printf("C");
			index %= M;
		}
		A[index] = value;
		printf("%d\n", index);
	}
	return;
}

void search(int A[], int value, int M, int q) {
	int index = hash(value, M);
	int i = 0;
	if (A[index] == value) {
		printf("%d %d\n", index, value);
		return;
	}
	else {
		int stride = hash2(value, q);
		int index2 = index;
		index += stride;
		while (A[index2%M] != value) {
			index2 += stride;
			i++;
			if (i == M) {
				printf("-1\n");
				return;
			}
		}
		printf("%d %d\n", index2 % M, value);
	}
	return;
}


int main() {
	int M, n,q,num, value, * A;
	char com;
	num = 0;
	scanf("%d %d %d", &M, &n, &q);
	A = (int*)malloc(sizeof(int) * M);
	for (int i = 0; i < M; i++) {
		A[i] = 0;
	}

	while (1) {
		scanf("%c", &com);
		if (com == 'i') {
			scanf("%d", &value);
			insert(A, value, M, q);
		}
		if (com == 's') {
			scanf("%d", &value);
			search(A, value, M, q);
		}
		if (com == 'p') {
			for (int i = 0; i < M; i++) {
				printf(" %d", A[i]);
			}
			printf("\n");
		}
		if (com == 'e') {
			for (int i = 0; i < M; i++) {
				printf(" %d", A[i]);
			}
			printf("\n");
			break;
		}
	}
	return 0;
}