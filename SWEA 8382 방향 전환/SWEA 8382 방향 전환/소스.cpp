#include <stdio.h>
#define SIZE 201
int sx, sy, ex, ey, T, r = -1, f = -1, min = 2123456789;
int visited[SIZE][SIZE][4], by[4] = { -1,0,1,0 }, bx[4] = { 0,1,0,-1 };
typedef struct { int y; int x; int d; int step; }Queue;
Queue q[SIZE*SIZE * SIZE];
void enQ(int y, int x, int d, int step) {
	r++;
	q[r].y = y;
	q[r].x = x;
	q[r].d = d;
	q[r].step = step;
}
void deQ() { f++; }
Queue peek() { return q[f + 1]; }
int empty() {
	if (r == f)return 1;
	else return 0;
}
void bfs(int y, int x) {
	for (int i = 0; i < 4; i++) {
		enQ(y, x, i, 0);
		visited[y][x][i] = 1;
	}
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		int td = peek().d;
		int tstep = peek().step;
		deQ();
		if (ty == ey && tx == ex) {
			if (tstep < min)min = tstep;
			continue;
		}
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < SIZE && 0 <= nx && nx < SIZE&&visited[ny][nx][i] == 0) {
				if (td % 2 == i % 2) continue;//전에 왔던 방향이랑 같으면 걍 넘어가고 직각으로만 움직이게 가라
				enQ(ny, nx, i, tstep + 1);
				visited[ny][nx][i] = 1;
			}
		}
	}
}
void init() {
	f = r = -1;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			for (int n = 0; n < 4; n++) visited[i][j][n] = 0;
		}
	}
	min = 2123456789;
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d ", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
		sx += 100;
		sy += 100;
		ex += 100;
		ey += 100;
		bfs(sy, sx);
		printf("#%d %d\n", test + 1, min);
		init();
	}
	return 0;
}