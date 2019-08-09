#include <stdio.h>
#define SIZE 20
int N, K, T;
int map[SIZE];
void init() {
	for (int i = 0; i < K; i++)map[i] = 0;
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d %d", &N, &K);
		for (int i = 0; i < N * K; i++) {
			if ((i / K) % 2 == 0)
				map[i % K] += (i + 1);
			else
				map[K - 1 - (i%K)] += (i + 1);
		}
		printf("#%d ", test + 1);
		for (int i = 0; i < K; i++) {
			printf("%d ", map[i]);
		}
		printf("\n");
		init();
	}
	return 0;
}