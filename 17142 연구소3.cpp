#include <stdio.h>
#define SIZE 50
int N, M, f = -1, r = -1, virus_count, ans = 2123456789;
int map[SIZE][SIZE], visited[SIZE][SIZE], by[4] = { -1,0,1,0 }, bx[4] = { 0,1,0,-1 };
typedef struct { int y; int x; int visited; }VIRUS;
VIRUS q[SIZE*SIZE], virus[10];
void enQ(int y, int x, int step) {
	r++;
	q[r].y = y;
	q[r].x = x;
	q[r].visited = step;
}
void deQ() { f++; }
VIRUS peek() { return q[f + 1]; }
int empty() {
	if (r == f)return 1;
	else return 0;
}
int init() {
	int max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] != 2 && map[i][j] != 1) {
				if (map[i][j] == 0 && visited[i][j] == 0) max = 2123456789;
				if (visited[i][j] > max)max = visited[i][j];
			}
			visited[i][j] = 0;
		}
	}
	return max;
}
void bfs() {
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		int tstep = peek().visited;
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < N&&visited[ny][nx] == 0 && map[ny][nx] != 1) {
				if (map[ny][nx] == 1) {
					visited[ny][nx] = tstep;
					enQ(ny, nx, tstep);
				}
				else {
					enQ(ny, nx, tstep + 1);
					visited[ny][nx] = tstep + 1;
				}
			}
		}
	}
}
void dfs(int d, int n) {
	if (d == M) {
		f = r = -1;
		for (int i = 0; i < virus_count; i++) {
			if (virus[i].visited == 1) {
				enQ(virus[i].y, virus[i].x, 0);
				visited[virus[i].y][virus[i].x] = -1;
			}
		}
		bfs();
		int temp = init();
		if (temp < ans)ans = temp;
		return;
	}
	for (int i = n; i < virus_count; i++) {
		if (virus[i].visited == 0) {
			virus[i].visited = 1;
			dfs(d + 1, i);
			virus[i].visited = 0;
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) {
				virus[virus_count].y = i;
				virus[virus_count++].x = j;
			}
		}
	}
	dfs(0, 0);
	if (ans == 2123456789)	printf("%d\n", -1);
	else printf("%d\n", ans);
	return 0;
}