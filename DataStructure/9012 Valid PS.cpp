#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int  valid(char* ps) {
	int P = 0;
	int len = strlen(ps);

	for (int i = 0; i < len; i++) {
		if (ps[i] == ')') P--;
		else if (ps[i] == '(') P++;

		if (P < 0) return 0;
	}
	if (P > 0) return 0;
	else return 1;
}

int main() {
	char ps[51];
	int n;

	scanf("%d", &n); //ют╥б х╫╪Ж
	for (int i = 0; i < n; i++) {
		scanf("%s", ps);
		if (valid(ps)) printf("YES\n");
		else printf("NO\n");		
	}

	return 0;
}