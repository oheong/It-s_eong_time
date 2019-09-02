#include<stdio.h>
#define SIZE 50
int map[SIZE][SIZE], visited[SIZE][SIZE], bx[4] = { 1,-1,0,0 }, by[4] = { 0,0,1,-1 };
int N, M, K, f = -1, r = -1, testcase, count;
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
	if (f == r)return 1;
	else return 0;
}
void init() {
	f = r = -1;
	count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = 0;
			map[i][j] = 0;
		}
	}
}
void bfs(int y, int x) {
	visited[y][x] = 1;
	enQ(y, x);
	while (empty() == 0) {
		int tx = peek().x;
		int ty = peek().y;
		deQ();
		for (int i = 0; i < 4; i++) {
			int nx = tx + bx[i];
			int ny = ty + by[i];
			if (0 <= nx && nx < M && 0 <= ny && ny < N&&visited[ny][nx] == 0 && map[ny][nx] == 1) {
				enQ(ny, nx);
				visited[ny][nx] = 1;
			}
		}
	}
}
int main() {
	int a, b;
	//freopen("Text.txt", "r", stdin);
	scanf("%d", &testcase);
	for (int test = 0; test < testcase; test++) {
		scanf("%d %d %d", &M, &N, &K);//가로, 세로
		for (int i = 0; i < K; i++) {
			scanf("%d %d", &a, &b);//x y
			map[b][a] = 1;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 1 && visited[i][j] == 0) {
					count++;
					bfs(i, j);
				}
			}
		}
		printf("%d\n", count);
		init();
	}
	return 0;
}