#include <stdio.h>
#define SIZE 300
int N, M, count, final_value, f = -1, r = -1, zero_count;
int map[SIZE][SIZE], visited[SIZE][SIZE], bx[4] = { 1,-1,0,0 }, by[4] = { 0,0,1,-1 };
typedef struct { int y; int x; }Queue;
Queue q[SIZE*SIZE];
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
void init() {
	f = r = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = 0;
		}
	}
}
int abs(int z) {
	if (z < 0)return 0;
	else return z;
}
void bfs(int y, int x) {
	enQ(y, x);
	visited[y][x] = 1;
	while (empty() == 0) {
		int tx = peek().x;
		int ty = peek().y;
		deQ();
		for (int i = 0; i < 4; i++) {
			int nx = tx + bx[i];
			int ny = ty + by[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < M) {
				if (map[ny][nx] != 0 && visited[ny][nx] == 0) {
					enQ(ny, nx);
					visited[ny][nx] = 1;
				}
				else if (map[ny][nx] == 0 && visited[ny][nx] == 0) {
					zero_count++;
				}
			}
		}
		map[ty][tx] = abs(map[ty][tx] - zero_count);//음수처리해주새얌
		zero_count = 0;
	}
}
void dfs(int d) {
	if (count >= 2) { //답 출력
		final_value = d - 1;
		return;
	}
	if (d > 1 && count == 0) {
		final_value = 0;
		return;
	}
	count = 0;
	for (int i = 1; i < N - 1; i++) {
		for (int j = 1; j < M - 1; j++) {
			if (map[i][j] != 0 && visited[i][j] == 0) {
				count++;
				bfs(i, j);
			}
		}
	}
	init();
	dfs(d + 1);
}
int main() {
	//freopen("Text.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	dfs(0);
	printf("%d\n", final_value);
	return 0;
}