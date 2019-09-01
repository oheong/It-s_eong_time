#include <stdio.h>
#define SIZE 52
int N, K, f = -1, r = -1, min = 2123456789;
int map[SIZE][SIZE + 2], visited[SIZE][SIZE + 2], by[4] = { -1,0,1,0 }, bx[4] = { 0,1,0,-1 };
typedef struct { int y; int x; int step; }Queue;
Queue q[SIZE*SIZE * 6];
void enQ(int y, int x, int step) {
	r++;
	q[r].y = y;
	q[r].x = x;
	q[r].step = step;
}
void deQ() { f++; }
Queue peek() { return q[f + 1]; }
int empty() {
	if (r == f)return 1;
	else return 0;
}
void init(int n) {
	if (n == 1) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= N + 2; j++) {
				map[i][j] = -1;
			}
		}
		map[0][0] = 5;
		map[N - 1][N + 1] = 5;
	}
	f = r = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= N; j++) {
			visited[i][j] = 0;
		}
	}
	visited[N - 1][N + 1] = 0;
}
int can_i_go(int i, int ty, int tx, int ny, int nx) {//다음 칸에 갈수 있는지 없는지?
	if (map[ty][tx] == 0) {//지금 0모양이고
		if (i == 2) {//이쪽에 길이있냐?
			if (map[ny][nx] == 2 || map[ny][nx] == 3 || map[ny][nx] == 4) return 1;
		}
		else if (i == 1) {
			if (map[ny][nx] == 1 || map[ny][nx] == 3 || map[ny][nx] == 5) return 1;
		}
	}
	else if (map[ty][tx] == 1) {
		if (i == 2) {
			if (map[ny][nx] == 2 || map[ny][nx] == 3 || map[ny][nx] == 4) return 1;
		}
		else if (i == 3) {
			if (map[ny][nx] == 0 || map[ny][nx] == 2 || map[ny][nx] == 5) return 1;
		}
	}
	else if (map[ty][tx] == 2) {
		if (i == 1) {
			if (map[ny][nx] == 1 || map[ny][nx] == 3 || map[ny][nx] == 5) return 1;
		}
		else if (i == 0) {
			if (map[ny][nx] == 0 || map[ny][nx] == 1 || map[ny][nx] == 4) return 1;
		}
	}
	else if (map[ty][tx] == 3) {
		if (i == 3) {
			if (map[ny][nx] == 0 || map[ny][nx] == 2 || map[ny][nx] == 5) return 1;
		}
		else if (i == 0) {
			if (map[ny][nx] == 0 || map[ny][nx] == 1 || map[ny][nx] == 4) return 1;
		}
	}
	else if (map[ty][tx] == 4) {
		if (i == 2) {
			if (map[ny][nx] == 2 || map[ny][nx] == 3 || map[ny][nx] == 4) return 1;
		}
		else if (i == 0) {
			if (map[ny][nx] == 0 || map[ny][nx] == 1 || map[ny][nx] == 4) return 1;
		}
	}
	else if (map[ty][tx] == 5) {
		if (i == 1) {
			if (map[ny][nx] == 1 || map[ny][nx] == 3 || map[ny][nx] == 5) return 1;
		}
		else if (i == 3) {
			if (map[ny][nx] == 0 || map[ny][nx] == 2 || map[ny][nx] == 5) return 1;
		}
	}
	return 0;
}
void bfs() {
	enQ(0, 0, 0);
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		int tstep = peek().step;
		deQ();
		if (ty == N - 1 && tx == N + 1) {
			if (min > tstep)min = tstep;
			continue;
		}
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < N && 0 < nx&&nx <= N + 1 && visited[ny][nx] == 0 && 0 <= map[ny][nx] && map[ny][nx] <= 5) {
				if (can_i_go(i, ty, tx, ny, nx) == 1) {//다음꺼 갈 수 있냐?
					enQ(ny, nx, tstep + 1);
					visited[ny][nx] = tstep + 1;
					break;
				}
			}
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d", &N, &K);
	init(1);
	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	if (K == 0)
		bfs();
	else if (K == 1) {
		//init(2);
		for (int i = 0; i < N; i++) {
			for (int j = 1; j <= N; j++) {
				int t = map[i][j];
				if (t == -1)continue;
				for (int line = 0; line < 6; line++) {
					if (line == t)continue;
					map[i][j] = line;
					bfs();
					init(2);
				}
				map[i][j] = t;
			}
		}
	}
	if (min == 2123456789)printf("%d\n", -1);
	else printf("%d\n", min - 1);
	return 0;
}