#include <stdio.h>
#define SIZE 51
int T, N, M, sy, sx, f, r, min;
char c, map[SIZE][SIZE];
int visited[SIZE][SIZE];
int by[4] = { 0,0,1,-1 }, bx[4] = { 1,-1,0,0 };
typedef struct { int status; int y; int x; int step; }Queue;
Queue q[SIZE*SIZE*SIZE];
void enQ(int status, int y, int x, int step) {
	r++;
	q[r].status = status;
	q[r].y = y;
	q[r].x = x;
	q[r].step = step;
}
void deQ() { f++; }
int empty() {
	if (f == r)return 1;
	else return 0;
}
Queue peek() { return q[f + 1]; }
void bfs() {
	while (empty() == 0) {
		int tstatus = peek().status;
		int ty = peek().y;
		int tx = peek().x;
		int tstep = peek().step;
		deQ();
		if (tstatus == 1 && map[ty][tx] == 'D') {
			if (tstep < min)
				min = tstep;
		}
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < M&&map[ny][nx] != 'X') {
				if (tstatus == 1) { // 熱翱檜
					if (visited[ty][tx] == 2) {
					//	min = 2123456789;
						continue;
					}
					if (visited[ny][nx] == 0) {
						enQ(tstatus, ny, nx, tstep + 1);
						visited[ny][nx] = 1;
					}
				}
				else { // 學葆
					if (visited[ny][nx] < 2) {
						if (map[ny][nx] == 'D')continue;
						enQ(tstatus, ny, nx, tstep);
						visited[ny][nx] = 2;
					}
				}
			}
		}
	}
}
void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = 0;
			map[i][j] = '\0';
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d %d\n", &N, &M);
		f = r = -1; min = 2123456789;
		enQ(1, 0, 0, 0);
		for (int i = 0; i < N; i++) {
			scanf("%s", map[i]);
			for (int j = 0; j < M; j++) {
				//scanf("%c", &map[i][j]);
				if (map[i][j] == 'S') {// 熱翱檜
					sy = i; sx = j;
					visited[sy][sx] = 1;
				}
				else if (map[i][j] == '*') {// 學葆
					enQ(2, i, j, 0);
					visited[i][j] = 2;
				}
				else if (map[i][j] == 'X')visited[i][j] = 9;
			}
		}
		q[0].y = sy;
		q[0].x = sx;
		bfs();
		printf("#%d ", test + 1);
		if (min == 2123456789)printf("GAME OVER\n");
		else printf("%d\n", min);
		init();
	}
	return 0;
}
//tq