#include <stdio.h>
#define SIZE 101
int N, M, f = -1, r = -1, cheese_count, t;
int map[SIZE][SIZE], visited[SIZE][SIZE], by[4] = { 0,0,1,-1 }, bx[4] = { 1,-1,0,0 };
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

void bfs(int y, int x) {
	visited[y][x] = 1;
	enQ(y, x);
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny <= N && 0 <= nx && nx <= M) {
				if (map[ny][nx] == 0 && visited[ny][nx] == 0) {
					enQ(ny, nx);
					visited[ny][nx] = 1;//빈공간
				}
				else if (map[ny][nx] == 1) {
					visited[ny][nx] = 2;//공기중에 노출된 치즈
				}
			}
		}
	}
}
int remain_cheese() {
	int cheese = 0;
	f = r = -1;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (map[i][j] == 1 && visited[i][j] == 0) cheese++;
			if (visited[i][j] == 2)map[i][j] = 0;
			visited[i][j] = 0;
		}
	}
	return cheese;
}
int time() {
	t++;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (visited[i][j] == 0) return 0;
		}
	}
	return 1;
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	while (1) {
		cheese_count = remain_cheese();
		bfs(0, 0);
		if (time() == 1)break;
	}
	printf("%d\n%d\n", t, cheese_count);
	return 0;
}