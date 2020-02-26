#include <stdio.h>
#define SIZE 1000
int N, M, f = -1, r = -1, ans;
int map[SIZE][SIZE], visited[SIZE][SIZE], by[4] = { 0,0,1,-1 }, bx[4] = { 1,-1,0,0 };
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
	if (r == f)return 1;
	else return 0;
}
void bfs() {
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		int tstep = peek().step;
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < M&&visited[ny][nx] == 0 && map[ny][nx] != -1) {
				enQ(ny, nx, tstep + 1);
				visited[ny][nx] = tstep + 1;
			}
		}
	}
}
int check() {
	int max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] == 0)return -1;
			if (visited[i][j] > max)max = visited[i][j];
		}
	}
	return max;
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d", &M, &N);
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) {
				enQ(i, j, 0);
				visited[i][j] = 1;
				count++;
			}
			else if (map[i][j] == -1)visited[i][j] = 1;
		}
	}
	if (count == M * N) {
		printf("%d\n", 0);
		return 0;
	}
	bfs();
	int ans = check();
	printf("%d\n", check());
	return 0;
}