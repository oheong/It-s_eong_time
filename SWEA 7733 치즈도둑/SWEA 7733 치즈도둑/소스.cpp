#include <stdio.h>
#define SIZE 101
int map[SIZE][SIZE], visited[SIZE][SIZE], by[4] = { 0,0,1,-1 }, bx[4] = { 1,-1,0,0 };
int N, T, f = -1, r = -1, max, count;
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
	if (r == f) return 1;
	else return 0;
}
void init() {
	f = r = -1;
	count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 0;
		}
	}
}
void bfs(int y, int x, int day) {
	visited[y][x] = 1;
	enQ(y, x);
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < N&&visited[ny][nx] == 0 && day < map[ny][nx]) {
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
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		max = 0;// ¿Í ÀÌ°É•û¸Ô´Ù´Ï °³¸ÛÃ»;
		for (int day = 0; day <= 100; day++) {
			for (int y = 0; y < N; y++) {
				for (int x = 0; x < N; x++) {
					if (day < map[y][x] && visited[y][x] == 0) {
						bfs(y, x, day);
						count++;
					}
				}
			}
			if (count > max)max = count;
			init();
		}
		printf("#%d %d\n", test + 1, max);
	}
	return 0;
}