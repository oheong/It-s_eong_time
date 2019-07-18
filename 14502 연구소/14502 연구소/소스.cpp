#include <stdio.h>
#define SIZE 8
int N, M, max, f = -1, r = -1;
int map[SIZE][SIZE], visited[SIZE][SIZE], copy[SIZE][SIZE], bx[4]{ 1,-1,0,0 }, by[4] = { 0,0,1,-1 };
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
	if (r == f) return 1;
	else return 0;
}
void Copy() {
	f = r = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			copy[i][j] = map[i][j];
			visited[i][j] = 0;
		}
	}
}
void spread(int y, int x) {
	enQ(y, x);
	visited[y][x] = 1;
	while (empty() == 0) {
		int tx = peek().x;
		int ty = peek().y;
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= nx && nx < M && 0 <= ny && ny < N&&visited[ny][nx] == 0 && copy[ny][nx] == 0) {
				enQ(ny, nx);
				visited[ny][nx] = 1;
				copy[ny][nx] = 2;
			}
		}
	}
}
void dfs(int v, int d) {
	if (d == 3) {
		Copy();
		int count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (copy[i][j] == 2 && visited[i][j] == 0)
					spread(i, j);
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (copy[i][j] == 0)
					count++;
			}
		}
		if (count > max) max = count;
		return;
	}
	for (int i = v + 1; i < N*M; i++) {
		int y = i / M;
		int x = i % M;
		if (map[y][x] == 0) {
			map[y][x] = 1;
			dfs(i, d + 1);
			map[y][x] = 0;
		}
	}
}
int main() {
	//freopen("Text.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < M*N; i++) {
		int y = i / M;
		int x = i % M;
		if (map[y][x] == 0) {
			map[y][x] = 1;
			dfs(i, 1);
			map[y][x] = 0;
		}
	}
	printf("%d\n", max);
	return 0;
}