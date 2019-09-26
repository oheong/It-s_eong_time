#include <stdio.h>
#define SIZE 15
int T, N, sy, sx, ey, ex, f = -1, r = -1, ans;
int map[SIZE][SIZE], visited[SIZE][SIZE], by[4] = { 0,0,1,-1 }, bx[4] = { 1,-1,0,0 };
typedef struct { int y; int x; int time; int step; }Queue;
Queue q[SIZE*SIZE*SIZE*SIZE];
void enQ(int y, int x, int time, int step) {
	r++;
	q[r].y = y;
	q[r].x = x;
	q[r].time = time;
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
int bfs() {
	enQ(sy, sx, 0, 0);
	visited[sy][sx] = 1;
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		int ttime = peek().time;
		int tstep = peek().step;
		deQ();
		if (ty == ey && tx == ex) {
			return ttime;
		}
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < N&&map[ny][nx] != 1 && visited[ny][nx] == 0) {
				if (map[ny][nx] == 0) {
					enQ(ny, nx, ttime + 1, tstep + 1);
					visited[ny][nx] = 1;
				}
				else {//2
					if (ttime % 3 == 2) {
						visited[ny][nx] = 1;
						enQ(ny, nx, ttime + 1, tstep + 1);
					}
					else {
						enQ(ty, tx, ttime + 1, tstep);
					}
				}
			}
		}
	}
	return -1;
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		scanf("%d %d %d %d", &sy, &sx, &ey, &ex);

		printf("#%d %d\n", test + 1, bfs());
		init();
	}
	return 0;
}