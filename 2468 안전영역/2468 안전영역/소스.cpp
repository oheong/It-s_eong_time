#include <stdio.h>
#define SIZE 100
int N, f = -1, r = -1, max, count;
int map[SIZE][SIZE], visited[SIZE][SIZE], bx[4] = { 1,-1,0,0 }, by[4] = { 0,0,1,-1 };
typedef struct { int y; int x; }Queue;
Queue q[SIZE*SIZE*SIZE];
void enQ(int y, int x) {
	r++;
	q[r].x = x;
	q[r].y = y;
}
void deQ() { f++; }
Queue peek() { return q[f + 1]; }
int empty() {
	if (f == r)return 1;
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
void bfs(int y, int x, int rain) {
	enQ(y, x);
	visited[y][x] = 1;
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < N&&visited[ny][nx] == 0 && map[ny][nx] >= rain) {
				visited[ny][nx] = 1;
				enQ(ny, nx);
			}
		}
	}
}
int main() {
	int t = 0;
	scanf("%d ", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (t < map[i][j])t = map[i][j];
		}
	}
	for (int rain = 0; rain <= t; rain++) {
		count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] >= rain && visited[i][j] == 0) {
					bfs(i, j, rain);
					count++;
				}
			}
		}
		if (max < count)max = count;
		init();
	}
	printf("%d\n", max);
	return 0;
}