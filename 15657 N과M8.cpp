#include <stdio.h>
int N, M;
int map[8], visited[8];
void sort() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (map[j] > map[j + 1]) {
				int temp = map[j + 1];
				map[j + 1] = map[j];
				map[j] = temp;
			}
		}
	}
}
void dfs(int d, int n) {
	if (d == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", visited[i]);
		}
		printf("\n");

		return;
	}
	for (int i = n; i < N; i++) {
		visited[d] = map[i];
		dfs(d + 1, i);
	}
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &map[i]);
	}
	sort();
	dfs(0, 0);
	return 0;
}