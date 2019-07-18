#include <stdio.h>
#define SIZE 300
int C, R, V, K, f = -1, r = -1, final_v, final_k;
int visited[SIZE][SIZE], bx[4] = { 1,-1,0,0 }, by[4] = { 0,0,1,-1 };
char map[SIZE][SIZE];
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
void bfs(int y, int x) {
	//v==´Á´ë
	//k==¾ç
	visited[y][x] = 1;
	enQ(y, x);
	while (empty() == 0) {
		int tx = peek().x;
		int ty = peek().y;
		deQ();
		for (int i = 0; i < 4; i++) {
			int nx = tx + bx[i];
			int ny = ty + by[i];
			if (0 <= nx && nx < C && 0 <= ny && ny < R&&visited[ny][nx] == 0 && map[ny][nx] != '#') {
				if (map[ny][nx] == 'v') V++;
				else if (map[ny][nx] == 'k') K++;
				enQ(ny, nx);
				visited[ny][nx] = 1;
			}
		}
	}
	if (K > V) final_k += K;
	else final_v += V;
}
int main() {
	//freopen("Text.txt", "r", stdin);
	scanf("%d %d\n", &R, &C);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j <= C; j++) {
			scanf("%c", &map[i][j]);
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] != '#'&&visited[i][j] == 0) {
				V = K = 0;
				if (map[i][j] == 'v') V++;
				else if (map[i][j] == 'k') K++;
				bfs(i, j);
			}
		}
	}
	printf("%d %d\n", final_k, final_v);//´Á´ë, ¾ç
	return 0;
}