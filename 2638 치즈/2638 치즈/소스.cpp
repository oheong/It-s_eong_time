#include <stdio.h>
#define SIZE 100
int N, M, f = -1, r = -1, count,flag;
int map[SIZE][SIZE], visited[SIZE][SIZE], temp_map[SIZE][SIZE], by[4] = { 0,0,1,-1 }, bx[4] = { 1,-1,0,0 };
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
	if (f == r)return 1;
	else return 0;
}
void init() {
	flag = 0;
	f = r = -1;
	count++;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = 0;
			map[i][j] -= temp_map[i][j];
			temp_map[i][j] = 0;
		}
	}
}
void air_bfs() {
	enQ(0, 0);
	visited[0][0] = 1;
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		deQ();
		int air = 0;
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < M&&visited[ny][nx] == 0 && map[ny][nx] == 0) {
				enQ(ny, nx);
				visited[ny][nx] = 1;
			}
		}
	}
}
void inner_air() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0 && visited[i][j] == 0) {
				map[i][j] = 2;
				temp_map[i][j] = 2;
			}
		}
	}
}
void cheese_bfs(int y, int x) {
	enQ(y, x);
	visited[y][x] = 1;
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		deQ();
		int air = 0;
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (visited[ny][nx] == 0 && map[ny][nx] == 1) {
				enQ(ny, nx);
				visited[ny][nx] = 1;
			}
			if (map[ny][nx] == 0) air++;
		}
		if (air >= 2)temp_map[ty][tx] = 1;
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	while (1) {
		air_bfs();
		inner_air();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 1 && visited[i][j] == 0) {
					cheese_bfs(i, j);
					flag = 1;
				}
			}
		}
		if (flag == 1)
			init();
		else break;
	}
	printf("%d\n", count);
	return 0;
}

/*
8 9
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 1 1 0 0 0 1 1 0
0 1 0 1 1 1 0 1 0
0 1 0 0 1 0 0 1 0
0 1 0 1 1 1 0 1 0
0 1 1 0 0 0 1 1 0
0 0 0 0 0 0 0 0 0
*/