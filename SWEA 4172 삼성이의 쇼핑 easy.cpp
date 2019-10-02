#include <stdio.h>
int T, N, M, ans;
int map[25][2], visited[25];
void dfs(int d, int money, int max) {
	if (d > M)return;
	if (money > N)return;
	if (ans < max)ans = max;

	visited[d] = 1;
	dfs(d + 1, money + map[d][0], max + map[d][1]);
	visited[d] = 0;
	dfs(d + 1, money, max);
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d %d", &N, &M);
		for (int i = 0; i < M; i++) {
			scanf("%d %d", &map[i][0], &map[i][1]);
		}
		dfs(0, 0, 0);
		printf("#%d %d\n", test + 1, ans);
		ans = 0;
	}
	return 0;
}