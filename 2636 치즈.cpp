#include <stdio.h>
#define SIZE 105
int N, M, f, r, cheese;
int map[SIZE][SIZE], visited[SIZE][SIZE];
int by[4] = { 0,0,1,-1 }, bx[4] = { 1,-1,0,0 };
typedef struct { int y; int x; }Queue;
Queue q[SIZE*SIZE];
void enQ(int y, int x) {
	r++;
	q[r].y = y;
	q[r].x = x;
}
void deQ() { f++; }
int empty() {
	if (f == r)return 1;
	else return 0;
}
Queue peek() { return q[f + 1]; }
int bfs(int y, int x) {
	f = r = -1;
	enQ(y, x);
	visited[y][x] = 1;
	int count = 1;
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < M && visited[ny][nx] == 0) {
				if (map[ny][nx] == 0) {
					enQ(ny, nx);
					visited[ny][nx] = 1;
					count++;
				}
				else {
					visited[ny][nx] = 9;
				}
			}
		}
	}
	return count;
}
int init() {
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] == 9) {
				count++;
				map[i][j] = 0;
			}
			visited[i][j] = 0;
		}
	}
	return count;
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	int time = 0;
	while (1) {
		if (bfs(0, 0) == N * M)
			break;
		cheese = init();
		time++;
	}
	printf("%d\n%d\n", time, cheese);
	return 0;
}