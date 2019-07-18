#include <stdio.h>
int N;
int map[50], visited[50];
void dfs(int d, int n) {
	if (d == 6) {
		for (int i = 0; i < N; i++) {
			if (visited[i] == 1)
				printf("%d ", map[i]);
		}
		printf("\n");
		return;
	}
	for (int i = n; i < N; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			dfs(d + 1, i);
			visited[i] = 0;
		}
	}
}
int main() {
	//freopen("Text.txt", "r", stdin);
	while (1) {
		scanf("%d", &N);
		if (N == 0)break;
		for (int i = 0; i < N; i++) {
			scanf("%d", &map[i]);
		}
		dfs(0, 0);
		printf("\n");
	}
	return 0;
}