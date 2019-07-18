#include <stdio.h>
#define SIZE 300
int N, M, f = -1, r = -1, count, ans;
int map[SIZE][SIZE], visited[SIZE][SIZE], by[4] = { 1,-1,0,0 }, bx[4] = { 0,0,1,-1 };
typedef struct { int y; int x; }Queue;
Queue q[SIZE*SIZE];
void init() {
	f = r = -1;
	//count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = 0;
		}
	}
}
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
int abs(int a) {
	if (a < 0) return 0;
	else return a;
}
void bfs(int y, int x) {
	visited[y][x] = 1;
	enQ(y, x);
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (visited[ny][nx] == 0 && map[ny][nx] != 0) {
				enQ(ny, nx);
				visited[ny][nx] = 1;
			}
			if (map[ny][nx] == 0 & visited[ny][nx] == 0) {
				map[ty][tx]--;
			}
			map[ty][tx] = abs(map[ty][tx]);
		}
	}
}
void dfs(int d) {
	if (count > 1) {
		ans = d - 1;
		return;
	}
	if (d > 1 && count == 0) {
		ans = 0;
		return;
	}
	count = 0;
	for (int i = 1; i < N - 1; i++) {
		for (int j = 1; j < M - 1; j++) {
			if (map[i][j] != 0 && visited[i][j] == 0) {
				count++;
				bfs(i, j);
			}
		}
	}
	init();
	dfs(d + 1);
}
int main() {
	//freopen("Text.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	dfs(0);
	printf("%d\n", ans);
	return 0;
}