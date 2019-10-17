#include <stdio.h>
#define SIZE 20
int T, N, M, K, f = -1, r = -1, ans;
int map[SIZE][SIZE], visited[SIZE][SIZE], by[4] = { 0,0,1,-1 }, bx[4] = { 1,-1,0,0 };
typedef struct { int y; int x; int step; }Queue;
Queue q[SIZE*SIZE*SIZE];
void enQ(int y, int x, int step) {
	r++;
	q[r].y = y;
	q[r].x = x;
	q[r].step = step;
}
void deQ() { f++; }
Queue peek() { return q[f + 1]; }
int empty() {
	if (r == f)return 1;
	else return 0;
}
void init() {
	ans = 0;
	f = r = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 0;
		}
	}
}
int operation_cost(int k) { return (k * k) + (k - 1)*(k - 1); }
void bfs(int y, int x, int count, int k) {
	f = r = -1;
	enQ(y, x, 1);
	visited[y][x] = count;
	int house_count;
	if (map[y][x] == 1)house_count = 1;
	else house_count = 0;
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		int tstep = peek().step;
		deQ();
		if (tstep == k) break;
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < N&&visited[ny][nx] < count&&tstep < k) {
				enQ(ny, nx, tstep + 1);
				visited[ny][nx] = count;
				if (map[ny][nx] == 1)house_count++;
			}
		}
	}
	int temp_cost = operation_cost(k);
	if (house_count*M >= temp_cost) {
		if (house_count > ans)ans = house_count;
	}
}
int main() {
	int count = 1;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 1; k <= N + 1; k++) {
					bfs(i, j, count++, k);
				}
			}
		}
		printf("#%d %d\n", test + 1, ans);
		//init();
		ans = 0;
	}
	return 0;
}