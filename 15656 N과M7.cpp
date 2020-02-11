#include <stdio.h>
#define SIZE 7
int N, M;
int map[SIZE], visited[SIZE];
void sort() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1 - i; j++) {
			if (map[j] > map[j + 1]) {
				int temp = map[j];
				map[j] = map[j + 1];
				map[j + 1] = temp;
			}
		}
	}
}
void dfs(int d) {
	if (d == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", visited[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < N; i++) {
		visited[d] = map[i];
		dfs(d + 1);
	}
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &map[i]);
	}
	sort();
	dfs(0);
	return 0;
}