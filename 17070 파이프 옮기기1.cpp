#include <stdio.h>
#define SIZE 17
int N, f, r, ans;
int map[SIZE][SIZE], by[3] = { 0,1,1 }, bx[3] = { 1,1,0 };
typedef struct { int y; int x; int dir; }Queue;
Queue q[SIZE*SIZE*SIZE*SIZE*SIZE*SIZE];
void enQ(int y, int x, int dir) {
	r++;
	q[r].y = y;
	q[r].x = x;
	q[r].dir = dir;
}
void deQ() { f++; }
int empty() {
	if (f == r)return 1;
	else return 0;
}
Queue peek() { return q[f + 1]; }
int is_ok(int y, int x, int tdir, int ndir) {
	if (tdir == 0) { // 오른쪽
		if (ndir == 0) {
			if (map[y + by[ndir]][x + bx[ndir]] == 1) return 0;
			else return 1;
		}
		else if (ndir == 1) {
			for (int i = 0; i < 3; i++) {
				if (map[y + by[i]][x + bx[i]] == 1) return 0;
			}
			return 1;
		}
		else return 0;
	}
	else if (tdir == 1) { // 대각선
		if (ndir == 0 || ndir == 2) {
			if (map[y + by[ndir]][x + bx[ndir]] == 1) return 0;
			else return 1;
		}
		else {
			for (int i = 0; i < 3; i++) {
				if (map[y + by[i]][x + bx[i]] == 1) return 0;
			}
			return 1;
		}
	}
	else { // 아래
		if (ndir == 0) return 0;
		else if (ndir == 1) {
			for (int i = 0; i < 3; i++) {
				if (map[y + by[i]][x + bx[i]] == 1) return 0;
			}
			return 1;
		}
		else {
			if (map[y + by[ndir]][x + bx[ndir]] == 1) return 0;
			else return 1;
		}
	}
}
void bfs() {
	f = r = -1;
	enQ(0, 1, 0);
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		int tdir = peek().dir;
		deQ();
		if (ty == N - 1 && tx == N - 1) {
			ans++;
			continue;
		}
		for (int i = 0; i < 3; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (ny < N&&nx < N) {
				if (is_ok(ty, tx, tdir, i) == 1) {
					enQ(ny, nx, i);
				}
			}
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
	bfs();
	printf("%d\n", ans);
	return 0;
}