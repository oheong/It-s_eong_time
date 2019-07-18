#include<stdio.h>
#define SIZE 51
int M, N, min = 2123456789, f = -1, r = -1, count;
char map[SIZE][SIZE], copymap[8][8];
int visited[8][8], bx[4] = { 1,-1,0,0 }, by[4] = { 0,0,1,-1 };
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
	if (f == r) return 1;
	else return 0;
}
void copy(int y, int x) {
	f = r = -1;
	count = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			copymap[i][j] = map[i + y][j + x];
			visited[i][j] = 0;
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
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= nx && nx < 8 && 0 <= ny && ny < 8 && visited[ny][nx] == 0) {
				if (copymap[ty][tx] == copymap[ny][nx]) {
					if (copymap[ty][tx] == 'B')
						copymap[ny][nx] = 'W';
					else
						copymap[ny][nx] = 'B';
					count++;
				}
				enQ(ny, nx);
				visited[ny][nx] = 1;
			}
		}
	}
	if (min > count) min = count;
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d\n", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= M; j++) {
			scanf("%c", &map[i][j]);
		}
	}
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			//½ÃÀÛÁÂÇ¥ 
			copy(i, j);
			bfs(0, 0);

			copy(i, j);
			bfs(7, 7);
		}
	}
	printf("%d\n", min);
	return 0;
}