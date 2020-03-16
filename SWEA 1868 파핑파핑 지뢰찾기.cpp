#include <stdio.h>
#define SIZE 310
int T, N, f, r, ans;
char bomb[SIZE][SIZE];
int map[SIZE][SIZE], visited[SIZE][SIZE];
int by[8] = { -1,-1,0,1,1,1,0,-1 }, bx[8] = { 0,1,1,1,0,-1,-1,-1 };
typedef struct { int y; int x; }Queue;
Queue q[SIZE*SIZE];
void enQ(int y, int x) {
	r++;
	q[r].y = y;
	q[r].x = x;
}
void deQ() { f++; }
int empty() {
	if (f == r)return 1;
	else return 0;
}
Queue peek() { return q[f + 1]; }
int is_ok(int y, int x) {
	if (0 <= y && y < N && 0 <= x && x < N)return 1;
	return 0;
}
void change_map() {
	ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 0;
			map[i][j] = 0;
			if (bomb[i][j] == '*') {
				map[i][j] = 9;
				continue;
			}
			for (int n = 0; n < 8; n++) {
				if (is_ok(i + by[n], j + bx[n]) == 0)continue;
				if (bomb[i + by[n]][j + bx[n]] == '*')
					map[i][j]++;
			}
		}
	}
}
void bfs(int y, int x, int cnt) {
	f = r = -1;
	enQ(y, x);
	visited[y][x] = cnt;
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		deQ();
		for (int i = 0; i < 8; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (is_ok(ny, nx) == 1 && visited[ny][nx] == 0 && map[ny][nx] != 9) {
				if (map[ny][nx] == 0) enQ(ny, nx);
				visited[ny][nx] = cnt;
			}
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d\n", &N);
		for (int i = 0; i < N; i++) {
			scanf("%s", &bomb[i]);
		}
		change_map();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 9)continue;
				if (map[i][j]==0&&visited[i][j] == 0) {
					bfs(i, j, ++ans);

				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 9)continue;
				if (visited[i][j] == 0)ans++;
			}
		}
		printf("#%d %d\n", test + 1, ans);
	}
	return 0;
}