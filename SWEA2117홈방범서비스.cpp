#include <stdio.h>
#define SIZE 20
int N, M, T, f, r, cost, max_house_cnt;
int map[SIZE][SIZE], visited[SIZE][SIZE];
int by[4] = { -1,0,1,0 }, bx[4] = { 0,1,0,-1 };
typedef struct { int y; int x; int step; }Queue;
Queue q[SIZE*SIZE*SIZE*SIZE];
void enQ(int y, int x, int step) {
	r++;
	q[r].y = y;
	q[r].x = x;
	q[r].step = step;
}
void deQ() { f++; }
Queue peek() { return q[f + 1]; }
int empty() {
	if (f == r)return 1;
	else return 0;
}
int bfs(int y, int x, int num, int k) {
	f = r = -1;
	int count = 0;
	enQ(y, x, 1);
	visited[y][x] = num;
	if (map[y][x] == 1)count = 1;
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		int tstep = peek().step;
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < N&&visited[ny][nx] != num && tstep < k) {
				enQ(ny, nx, tstep + 1);
				visited[ny][nx] = num;
				if (map[ny][nx] == 1)count++;
			}
		}
	}
	return count * M; // 각 집별 사용료 리턴
}
int main() {
	//freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d %d", &N, &M);
		max_house_cnt = 1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		for (int k = 2; k <= N + 1; k++) {
			cost = k * k + (k - 1)*(k - 1);
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					int pay = bfs(i, j, (i*N + j)*k + 1, k);
					if (0 <= pay - cost && max_house_cnt < pay / M) {
						max_house_cnt = pay / M;
					}
				}
			}
		}
		printf("#%d %d\n", test + 1, max_house_cnt);
	}
	return 0;
}