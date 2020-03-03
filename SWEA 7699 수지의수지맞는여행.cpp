#include <stdio.h>
#define SIZE 21
int T, R, C, max;
char map[SIZE][SIZE];
int visited[SIZE][SIZE], alph[26];
int by[4] = { 0,0,1,-1 }, bx[4] = { 1,-1,0,0 };
int is_ok(int y, int x) {
	if (0 <= y && y < R && 0 <= x && x < C)return 1;
	else return 0;
}
void dfs(int d, int y, int x) {
	if (d > R*C)return;
	if (alph[map[y][x] - '0'] == 1 || visited[y][x] == 1) return;
	if (max < d)max = d;
	alph[map[y][x] - '0'] = 1;
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + by[i];
		int nx = x + bx[i];
		if (is_ok(ny, nx) == 1)
			dfs(d + 1, ny, nx);
	}
	alph[map[y][x] - '0'] = 0;
	visited[y][x] = 0;
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d %d\n", &R, &C);
		for (int i = 0; i < R; i++) {
			for (int j = 0; j <= C; j++) {
				scanf("%c", &map[i][j]);
			}
		}
		max = 0;
		dfs(1, 0, 0);
		printf("#%d %d\n", test + 1, max);
	}
	return 0;
}
