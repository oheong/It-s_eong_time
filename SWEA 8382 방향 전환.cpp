#include <stdio.h>
#define SIZE 201
int T, N, sx, sy, ex, ey, min = 2123456789, f = -1, r = -1;
int by[4] = { -1,0,1,0 }, bx[4] = { 0,1,0,-1 };
int visited[SIZE][SIZE][4];
typedef struct { int y; int x; int dir; int step; }Queue;
Queue q[SIZE*SIZE*SIZE];
void enQ(int y, int x, int dir, int step) {
	r++;
	q[r].y = y;
	q[r].x = x;
	q[r].dir = dir;
	q[r].step = step;
}
void deQ() { f++; }
Queue peek() { return q[f + 1]; }
int empty() {
	if (f == r)return 1;
	else return 0;
}
void init() {
	f = r = -1; min = 2123456789;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			for (int n = 0; n < 4; n++)
				visited[i][j][n] = 0;
		}
	}
}
void bfs(int y, int x) {
	for (int i = 0; i < 4; i++) {
		visited[y][x][i] = 1;
		enQ(y, x, i, 0);
	}
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		int tdir = peek().dir;
		int tstep = peek().step;
		deQ();
		if (ty == ey && tx == ex) {
			if (tstep < min)min = tstep;
			continue;
		}
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < SIZE && 0 <= nx && nx < SIZE&&visited[ny][nx][i] == 0) { // 최소 스텝이니까
				if (tdir % 2 == i % 2) continue;
				enQ(ny, nx, i, tstep + 1);
				visited[ny][nx][i] = tstep + 1;
			}
		}
	}
}
#define s 100
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
		sx += s;
		sy += s;
		ex += s;
		ey += s;
		bfs(sy, sx);
		printf("#%d %d\n", test + 1, min);
		init();
	}
	return 0;
}