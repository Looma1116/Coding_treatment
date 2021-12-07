#include <stdio.h>
#include <stdlib.h>




int hash(int value, int M) {
	return (value % M);
}

void insert(int A[], int value,int M) {
	int index = hash(value, M);
	if (A[index] == 0) {
		A[index] = value;
		printf("%d\n", index);
	}
	else {
		printf("C");
		int index2 = index + 1;
		while (index2%M != index && A[index2%M]!=0) {
			printf("C");
			index2++;
		}
		A[index2%M] = value;
		printf("%d\n", index2%M);
	}
}

void search(int A[], int value, int M) {
	int index = hash(value, M);
	if (A[index] == value) {
		printf("%d %d\n", index, value);
		return;
	}
	else {
		int index2 = index + 1;
		while (index2%M != index) {
			if (A[index2%M] == value) {
				printf("%d %d\n", index2%M, value);
				return;
			}
			index2++;
		}
	}
	printf("-1\n");
	return;
}



int main() {
	int M,n, value,*A;
	char com;

	scanf("%d %d", &M, &n);
	A = (int*)malloc(sizeof(int) * M);
	for (int i = 0; i < M; i++) {
		A[i] = 0;
	}

	while (1) {
		scanf("%c", &com);
		if (com == 'i') {
			scanf("%d", &value);
			insert(A, value, M);
		}
		if (com == 's') {
			scanf("%d", &value);
			search(A, value, M);
		}
		if (com == 'e') {
			break;
		}
	}
	return 0;
}