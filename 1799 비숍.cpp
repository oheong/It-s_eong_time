#include <stdio.h>
#define SIZE 10
int N;
int map[SIZE][SIZE], chess[SIZE][SIZE], ans[2], visited[SIZE][SIZE];
int by[4] = { -1,-1,1,1 }, bx[4] = { -1,1,1,-1 };
int is_ok(int y, int x) {
	for (int i = 0; i < 4; i++) {
		// 네 방향 돌면서 계속 확인해본다.
		int ny = y + by[i];
		int nx = x + bx[i];
		for (int j = 1; j < N; j++) {
			if (0 <= ny && ny < N && 0 <= nx && nx < N) {
				if (visited[ny][nx] == 1)return false;
			}
			nx += bx[i];
			ny += by[i];
		}
	}
	return true;
}
void dfs(int d, int count, int color) {
	if (ans[color] < d)ans[color] = d;
	if (N*N / 2 < d)return;

	for (int i = count; i < N*N; i++) {
		int y = i / N;
		int x = i % N;

		if (chess[y][x] != color) continue;

		if (map[y][x] == 1) {
			if (is_ok(y, x) == 1) {
				visited[y][x] = 1;
				dfs(d + 1, i + 1, color);
				visited[y][x] = 0;
			}
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (i % 2 == 0) {
				if (j % 2 == 0) chess[i][j] = 1; // black
			}
			else {
				if (j % 2 != 0) chess[i][j] = 1; // black
			}
		}
	}
	dfs(0, 0, 0);
	dfs(0, 0, 1);
	printf("%d\n", ans[0] + ans[1]);
	return 0;
}