#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push(int* stack, int* index) {
	int i;
	int* tmp;

	scanf("%d", &i);

	if (i > 100000 || i < 1) return;
	else {
		(*index)++;
		stack[*index - 1] = i;
	}
	

}

void pop(int* stack, int* index) {
	int* tmp;
	if (*index == 0) {
		printf("-1\n");
		return;
	}
	printf("%d\n", stack[*index - 1]);

	(*index)--;
}


void top(int* stack, int* index) {
	if (*index == 0) {
		printf("-1\n");
		return;
	}
	printf("%d\n", stack[*index - 1]);
}

int main() {
	int num_c;
	int stack[100001];
	int index=0;
	char c[10] = { NULL };

	scanf("%d", &num_c);
	if (num_c <= 10000) {
		for (int i = 0; i < num_c; i++) {
			scanf("%s", c);
			if (strcmp(c, "push") == 0) {
				push(stack, &index);
			}
			if (strcmp(c, "pop") == 0) {
				pop(stack,&index);
			}
			if (strcmp(c, "size") == 0) {
				printf("%d\n", index);
			}
			if (strcmp(c, "empty") == 0) {
				if (index < 1) printf("1\n");
				else printf("0\n");
			}
			if (strcmp(c, "top") == 0) {
				top(stack, &index);
			}
		}
	}



	return 0;
}
