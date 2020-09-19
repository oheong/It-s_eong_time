#include <stdio.h>
#define SIZE 50
int N, M, f, r, virus_count, min = 2123456789;
int map[SIZE][SIZE], visited[SIZE][SIZE];
typedef struct { int y; int x; }Queue;
Queue q[SIZE*SIZE];
typedef struct { int y; int x; int v; }VIRUS;
VIRUS virus[10];
int by[4] = { -1,0,1,0 }, bx[4] = { 0,1,0,-1 };
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
int get_ans() {
	int max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 2) {
				visited[i][j] = 0;
				continue;
			}
			if (max < visited[i][j])
				max = visited[i][j];
			if (map[i][j] == 0 && visited[i][j] == -1)
				max = 2123456789;
			visited[i][j] = 0;
		}
	}
	return max;
}
void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1)visited[i][j] = 0;
			else visited[i][j] = -1;
		}
	}
}
void bfs() {
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < N&&map[ny][nx] != 1 && visited[ny][nx] == -1) {
				enQ(ny, nx);
				visited[ny][nx] = visited[ty][tx] + 1;
			}
		}
	}
}
void dfs(int d, int n) {
	if (d == M) {
		f = r = -1;
		init();
		for (int i = 0; i < virus_count; i++) {
			if (virus[i].v == 1) {
				enQ(virus[i].y, virus[i].x);
				visited[virus[i].y][virus[i].x] = 0;
			}
		}

		bfs();

		int temp = get_ans();

		if (temp < min)
			min = temp;

		return;
	}
	for (int i = n; i < virus_count; i++) {
		if (virus[i].v == 0) {
			virus[i].v = 1;
			dfs(d + 1, i);
			virus[i].v = 0;
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
	if (min == 2123456789)min = -1;
	printf("%d\n", min);
	return 0;
}