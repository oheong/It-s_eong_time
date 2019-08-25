#include <stdio.h>
#define SIZE 100
int N;
int map[SIZE * 2][SIZE * 2];
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i >= j)printf("*");
			else printf(" ");
		}
		for (int j = N; j < 2 * N; j++) {
			if (i + j + 1 >= 2 * N)printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	for (int i = N; i < 2 * N - 1; i++) {
		for (int j = 0; j < N; j++) {
			if (i + j < N * 2 - 1)printf("*");
			else printf(" ");
		}
		for (int j = N; j < 2 * N; j++) {
			if (i < j)printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}