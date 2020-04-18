#include <stdio.h>
#define SIZE 10
int T, f, r;
int map[SIZE][SIZE], visited[SIZE][SIZE];
int by[8] = { -1,-1,0,1,1,1,0,-1 }, bx[8] = { 0,1,1,1,0,-1,-1,-1 };
typedef struct { int y; int x; }Queue;
Queue q[SIZE*SIZE];
void enQ(int y, int x) {
	r++;
	q[r].x = x;
	q[r].y = y;
}
void deQ() { f++; }
int empty() {
	if (f == r)return 1;
	else return 0;
}
Queue peek() { return q[f + 1]; }

void bfs(int y, int x) {
	f = r = -1;
	enQ(y, x);
	visited[y][x] = 1;
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		deQ();
		for (int i = 0; i < 8; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < SIZE && 0 <= nx && nx < SIZE&&map[ny][nx] == 1 && visited[ny][nx] == 0) {
				enQ(ny, nx);
				visited[ny][nx] = 1;
			}
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				scanf("%d", &map[i][j]);
				visited[i][j] = 0;
			}
		}
		int ans = 0;
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				if (map[i][j] == 1 && visited[i][j] == 0) {
					bfs(i, j);
					ans++;
				}
			}
		}
		printf("#%d %d\n", test + 1, ans);
	}
	return 0;
}