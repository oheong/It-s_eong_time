#include <stdio.h>
int k;
int map[51], visited[51];
void dfs(int d, int n) {
	if (d == 6) {
		for (int i = 0; i < k; i++) {
			if (visited[i] == 1) {
				printf("%d ", map[i]);
			}
		}
		printf("\n");
		return;
	}
	for (int i = n + 1; i < k; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			dfs(d+1, i);
			visited[i] = 0;
		}
	}
}
int main() {
	while (1) {
		scanf("%d", &k);
		if (k == 0) return 0;
		for (int i = 0; i < k; i++) {
			scanf("%d", &map[i]);
		}
		for (int i = 0; i < k; i++) {
			if (visited[i] == 0) {
				visited[i] = 1;
				dfs(1, i);
				visited[i] = 0;
			}
		}
		printf("\n");
	}
}