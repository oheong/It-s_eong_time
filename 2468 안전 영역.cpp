#include <stdio.h>
#define SIZE 100
int N, f = -1, r = -1, max, count, final_value;
int map[SIZE][SIZE], visited[SIZE][SIZE], bx[4] = { 1,-1,0,0 }, by[4] = { 0,0,1,-1 };
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
	if (f == r) return 1;
	else return 0;
}
void bfs(int y, int x, int h) {
	visited[y][x] = 1;
	enQ(y, x);
	while (empty() == 0) {
		int tx = peek().x;
		int ty = peek().y;
		deQ();
		for (int i = 0; i < 4; i++) {
			int nx = tx + bx[i];
			int ny = ty + by[i];
			if (0 <= nx && nx < N && 0 <= nx && nx < N&&visited[ny][nx] == 0 && map[ny][nx] >= h) {
				visited[ny][nx] = 1;
				enQ(ny, nx);
			}
		}
	}
}
void init() {
	count = 0;
	f = r = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 0;
		}
	}
}
int main() {
	//freopen("Text.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (max < map[i][j])max = map[i][j];
		}
	}
	for (int m = 0; m <= max; m++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] >= m && visited[i][j] == 0) {
					count++;
					bfs(i, j, m);
				}
			}
		}
		if (count > final_value)final_value = count;
		init();
	}
	printf("%d\n", final_value);
	return 0;
}