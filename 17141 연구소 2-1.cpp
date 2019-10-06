#include <stdio.h>
#define SIZE 50
int N, M, r = -1, f = -1, virus_count, min = 2123456789;
int map[SIZE][SIZE], visited[SIZE][SIZE], by[4] = { 0,0,1,-1 }, bx[4] = { 1,-1,0,0 };
typedef struct { int y; int x; int step; }Queue;
Queue q[SIZE*SIZE];
Queue virus[10];
void enQ(int y, int x, int step) {
	r++;
	q[r].y = y;
	q[r].x = x;
	q[r].step = step;
}
void deQ() { f++; };
Queue peek() { return q[f + 1]; }
int empty() {
	if (f == r)return 1;
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
			if (0 <= ny && ny < N && 0 <= nx && nx < N && visited[ny][nx] == 0 && map[ny][nx] == 0) {
				enQ(ny, nx, tstep + 1);
				visited[ny][nx] = tstep + 1;
			}
		}
	}
}
int init() {
	f = r = -1;
	int t = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1)continue;
			if (visited[i][j] == 0)t = 2123456789;
			else {
				if (visited[i][j] > t&&t != 2123456789)t = visited[i][j];
			}
			visited[i][j] = 0;
		}
	}
	return t;
}
void dfs(int d, int n) {
	if (d == M) {
		for (int i = 0; i < virus_count; i++) {
			if (virus[i].step == 1) {
				enQ(virus[i].y, virus[i].x, 0);
				visited[virus[i].y][virus[i].x] = -1;
			}
		}
		bfs();
		int t = init();
		if (min > t)min = t;
		return;
	}
	for (int i = n; i < virus_count; i++) {
		if (virus[i].step == 0) {
			virus[i].step = 1;
			dfs(d + 1, i);
			virus[i].step = 0;
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) {
				virus[virus_count].y = i;
				virus[virus_count].x = j;
				virus_count++;
				map[i][j] = 0;
			}
		}
	}
	dfs(0, 0);
	if (min == 2123456789)printf("%d\n", -1);
	else printf("%d\n", min);
	return 0;
}