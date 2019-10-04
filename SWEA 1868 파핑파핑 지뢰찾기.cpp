#include <stdio.h>
#define SIZE 301
int T, N, f = -1, r = -1, ans;
char map[SIZE][SIZE], num[SIZE][SIZE];
int visited[SIZE][SIZE], by[8] = { -1,-1,0,1,1,1,0,-1 }, bx[8] = { 0,1,1,1,0,-1,-1,-1 };
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
void find_num() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == '*') {
				num[i][j] = -1;
				continue;
			}
			int count = 0;
			for (int n = 0; n < 8; n++) {
				int ny = i + by[n];
				int nx = j + bx[n];
				if (0 > ny || ny >= N || 0 > nx || nx >= N) continue;
				else if (map[ny][nx] == '*')count++;
			}
			num[i][j] = count;
		}
	}
}
void bfs(int y, int x) {
	enQ(y, x);
	visited[y][x] = 1;
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		deQ();
		for (int i = 0; i < 8; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < N&&visited[ny][nx] == 0) {
				if (num[ny][nx] == 0) enQ(ny, nx);
				visited[ny][nx] = 1;
			}
		}
	}
}
void init() {
	f = r = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (num[i][j] != -1 && visited[i][j] == 0) ans++;
			num[i][j] = 0;
			visited[i][j] = 0;
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d\n", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= N; j++) {
				scanf("%c", &map[i][j]);
			}
		}
		find_num();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (num[i][j] == 0 && visited[i][j] == 0) {
					f = r = -1;
					bfs(i, j);
					ans++;
				}
			}
		}
		init();
		printf("#%d %d\n", test + 1, ans);
		ans = 0;
	}
	return 0;
}