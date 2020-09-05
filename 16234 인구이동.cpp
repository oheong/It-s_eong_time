#include <stdio.h>
#define SIZE 5//0
int N, L, R, f, r, ans;
int map[SIZE][SIZE], visited[SIZE][SIZE], change[SIZE*SIZE];
int by[4] = { -1,0,1,0 }, bx[4] = { 0,1,0,-1 };
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
int abs(int a) {
	if (a < 0)return -1 * a;
	else return a;
}
void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = change[visited[i][j]];
			visited[i][j] = 0;
		}
	}
	for (int i = 0; i < N*N; i++) {
		change[i] = 0;
	}
}
void bfs(int y, int x, int num) {
	f = r = -1;
	enQ(y, x);
	visited[y][x] = num;
	int count = 1;
	int sum = map[y][x];
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			int cha = abs(map[ty][tx] - map[ny][nx]);
			if (0 <= ny && ny < N && 0 <= nx && nx < N&&visited[ny][nx] == 0 && L <= cha && cha <= R) {
				count++;
				sum += map[ny][nx];
				visited[ny][nx] = num;
				enQ(ny, nx);
			}
		}
	}
	if (1 < count) // 한칸짜리가 아님
		change[num] = sum / count;
	else change[num] = map[y][x];
}
void dfs(int d) {
	if (d > 2000)return;
	ans = d;
	int num = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == 0) {
				bfs(i, j, num);
				num++;
			}
		}
	}
	if (num == N * N+1) { //전부 한칸짜리라 더이상 인구이동할곳이 없음
		return;
	}
	else {
		init();
		dfs(d + 1);
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d %d", &N, &L, &R);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	dfs(0);
	printf("%d\n", ans);
	return 0;
}