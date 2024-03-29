#include <stdio.h>
#define SIZE 100
int N, M, f = -1, r = -1, min = 2123456789;
int map[SIZE][SIZE], visited[SIZE][SIZE], by[4] = { 0,0,1,-1 }, bx[4] = { 1,-1,0,0 };
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
void bfs(int y, int x) {
	enQ(y, x, 1);
	visited[y][x] = 1;
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		int tstep = peek().step;
		if (ty == N - 1 && tx == M - 1) {
			if (min > tstep)min = tstep;
		}
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < M&&visited[ny][nx] == 0 && map[ny][nx] == 1) {
				visited[ny][nx] = tstep + 1;
				enQ(ny, nx, tstep + 1);
			}
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	bfs(0, 0);
	printf("%d\n", min);
	return 0;
}