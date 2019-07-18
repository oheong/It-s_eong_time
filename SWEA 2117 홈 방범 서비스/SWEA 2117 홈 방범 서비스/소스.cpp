#include <stdio.h>
#define SIZE 20
int T, N, M, home_count, f = -1, r = -1, max, temp_step, K;
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
void init() {
	f = r = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 0;
		}
	}
}
void bfs(int y, int x, int step) {
	enQ(y, x, step);
	visited[y][x] = 1;
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		int tstep = peek().step;
		if (tstep != temp_step) {
			K = tstep * tstep + (tstep - 1)*(tstep - 1);
			if (0 <= home_count * M - K)
				if (max < home_count)
					max = home_count;
		}
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < N&&visited[ny][nx] == 0) {
				enQ(ny, nx, tstep + 1);
				visited[ny][nx] = 1;
				temp_step = tstep;
				if (map[ny][nx] == 1) home_count++;
			}
		}
	}
}
int main() {
	//freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		max = 0;
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 1) home_count = 1;
				else home_count = 0;
				temp_step = 0;
				bfs(i, j, 1);
				init();
			}
		}
		printf("#%d %d\n", test + 1, max);
	}
	return 0;
}