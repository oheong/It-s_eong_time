#include <stdio.h>
#define SIZE 20
int T, N, dessert_max, ans_max = -1;
int map[SIZE][SIZE], visited[2], dessert[101], by[4] = { 1,1,-1,-1 }, bx[4] = { -1,1,1,-1 };
void init() {
	for (int i = 1; i <= dessert_max; i++)dessert[i] = 0;
	dessert_max = 0;
	ans_max = -1;
}
int gogo_cafe(int y, int x) {
	if (x - visited[0] < 0 || N <= x + visited[1] || N <= y + visited[0] + visited[1]) return 0;
	int ty = y, tx = x;
	dessert[map[ty][tx]] = 1;
	for (int i = 0; i < visited[0]; i++) {
		ty += by[0];
		tx += bx[0];
		if (dessert[map[ty][tx]] == 1)return 0;
		else dessert[map[ty][tx]] = 1;
	}
	for (int i = 0; i < visited[1]; i++) {
		ty += by[1];
		tx += bx[1];
		if (dessert[map[ty][tx]] == 1)return 0;
		else dessert[map[ty][tx]] = 1;
	}
	for (int i = 0; i < visited[0]; i++) {
		ty += by[2];
		tx += bx[2];
		if (dessert[map[ty][tx]] == 1)return 0;
		else dessert[map[ty][tx]] = 1;
	}
	for (int i = 0; i < visited[1]; i++) {
		ty += by[3];
		tx += bx[3];
		if (dessert[map[ty][tx]] == 1) {
			if (ty == y && tx == x) dessert[map[ty][tx]]++;
			else return 0;
		}
		else dessert[map[ty][tx]] = 1;
	}
	if (dessert[map[y][x]] == 2)return 1;
	else return 0;
}
void dfs(int d) {
	if (d == 2) {
		if (visited[0] + visited[1] >= N)return;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (gogo_cafe(i, j) == 1) {
					if (ans_max < (visited[0] + visited[1]) * 2)ans_max = (visited[0] + visited[1]) * 2;
				}
				for (int i = 1; i <= dessert_max; i++)dessert[i] = 0;
			}
		}
		return;
	}
	for (int i = 1; i < N; i++) {
		visited[d] = i;
		dfs(d + 1);
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
				if (dessert_max < map[i][j])dessert_max = map[i][j];
			}
		}
		dfs(0);
		printf("#%d %d\n", test + 1, ans_max);
		init();
	}
	return 0;
}