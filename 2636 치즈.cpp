#include <stdio.h>
#define SIZE 102
int map[SIZE][SIZE], temp_map[SIZE][SIZE], visited[SIZE][SIZE], by[4] = { 0,0,1,-1 }, bx[4] = { 1,-1,0,0 };
int N, M, f, r, ans;
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
void bfs(int y, int x, int input) {
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
			if (0 <= ny && ny < N && 0 <= nx && nx < M) {
				if (input == 1) {
					if (map[ny][nx] == 0 && visited[ny][nx] == 2) count++;

					if (map[ny][nx] == 1 && visited[ny][nx] == 0) {
						enQ(ny, nx);
						visited[ny][nx] = 1;
					}
				}
				else {
					if (map[ny][nx] == 0 && visited[ny][nx] == 0) {
						enQ(ny, nx);
						visited[ny][nx] = 2;
					}
				}
			}
		}
		if (0 < count) {
			temp_map[ty][tx] = 1;
		}
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
	int time = 0;
	while (1) {
		bfs(0, 0, 0);
		for (int i = 1; i < N; i++) {
			for (int j = 1; j < M; j++) {
				if (map[i][j] == 1 && visited[i][j] == 0) {
					bfs(i, j, 1);
				}
			}
		}
		int count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				visited[i][j] = 0;
				if (temp_map[i][j] == 1) {
					map[i][j] = 0;
					temp_map[i][j] = 0;
					count++;
				}
			}
		}
		if (count != 0) ans = count;
		else {
			printf("%d\n%d\n", time, ans);
			return 0;
		}
		time++;
	}
	return 0;
}