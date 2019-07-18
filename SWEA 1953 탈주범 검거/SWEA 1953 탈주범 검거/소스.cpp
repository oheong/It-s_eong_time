#include <stdio.h>
#define SIZE 55
int T, N, M, C, R, L, f = -1, r = -1, temp;
typedef struct { int y; int x; int step; }Queue;
Queue q[SIZE*SIZE];
int map[SIZE][SIZE], visited[SIZE][SIZE], bx[4] = { 0,1,0,-1 }, by[4] = { -1,0,1,0 };
int next[4][4] = { {1,2,5,6} ,{1,3,6,7},{1,2,4,7},{1,3,4,5} };
int pipe[8][4] = { {0,0,0,0},
					{1,1,1,1},
					{1,0,1,0},
					{0,1,0,1},
					{1,1,0,0},
					{0,1,1,0},
					{0,0,1,1},
					{1,0,0,1} };
void init() {
	f = r = -1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			visited[i][j] = 0;
			map[i][j] = 0;
		}
	}
}
void enQ(int y, int x, int step) {
	r++;
	q[r].x = x;
	q[r].y = y;
	q[r].step = step;
}
void deQ() { f++; }
Queue peek() { return q[f + 1]; }
int empty() {
	if (f == r)return 1;
	else return 0;
}
int counting() {
	temp = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (visited[i][j] == 1) temp++;
		}
	}
	return temp;
}
void bfs() {
	while (empty() == 0) {
		int tx = peek().x;
		int ty = peek().y;
		int tstep = peek().step;
		if (tstep == L || tstep >= 20) {
			return;
		}
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (visited[ny][nx] == 0 && map[ny][nx] != 0 && pipe[map[ty][tx]][i] == 1) {
				for (int j = 0; j < 4; j++) {
					if (next[i][j] == map[ny][nx]) {
						enQ(ny, nx, tstep + 1);
						visited[ny][nx] = 1;
					}
				}
			}
		}
	}
}
int main() {
	//freopen("Text.txt", "r", stdin);
	scanf("%d ", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d %d %d %d %d", &N, &M, &C, &R, &L);
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		visited[C + 1][R + 1] = 1;
		enQ(C + 1, R + 1, 1);
		bfs();
		printf("#%d %d\n", test + 1, counting());
		init();
	}
	return 0;
}