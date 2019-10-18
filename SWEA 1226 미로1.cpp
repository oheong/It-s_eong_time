#include <stdio.h>
#define SIZE 16
int f, r;
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
int bfs(int test) {
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (map[ny][nx] == 3)return 1;
			if (visited[ny][nx] < test&&map[ny][nx] == 0) {
				enQ(ny, nx);
				visited[ny][nx] = test;
			}
		}
	}
	return 0;
}
int main() {
	freopen("Text.txt", "r", stdin);
	int t;
	for (int test = 1; test <= 10; test++) {
		scanf("%d", &t);
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				scanf("%1d", &map[i][j]);
				if (map[i][j] == 2) {
					f = r = -1;
					visited[i][j] = test;
					enQ(i, j);
				}
			}
		}
		printf("#%d %d\n", test, bfs(test));
	}
	return 0;
}