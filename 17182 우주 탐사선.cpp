#include <stdio.h>
#define SIZE 10
int N, start, min = 2123456789;
int map[SIZE][SIZE], visited[SIZE];
void dfs(int d, int start, int sum) {
	if (d == N) {
		if (sum < min)min = sum;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			dfs(d + 1, i, sum + map[start][i]);
			visited[i] = 0;
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d", &N, &start);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int t = 0; t < N; t++) {
		for (int s = 0; s < N; s++) {
			for (int e = 0; e < N; e++) {
				if (map[s][t] + map[t][e] < map[s][e])
					map[s][e] = map[s][t] + map[t][e];
			}
		}
	}
	visited[start] = 1;
	dfs(1, start, 0);
	printf("%d\n", min);
	return 0;
}