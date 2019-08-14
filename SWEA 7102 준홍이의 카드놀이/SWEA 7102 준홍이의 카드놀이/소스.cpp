#include <stdio.h>
#define SIZE 21
int T, N, M, max;
int hap[SIZE * 2];
void init() {
	for (int i = 1; i <= N + M; i++) hap[i] = 0;
	max = 0;
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d %d", &N, &M);
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				hap[i + j]++;
				if (max < hap[i + j]) max = hap[i + j];
			}
		}
		printf("#%d ", test + 1);
		for (int i = 1; i <= N + M; i++) {
			if (hap[i] == max)printf("%d ", i);
		}
		printf("\n");
		init();
	}
	return 0;
}