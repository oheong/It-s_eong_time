#include <stdio.h>
#define SIZE 100
int N, M, K, f = -1, r = -1, count;
int map[SIZE][SIZE], visited[SIZE][SIZE], value[SIZE*SIZE], by[4] = { 0,0,-1,1 }, bx[4] = { 1,-1,0,0 };
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
int bfs(int y, int x) {
	f = r = -1;
	count = 1;
	enQ(y, x);
	visited[y][x] = 1;
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < M && 0 <= nx && nx < N&&visited[ny][nx] == 0 && map[ny][nx] == 0) {
				enQ(ny, nx);
				visited[ny][nx] = 1;
				count++;
			}
		}
	}
	return count;
}
void sort(int t) {
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < t - 1 - i; j++) {
			if (value[j] > value[j + 1]) {
				int temp = value[j + 1];
				value[j + 1] = value[j];
				value[j] = temp;
			}
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d %d", &M, &N, &K);
	int sx, sy, ex, ey;
	for (int i = 0; i < K; i++) {
		scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
		for (int i = M - ey; i < M - sy; i++) {
			for (int j = sx; j < ex; j++) {
				map[i][j] = 1;
			}
		}
	}
	int t = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == 0 && map[i][j] == 0) {
				value[t++] = bfs(i, j);
			}
		}
	}
	sort(t);
	printf("%d\n", t);
	for (int i = 0; i < t; i++) printf("%d ", value[i]);
	printf("\n");
	return 0;
}