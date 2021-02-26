#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int size_stack;


void push(int* stack) {
	int i;
	int* tmp;

	scanf("%d", &i);

	if (i > 100000 || i<1) return;
	size_stack++;
	tmp = stack;
	stack = (int*)realloc(stack, sizeof(int) * (size_stack));
	stack[size_stack-1] = i;
	if(tmp != stack) 	free(tmp);
}

void pop(int* stack) {
	int* tmp;
	if (size_stack == 0) {
		printf("-1\n");
		return;
	}
	printf("%d\n", stack[size_stack-1]);

	tmp = stack;
	stack = (int*)realloc(stack, sizeof(int) * (size_stack));
	if (tmp != stack) 	free(tmp);

	size_stack--;

}


void top(int* stack) {
	if (size_stack == 0) {
		printf("-1\n");
		return;
	}
	printf("%d\n", stack[size_stack-1]);
}

int main() {
	int num_c;
	int* stack = NULL;
	char c[10] = { NULL };

	stack = (int*)malloc(sizeof(int)*(size_stack+1));

	scanf("%d", &num_c);
	if (num_c <= 10000) {
		for (int i = 0; i < num_c; i++) {
			scanf("%s",c);
			if (strcmp(c, "push") == 0) {
				push(stack);
			}
			if (strcmp(c, "pop") == 0) {
				pop(stack);
			}
			if (strcmp(c, "size") == 0) {
				printf("%d\n", size_stack);
			}
			if (strcmp(c, "empty") == 0) {
				if (size_stack < 1) printf("1\n");
				else printf("0\n");
			}
			if (strcmp(c, "top") == 0) {
				top(stack);
			}
		}
	}

	free(stack);
	

	return 0;
}
