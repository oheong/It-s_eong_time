#include <stdio.h>
#define SIZE 50
int N, M, R, G, c_count, f, r, max;
int map[SIZE][SIZE], bfs_visited[2][SIZE][SIZE], dfs_visited[10];
int by[4] = { 0,0,1,-1 }, bx[4] = { 1,-1,0,0 };
typedef struct { int c; int y; int x; } Queue;
Queue color[10], q[SIZE*SIZE*SIZE*SIZE];
void enQ(int y, int x, int c) {
	r++;
	q[r].c = c;
	q[r].y = y;
	q[r].x = x;
}
void deQ() { f++; }
int empty() {
	if (r == f) return 1;
	return 0;
}
Queue peek() {
	return q[f + 1];
}
int init() {
	int flower = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] != 0 && bfs_visited[0][i][j] != 0 && bfs_visited[0][i][j] == bfs_visited[1][i][j])
				flower++;
			bfs_visited[0][i][j] = 0;
			bfs_visited[1][i][j] = 0;
		}
	}
	return flower;
}
int change(int tc) {
	return (tc + 1) % 2;
}
void bfs() {
	f = r = -1;
	for (int i = 0; i < c_count; i++) {
		if (dfs_visited[i] != 0) {
			enQ(color[i].y, color[i].x, dfs_visited[i]);
			bfs_visited[dfs_visited[i] % 2][color[i].y][color[i].x] = 1;
		}
	}
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		int tc = peek().c;
		deQ();
		if (bfs_visited[change(tc)][ty][tx] == bfs_visited[tc % 2][ty][tx]) continue;
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < M&& map[ny][nx] != 0 && bfs_visited[tc % 2][ny][nx] == 0) {
				enQ(ny, nx, tc);
				bfs_visited[tc % 2][ny][nx] = bfs_visited[tc % 2][ty][tx] + 1;
			}
		}
	}
}
void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", bfs_visited[0][i][j]);
		}
		printf("\t");
		for (int j = 0; j < M; j++) {
			printf("%d ", bfs_visited[1][i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void Rdfs(int d, int n) {
	if (d == R) {
		bfs();
		//print();
		int temp = init();
		if (max < temp)max = temp;
		return;
	}
	for (int i = n; i < c_count; i++) {
		if (dfs_visited[i] == 0) { // red 2
			dfs_visited[i] = 2;
			Rdfs(d + 1, i);
			dfs_visited[i] = 0;
		}
	}
}
void Gdfs(int d, int n) {
	if (d == G) {
		Rdfs(0, 0);
		return;
	}
	for (int i = n; i < c_count; i++) {
		if (dfs_visited[i] == 0) { // green 1
			dfs_visited[i] = 1;
			Gdfs(d + 1, i);
			dfs_visited[i] = 0;
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d %d %d", &N, &M, &G, &R);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) {
				color[c_count].y = i;
				color[c_count++].x = j;
			}
		}
	}
	// 배양액을 뿌릴 수 있는 자리 중 G와 R 골라서 조합 만들기
	Gdfs(0, 0);
	printf("%d\n", max);
	return 0;

	//4? 5? 눈감을때 틀림 아오ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ
}