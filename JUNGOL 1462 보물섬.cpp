#include <stdio.h>
#define SIZE 51
int N, M, f = -1, r = -1, ans;
char map[SIZE][SIZE];
int visited[SIZE][SIZE], by[4] = { 0,0,1,-1 }, bx[4] = { 1,-1,0,0 };
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
	if (r == f) return 1;
	else return 0;
}
int init() {
	int max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] > max)max = visited[i][j];
			visited[i][j] = 0;
		}
	}
	return max;
}
void bfs(int y, int x) {
	f = r = -1;
	enQ(y, x, 0);
	visited[y][x] = 1;
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		int tstep = peek().step;
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < M&&visited[ny][nx] == 0 && map[ny][nx] == 'L') {
				enQ(ny, nx, tstep + 1);
				visited[ny][nx] = tstep + 1;
			}
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d\n", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= M; j++) {
			scanf("%c", &map[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'L') {
				bfs(i, j);
				int temp = init();
				if (ans < temp)ans = temp;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
//정올에서는 왜틀렸지,,,?ㅠㅠ