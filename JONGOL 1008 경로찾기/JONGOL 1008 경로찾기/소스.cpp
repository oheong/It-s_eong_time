#include <stdio.h>
#define SIZE 10
int map[SIZE][SIZE], visited[SIZE][SIZE], by[4] = { 1,-1,0,0 }, bx[4] = { 0,0,1,-1 };
int N, T, sx, sy, ey, ex, f = -1, r = -1, max = -1;
typedef struct Queue { int y; int x; int step; };
Queue q[SIZE*SIZE];
int tt;
void enQ(int y, int x, int step) {
	r++;
	q[r].x = x;
	q[r].y = y;
	q[r].step = step;
}
void deQ() { f++; }
int empty() {
	if (f == r)return 1;
	else return 0;
}
Queue peek() { return q[f + 1]; }
void bfs(int y, int x) {
	enQ(y, x, 0);
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		int tstep = peek().step;
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < N && (visited[ny][nx] == 0 || visited[ny][nx] > visited[ty][tx] + map[ny][nx]) && map[ny][nx] != 0&&tstep<T) {
				visited[ny][nx] = map[ny][nx] + visited[ty][tx];
				tt = tstep + 1;
				enQ(ny, nx, tstep + 1);
			}
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d", &N, &T);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == -1) {
				sy = i;
				sx = j;
			}
			else if (map[i][j] == -2) {
				ey = i;
				ex = j;
			}
		}
	}
	visited[sy][sx] = 1;
	bfs(sy, sx);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d\t", visited[i][j]);
		}
		printf("\n");
	}
	printf("%d\n%d\n", visited[ey][ex],tt);
	return  0;
}