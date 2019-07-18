#include <stdio.h>
#define SIZE 8
int T, N, K, max, tempmax, height, height_count;
int map[SIZE][SIZE], visited[SIZE][SIZE], bx[4] = { 1,-1,0,0 }, by[4] = { 0,0,1,-1 };
typedef struct { int y; int x; } MOUNTAIN;
MOUNTAIN peek[5];
int OK(int ty, int tx, int ny, int nx) {
	if (ny < 0 || N <= ny || nx < 0 || N <= nx) return 0;//x
	else if (map[ty][tx] <= map[ny][nx]) return 0;//x
	else return 1;//¤·¤·
}
void dfs(int d, int y, int x) {
	if (d > N*N) return;
	for (int i = 0; i < 4; i++) {
		if (OK(y, x, y + by[i], x + bx[i]) == 1 && visited[y + by[i]][x + bx[i]] == 0) {
			visited[y + by[i]][x + bx[i]] = 1;
			dfs(d + 1, y + by[i], x + bx[i]);
		}
		else {
			if (max < d)
				max = d;
		}
	}
	visited[y][x] = 0;
	return;
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d %d ", &N, &K);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
				if (height < map[i][j])
					height = map[i][j];
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == height) {
					peek[height_count].y = i;
					peek[height_count++].x = j;
				}
			}
		}
		for (int k = 0; k <= K; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					map[i][j] -= k;
					//////////////////////////////////////////////////////////////////////////////////////////////////////
					for (int c = 0; c < height_count; c++) {
						if (peek[c].y == i && peek[c].x == j && map[i][j] != height)
							continue;
						visited[peek[c].y][peek[c].x] = 1;
						dfs(1, peek[c].y, peek[c].x);
					}
					//////////////////////////////////////////////////////////////////////////////////////////////////////
					map[i][j] += k;
				}

			}
		}
		printf("#%d %d\n", test + 1, max);
		max = 0;
		height = 0;
		height_count = 0;
	}
	return 0;
}