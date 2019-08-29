#include <stdio.h>
#define SIZE 100
int t, sy, sx, ey, ex, f = -1, r = -1;
int map[SIZE][SIZE], visited[SIZE][SIZE], by[4] = { 0,0,1,-1 }, bx[4] = { 1,-1,0,0 };
typedef struct { int y; int x; }Queue;
Queue q[SIZE*SIZE];
void enQ(int y, int x) {
	r++;
	q[r].y = y;
	q[r].x = x;
}
void deQ() { f++; }
Queue peek() { return q[f + 1]; }
int empty() {
	if (r == f)return 1;
	else return 0;
}
void init() {
	f = r = -1;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			visited[i][j] = 0;
		}
	}
}
int bfs(int y, int x) {
	visited[y][x] = 1;
	enQ(y, x);
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		deQ();
		if (ty == ey && tx == ex) {
			return 1;
		}
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (map[ny][nx] != 1 && visited[ny][nx] == 0) {
				visited[ny][nx] = 1;
				enQ(ny, nx);
			}
		}
	}
	return 0;
}
int main() {
	freopen("Text.txt", "r", stdin);
	for (int test = 0; test < 10; test++) {
		scanf("%d", &t);
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				scanf("%1d", &map[i][j]);
				if (map[i][j] == 2) {
					sy = i;
					sx = j;
				}
				else if (map[i][j] == 3) {
					ey = i;
					ex = j;
				}
			}
		}
		printf("#%d %d\n", t, bfs(sy, sx));
		init();
	}
	return 0;
}