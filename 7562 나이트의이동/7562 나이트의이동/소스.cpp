#include <stdio.h>
#define SIZE 300
int T, L, sx, sy, ex, ey, f = -1, r = -1;
int map[SIZE][SIZE], visited[SIZE][SIZE], by[8] = { -2,-1,1,2,2,1,-1,-2 }, bx[8] = { 1,2,2,1,-1,-2,-2,-1 };
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
	f = r = -1;
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < L; j++) {
			visited[i][j] = 0;
		}
	}
}
void bfs(int y, int x) {
	enQ(y, x, 0);
	visited[y][x] = 1;
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		int tstep = peek().step;
		if (ty == ey && tx == ex) {
			printf("%d\n", tstep);
			init();
			return;
		}
		deQ();
		for (int i = 0; i < 8; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < L && 0 <= nx && nx < L&&visited[ny][nx] == 0) {
				enQ(ny, nx, tstep + 1);
				visited[ny][nx] = 1;
			}
		}
	}
}
int main() {
	//freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d", &L);
		scanf("%d %d\n%d %d", &sy, &sx, &ey, &ex);
		bfs(sy, sx);
	}
	return 0;
}