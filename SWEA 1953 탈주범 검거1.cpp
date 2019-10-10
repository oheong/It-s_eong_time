#include <stdio.h>
#define SIZE 50
int T, N, M, L, sy, sx, f = -1, r = -1;
int map[SIZE][SIZE], visited[SIZE][SIZE], by[4] = { -1,0,1,0 }, bx[4] = { 0,1,0,-1 };
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
int where_gogo(int y, int x, int dir, int ny, int nx) {
	if (map[y][x] == 1) {
		if (dir == 0) {
			if (map[ny][nx] == 1 || map[ny][nx] == 2 || map[ny][nx] == 5 || map[ny][nx] == 6) return 1;
		}
		else if (dir == 1) {
			if (map[ny][nx] == 1 || map[ny][nx] == 3 || map[ny][nx] == 6 || map[ny][nx] == 7) return 1;
		}
		else if (dir == 2) {
			if (map[ny][nx] == 1 || map[ny][nx] == 2 || map[ny][nx] == 4 || map[ny][nx] == 7) return 1;
		}
		else if (dir == 3) {
			if (map[ny][nx] == 1 || map[ny][nx] == 3 || map[ny][nx] == 4 || map[ny][nx] == 5) return 1;
		}
	}
	else if (map[y][x] == 2) {
		if (dir == 0) {
			if (map[ny][nx] == 1 || map[ny][nx] == 2 || map[ny][nx] == 5 || map[ny][nx] == 6) return 1;
		}
		else if (dir == 2) {
			if (map[ny][nx] == 1 || map[ny][nx] == 2 || map[ny][nx] == 4 || map[ny][nx] == 7) return 1;
		}
	}
	else if (map[y][x] == 3) {
		if (dir == 1) {
			if (map[ny][nx] == 1 || map[ny][nx] == 3 || map[ny][nx] == 6 || map[ny][nx] == 7) return 1;
		}
		else if (dir == 3) {
			if (map[ny][nx] == 1 || map[ny][nx] == 3 || map[ny][nx] == 4 || map[ny][nx] == 5) return 1;
		}
	}
	else if (map[y][x] == 4) {
		if (dir == 0) {
			if (map[ny][nx] == 1 || map[ny][nx] == 2 || map[ny][nx] == 5 || map[ny][nx] == 6) return 1;
		}
		else if (dir == 1) {
			if (map[ny][nx] == 1 || map[ny][nx] == 3 || map[ny][nx] == 6 || map[ny][nx] == 7) return 1;
		}
	}
	else if (map[y][x] == 5) {
		if (dir == 1) {
			if (map[ny][nx] == 1 || map[ny][nx] == 3 || map[ny][nx] == 6 || map[ny][nx] == 7) return 1;
		}
		else if (dir == 2) {
			if (map[ny][nx] == 1 || map[ny][nx] == 2 || map[ny][nx] == 4 || map[ny][nx] == 7) return 1;
		}
	}
	else if (map[y][x] == 6) {
		if (dir == 2) {
			if (map[ny][nx] == 1 || map[ny][nx] == 2 || map[ny][nx] == 4 || map[ny][nx] == 7) return 1;
		}
		else if (dir == 3) {
			if (map[ny][nx] == 1 || map[ny][nx] == 3 || map[ny][nx] == 4 || map[ny][nx] == 5) return 1;
		}
	}
	else if (map[y][x] == 7) {
		if (dir == 0) {
			if (map[ny][nx] == 1 || map[ny][nx] == 2 || map[ny][nx] == 5 || map[ny][nx] == 6) return 1;
		}
		else if (dir == 3) {
			if (map[ny][nx] == 1 || map[ny][nx] == 3 || map[ny][nx] == 4 || map[ny][nx] == 5) return 1;
		}
	}
	return -1;
}
void bfs(int y, int x) {
	enQ(y, x, 1);
	visited[y][x] = 1;
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		int tstep = peek().step;
		if (tstep == L)return;
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < M&&visited[ny][nx] == 0 && map[ny][nx] != 0) {
				if (where_gogo(ty, tx, i, ny, nx) == 1) {
					enQ(ny, nx, tstep + 1);
					visited[ny][nx] = tstep + 1;
				}
			}
		}
	}
}
int init() {
	f = r = -1;
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] != 0)count++;
			visited[i][j] = 0;
		}
	}
	return count;
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d %d %d %d %d", &N, &M, &sy, &sx, &L);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		bfs(sy, sx);
		printf("#%d %d\n", test + 1, init());
	}
	return 0;
}