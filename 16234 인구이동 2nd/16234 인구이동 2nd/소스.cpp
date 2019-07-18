#include <stdio.h>
#define SIZE 50
int N, L, R, f = -1, r = -1, count, sum;
int map[SIZE][SIZE], visited[SIZE][SIZE], bx[4] = { 1,-1,0,0 }, by[4] = { 0,0,1,-1 };
typedef struct { int y; int x; }Queue;
Queue q[SIZE*SIZE];
bool flag = false;
void enQ(int y, int x) {
	r++;
	q[r].x = x;
	q[r].y = y;
}
void deQ() { f++; }
Queue peek() { return q[f + 1]; }
int empty() {
	if (r == f)return 1;
	else return 0;
}
void init() {
	f = r = -1;
	flag = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 0;
		}
	}
}
int abs(int a) {
	if (a < 0)return -1 * a;
	else return a;
}
void bfs(int y, int x) {
	count = 1;
	enQ(y, x);
	visited[y][x] = 1;
	sum = map[y][x];
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			int chaE = abs(map[ty][tx] - map[ny][nx]);
			if (0 <= nx && nx < N && 0 <= ny && ny < N&&visited[ny][nx] == 0 && L <= chaE && chaE <= R) {
				visited[ny][nx] = 1;
				enQ(ny, nx);
				count++;
				flag = true;
				sum += map[ny][nx];
			}
		}
	}
	if (count == 1) visited[y][x] = 2;
	else {
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
		printf("%d\n", d);
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
	return 0;
}