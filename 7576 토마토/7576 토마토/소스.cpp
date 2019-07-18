#include <stdio.h>
#define SIZE 1000
int N, M, tomato, r = -1, f = -1, ans;
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
void bfs() {
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		int tstep = peek().step;
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < M&&map[ny][nx] == 0 && visited[ny][nx] == 0) {
				ans = tstep + 1;
				enQ(ny, nx, tstep + 1);
				visited[ny][nx] = 1;
			}
		}
	}
}
int main() {
	//freopen("Text.txt", "r", stdin);
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) {
				enQ(i, j, 0);
				visited[i][j] = 1;
			}
			else if (map[i][j] == -1) visited[i][j] = 1;
		}
	}
	bfs();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] == 0) {
				printf("%d\n", -1);
				return 0;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}