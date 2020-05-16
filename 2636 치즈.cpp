#include <stdio.h>
#define SIZE 105
int N, M, f, r, cheese_count;
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
void bfs_cheese(int y, int x) {
	f = r = -1;
	enQ(y, x);
	visited[y][x] = 1;
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		deQ();
		int count = 0;
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (map[ny][nx] == 0 && visited[ny][nx] == 9) {
				count++;
			}

			else if (map[ny][nx] == 1 && visited[ny][nx] == 0) {
				visited[ny][nx] = 1;
				enQ(ny, nx);
			}
		}
		if (count != 0) {
			visited[ty][tx] = 5;
		}
	}
}
int bfs_air() {
	f = r = -1;
	enQ(0, 0);
	visited[0][0] = 9;
	int cnt = 1;
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		deQ();
		int count = 0;
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < M&&visited[ny][nx] == 0 && map[ny][nx] == 0) {
				enQ(ny, nx);
				visited[ny][nx] = 9;
				cnt++;
			}
		}
	}
	return cnt;
}
int init() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1)
				cnt++;
			if (visited[i][j] == 5)
				map[i][j] = 0;
			visited[i][j] = 0;
		}
	}
	return cnt;
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
		int temp_count = init();
		if (temp_count == 0)break;
		cheese_count = temp_count;
		if (bfs_air() == N * M)break;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 1 && visited[i][j] == 0)
					bfs_cheese(i, j);
			}
		}
		time++;
	}
	printf("%d\n%d\n", time, cheese_count);
	return 0;
}