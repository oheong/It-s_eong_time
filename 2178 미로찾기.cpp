#include <stdio.h>
int N, M, f = -1, r = -1;
int map[150][150], visited[150][150], bx[4] = { 1,-1,0,0 }, by[4] = { 0,0,1,-1 };
typedef struct { int y; int x; }Queue;
Queue q[10000];
void enQ(int y, int x) {
	r++;
	q[r].y = y;
	q[r].x = x;
}
void deQ() { f++; }
Queue peek() { return q[f + 1]; }
int empty() {
	if (f == r)return 1;
	else return 0;
}
void bfs() {
	visited[1][1] = 1;
	enQ(1, 1);
	while (empty() == 0) {
		int tx = peek().x;
		int ty = peek().y;
		if (ty == N && tx == M) {
			printf("%d\n", visited[N][M]);
			return;
		}
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (map[ny][nx] == 1&&(visited[ny][nx]==0||visited[ny][nx]>visited[ty][tx]+1)) {
				visited[ny][nx] = visited[ty][tx] + 1;
				enQ(ny, nx);
			}
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d ", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	bfs();
	return 0;
}