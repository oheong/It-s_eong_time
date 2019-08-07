#include <stdio.h>
#define SIZE 17
int N, ans, r = -1, f = -1;
int map[SIZE][SIZE], by[3] = { 0,1,1 }, bx[3] = { 1,1,0 }, check[3], ny, nx;
typedef struct { int state; int y; int x; }Queue;
Queue q[10000000];
void enQ(int state, int y, int x) {
	r++;
	q[r].state = state;
	q[r].y = y;
	q[r].x = x;
}
void deQ() { f++; }
Queue peek() { return q[f + 1]; }
int empty() {
	if (r == f)return 1;
	else return 0;
}
int is_here(int y, int x) {
	if (y < 0 || y >= N || x < 0 || x >= N)return 0;
	else return 1;
}
int is_dir1(int y, int x) {
	if (map[y + by[0]][x + bx[0]] == 0 && map[y + by[1]][x + bx[1]] == 0 && map[y + by[2]][x + bx[2]] == 0)
		return 1;
	else return 0;
}
void init() {
	for (int i = 0; i < 3; i++)check[i] = 0;
}
void bfs(int state, int y, int x) {
	enQ(state, y, x);
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		int tstate = peek().state;
		if (ty == N - 1 && tx == N - 1) {
			ans++;
		}
		deQ();
		if (tstate == 0) {
			ny = ty + by[0];
			nx = tx + bx[0];
			if (is_here(ny, nx) == 1 && map[ny][nx] == 0)
				enQ(0, ny, nx);

			ny = ty + by[1];
			nx = tx + bx[1];
			if (is_here(ny, nx) == 1 && is_dir1(ty, tx) == 1)
				enQ(1, ny, nx);
		}
		else if (tstate == 1) {
			ny = ty + by[0];
			nx = tx + bx[0];
			if (is_here(ny, nx) == 1 && map[ny][nx] == 0)
				enQ(0, ny, nx);

			ny = ty + by[1];
			nx = tx + bx[1];
			if (is_here(ny, nx) == 1 && is_dir1(ty, tx) == 1)
				enQ(1, ny, nx);

			ny = ty + by[2];
			nx = tx + bx[2];
			if (is_here(ny, nx) == 1 && map[ny][nx] == 0)
				enQ(2, ny, nx);
		}
		else {
			ny = ty + by[1];
			nx = tx + bx[1];
			if (is_here(ny, nx) == 1 && is_dir1(ty, tx) == 1)
				enQ(1, ny, nx);

			ny = ty + by[2];
			nx = tx + bx[2];
			if (is_here(ny, nx) == 1 && map[ny][nx] == 0)
				enQ(2, ny, nx);
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	bfs(0, 0, 1);
	printf("%d\n", ans);
	return 0;
}

/*
16
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0
0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

98¸¸ ¤µ¤²
https://www.acmicpc.net/board/view/39246

*/