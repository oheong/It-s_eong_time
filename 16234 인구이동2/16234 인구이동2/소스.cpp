#include <stdio.h>
#define SIZE 50
int N, L, R, f = -1, r = -1, sum, count, ans;
int map[SIZE][SIZE], visited[SIZE][SIZE], by[4] = { 0,0,1,-1 }, bx[4] = { 1,-1,0,0 };
bool flag;
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
int abs(int a) {
	if (a < 0)return -1 * a;
	else return a;
}
void init() {
	flag = false;
	f = r = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 0;
		}
	}
}
void getavg() {
	int temp = sum / count;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == 1) {
				map[i][j] = temp;
				visited[i][j] = 2;
			}
		}
	}
}
void bfs(int y, int x) {
	enQ(y, x);
	visited[y][x] = 1;
	count = 1;
	sum = map[y][x];
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			int t = abs(map[ty][tx] - map[ny][nx]);
			if (0 <= ny && ny < N && 0 <= nx && nx < N&&visited[ny][nx] == 0 && L <= t && t <= R) {
				visited[ny][nx] = 1;
				enQ(ny, nx);
				sum += map[ny][nx];
				count++;
			}
		}
	}
	if (count > 1) {
		flag = true;
		getavg();
	}
	else
		visited[y][x] = 2;
}
void dfs(int d) {
	if (d > 2000) return;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == 0) {
				bfs(i, j);
			}
		}
	}
	if (flag == false) {
		ans = d;
		return;
	}
	else {
		init();
		dfs(d + 1);
	}
}
int main() {
	//freopen("Text.txt", "r", stdin);
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