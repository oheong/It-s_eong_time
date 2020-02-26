#include <stdio.h>
#define SIZE 16
int T, N;
double max;
int map[SIZE][SIZE], visited[SIZE];
void dfs(int d, double sum) {
	if (sum <= max) return;//와 이런생각 어떻게하지
	if (d == N) {
		if (max < sum) max = sum;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (visited[i] == 0) {
			visited[i] = d + 1;
			dfs(d + 1, sum*map[i][d] * 0.01);
			visited[i] = 0;
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		dfs(0, 1.0);
		printf("#%d %6f\n", test + 1, max * 100);
		max = 0.0;//초기화 쫌
	}
	return 0;
}
