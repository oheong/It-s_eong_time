#include <stdio.h>
#define SIZE 8
int N, M, max, f = -1, r = -1;
int map[SIZE][SIZE], visited[SIZE][SIZE], copymap[SIZE][SIZE], by[4] = { 0,0,1,-1 }, bx[4] = { 1,-1,0,0 };
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
	if (f == r)return 1;
	else return 0;
}
void copy() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			copymap[i][j] = map[i][j];
		}
	}
}
void init() {
	f = r = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = 0;
		}
	}
}
int counting() {
	int c = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (copymap[i][j] == 0)c++;
		}
	}
	return c;
}
void bfs(int y, int x) {
	enQ(y, x);
	visited[y][x] = 1;
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < M&&visited[ny][nx] == 0 && copymap[ny][nx] == 0) {
				enQ(ny, nx);
				visited[ny][nx] = 1;
				copymap[ny][nx] = 2;
			}
		}
	}
}
void dfs(int d, int n) {
	if (d == 3) {
		//벽 다세웠으니까 copy해서 바이러스 퍼트려보기
		copy();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (copymap[i][j] == 2 && visited[i][j] == 0) {
					bfs(i, j);
				}
			}
		}
		int temp = counting();
		if (max < temp)max = temp;
		init();
		return;
	}
	for (int i = n; i < M*N; i++) {
		int y = i / M;
		int x = i % M;
		if (map[y][x] == 0) {
			map[y][x] = 1;
			dfs(d + 1, i);
			map[y][x] = 0;
		}
	}
}
int main() {
	//freopen("Text.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	dfs(0, 0);
	printf("%d\n", max);
	return 0;
}