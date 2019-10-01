#include <stdio.h>
int T, max, s;
int map[5][5], visited1[5][5], by[4] = { 0,0,1,-1 }, bx[4] = { 1,-1,0,0 };
void dfs(int d, int y, int x, int ud) {
	if (0 > y || 5 <= y || 0 > x || 5 <= x || visited1[y][x] == 1)return;
	if (d > 26)return;
	if (max < d)max = d;
	visited1[y][x] = 1;
	if (ud == 1) {
		if (map[y + by[0]][x + bx[0]] < map[y][x])
			dfs(d + 1, y + by[0], x + bx[0], 0);
		if (map[y + by[1]][x + bx[1]] < map[y][x])
			dfs(d + 1, y + by[1], x + bx[1], 0);
		if (map[y + by[2]][x + bx[2]] < map[y][x])
			dfs(d + 1, y + by[2], x + bx[2], 0);
		if (map[y + by[3]][x + bx[3]] < map[y][x])
			dfs(d + 1, y + by[3], x + bx[3], 0);
	}
	else {
		if (map[y + by[0]][x + bx[0]] > map[y][x])
			dfs(d + 1, y + by[0], x + bx[0], 1);
		if (map[y + by[1]][x + bx[1]] > map[y][x])
			dfs(d + 1, y + by[1], x + bx[1], 1);
		if (map[y + by[2]][x + bx[2]] > map[y][x])
			dfs(d + 1, y + by[2], x + bx[2], 1);
		if (map[y + by[3]][x + bx[3]] > map[y][x])
			dfs(d + 1, y + by[3], x + bx[3], 1);
	}
	visited1[y][x] = 0;
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d", &s);
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				scanf("%d", &map[i][j]);
			}
		}

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				dfs(1, i, j, 0);
				dfs(1, i, j, 1);
			}
		}
		printf("#%d %d\n", s, max);
		max = 0;
	}
	return 0;
}