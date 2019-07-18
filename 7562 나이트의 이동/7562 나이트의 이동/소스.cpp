#include <stdio.h>
#define SIZE 300
int testcase, l, f = -1, r = -1, start_x, start_y, end_x, end_y;
int map[SIZE][SIZE], visited[SIZE][SIZE], bx[8] = { 1,2,2,1,-1,-2,-2,-1 }, by[8] = { -2,-1,1,2,2,1,-1,-2 };
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
	if (f == r)return 1;
	else return 0;
}
void init() {
	f = r = -1;
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l; j++) {
			map[i][j] = 0;
			visited[i][j] = 0;
		}
	}
}
void bfs(int y, int x) {
	enQ(y, x, 0);
	visited[y][x] = 1;
	while (empty() == 0) {
		int tx = peek().x;
		int ty = peek().y;
		int tstep = peek().step;
		if (ty == end_y && tx == end_x) {
			printf("%d\n", tstep);
			return;
		}
		deQ();
		for (int i = 0; i < 8; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			//if (ny == end_y && nx == end_x) {
			//	printf("%d\n", tstep + 1);
			//	return;
			//}
			if (0 <= nx && nx < l && 0 <= ny && ny < l&&visited[ny][nx] == 0) {
				enQ(ny, nx, tstep + 1);
				visited[ny][nx] = 1;
			}
		}
	}
	printf("%d\n", 0);//±î¸ÔÀ¸¸é ¾ÈµÊ! µµ´Þ ¸øÇÒ°æ¿ì´Â °Á 0ÀÓ!!!
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &testcase);
	for (int test = 0; test < testcase; test++) {
		scanf("%d\n%d %d\n%d %d", &l, &start_y, &start_x, &end_y, &end_x);
		//if (start_y == end_y && start_y == end_y) {
		//	printf("%d\n", 0);
		//	continue;
		//}
		bfs(start_y, start_x);

		init();
	}
	return 0;
}
/*
5
28
0
200
*/