#include <stdio.h>
#define SIZE 10//10
typedef struct { int y; int x; int step; }Queue;
int T, N, M, l_cnt, f, r, ans;
int visited[SIZE][SIZE];
int by[4] = { -1,0,1,0 }, bx[4] = { 0,1,0,-1 };
char map[SIZE][SIZE];
Queue q[SIZE*SIZE], L[SIZE*SIZE];
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
int init() {
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'L')
				count += (visited[i][j] - 1);
			visited[i][j] = 0;
		}
	}
	return count;
}
void bfs() {
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		int tstep = peek().step;
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < M&&visited[ny][nx] == 0 && map[ny][nx] == 'L') {
				enQ(ny, nx, tstep + 1);
				visited[ny][nx] = visited[ty][tx] + 1;
			}
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d %d\n", &N, &M);
		l_cnt = 0;
		ans = 0;
		f = r = -1;
		for (int i = 0; i < N; i++) {
			scanf("%s", &map[i]);
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 'W') {
					enQ(i, j, 0);
					visited[i][j] = 1;
				}
			}
		}
		bfs();
		printf("#%d %d\n", test + 1, init());
	}
	return 0;
}

// L부터 하는게 아니라 W부터 해야함