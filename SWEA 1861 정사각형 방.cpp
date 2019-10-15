#include <stdio.h>
#define SIZE 1000
int T, N, f = -1, r = -1, min = 2123456789, max;
int map[SIZE][SIZE], visited[SIZE][SIZE], by[4] = { -1,0,1,0 }, bx[4] = { 0,1,0,-1 };
typedef struct { int y; int x; int step; }Queue;
Queue q[SIZE*SIZE];
void enQ(int y, int x, int step) {
	r++;
	q[r].y = y;
	q[r].x = x;
	q[r].step = step;
}
void deQ() { f++; }
Queue peek() { return q[f + 1]; }
int empty() {
	if (r == f)return 1;
	else return 0;
}
void init() {
	min = 2123456789;
	max = 0;
	f = r = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 0;
		}
	}
}
void bfs(int y, int x, int num) {
	f = r = -1;
	enQ(y, x, 1);
	visited[y][x] = num;
	int temp_max = 0;
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		int tstep = peek().step;
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < N&&visited[ny][nx] != num && map[ny][nx] == map[ty][tx] + 1) {
				enQ(ny, nx, tstep + 1);
				visited[ny][nx] = num;
				if (tstep + 1 > temp_max)temp_max = tstep + 1;
			}
		}
	}
	if (max <= temp_max) {
		if (max == temp_max) {
			if (min > map[y][x]) {
				min = map[y][x];
			}
		}
		else min = map[y][x];
		max = temp_max;
	}
}
int main() {
	//rfreopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d ", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				bfs(i, j, map[i][j]);
			}
		}
		printf("#%d %d %d\n", test + 1, min, max);
		init();
	}
	return 0;
}