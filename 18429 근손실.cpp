#include <stdio.h>
int N, K, ans;
int map[10], visited[10];
void dfs(int d, int weight) {
	if (weight < 500) return;
	if (d == N) {
		ans++;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visited[i] == 0) {
			visited[i] = d + 1;
			dfs(d + 1, weight + map[i] - K);
			visited[i] = 0;
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &map[i]);
	}
	dfs(0, 500);
	printf("%d\n", ans);
	return 0;
}