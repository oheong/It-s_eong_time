#include <stdio.h>
#define S 10
int T, N, M, C, h, sum_max, ans;
int map[S][S], visited[S][S], honey[10], visited_honey[20];
int zegop(int a) { return a * a; }
void honey_dfs(int d, int end, int sum, int z) {
	if (d > end || sum > C)return;//ㅅㅂ꿀통 하나에서 max값임 이런씨발,,,
	if (z > sum_max) {
		sum_max = z;
	}
	visited_honey[d] = 1;
	honey_dfs(d + 1, end, sum + honey[d], z + (honey[d] * honey[d]));
	visited_honey[d] = 0;
	honey_dfs(d + 1, end, sum, z);
}
void dfs(int d, int n) {
	if (d == 2) {
		int temp_ans = 0;
		sum_max = 0;
		honey_dfs(0, h / 2, 0, 0);
		temp_ans += sum_max;
		sum_max = 0;
		honey_dfs(h / 2, h, 0, 0);
		temp_ans += sum_max;
		if (temp_ans > ans)ans = temp_ans;
		return;
	}
	for (int i = n; i < N*N; i++) {
		int y = i / N;
		int x = i % N;
		if (visited[y][x] == 0 && x + M - 1 < N) {
			for (int j = x; j < x + M; j++) {
				visited[y][j] = d + 1;
				honey[h++] = map[y][j];
			}
			dfs(d + 1, i);
			for (int j = x; j < x + M; j++) visited[y][j] = 0;
			h -= M;
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d %d %d", &N, &M, &C);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d ", &map[i][j]);
			}
		}
		sum_max = 0;
		dfs(0, 0);
		printf("#%d %d\n", test + 1, ans);
		ans = 0;
	}
	return 0;
}