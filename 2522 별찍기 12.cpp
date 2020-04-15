#include<stdio.h>
#define SIZE 100
int N;
int map[SIZE * 2][SIZE];
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N; j++) {
			if (i + j < N - 1)printf(" ");
			else printf("*");
		}
		printf("\n");
	}
	for (int i = 0; i < N; i++) printf("*");
	printf("\n");
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N; j++) {
			if (i >= j)printf(" ");
			else printf("*");
		}
		printf("\n");
	}
	return 0;
}