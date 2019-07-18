#include <stdio.h>
#define SIZE 20
int N, f = -1, r = -1, count, tempstep, ans, n_x, n_y;
int map[SIZE][SIZE], visited[SIZE][SIZE], by[4] = { 0,0,1,-1 }, bx[4] = { 1,-1,0,0 };
typedef struct { int y; int x; int size; int step; }Queue;
Queue q[SIZE*SIZE];
bool flag;
void enQ(int y, int x, int size, int step) {
	r++;
	q[r].y = y;
	q[r].x = x;
	q[r].size = size;
	q[r].step = step;
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
void eat() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == 9) {
				n_y = i;
				n_x = j;
				return;
			}
		}
	}
}
void bfs(int y, int x) {
	visited[y][x] = 1;
	enQ(y, x, 2, 0);
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		int tsize = peek().size;
		int tstep = peek().step;
		if (flag == true && tstep == tempstep + 1) {
			eat();
			init();
			map[n_y][n_x] = 0;
			count++;
			if (tsize == count) {
				count = 0;
				tsize++;
			}
			ans = tstep;
			enQ(n_y, n_x, tsize, tstep);
			visited[n_y][n_x] = 1;
			continue;
		}
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < N&&visited[ny][nx] == 0 && map[ny][nx] <= tsize) {
				if (map[ny][nx] == 0 || map[ny][nx] == tsize)
					visited[ny][nx] = 1;
				else {
					visited[ny][nx] = 9;
					tempstep = tstep;
					flag = true;
				}
				enQ(ny, nx, tsize, tstep + 1);
			}
		}
	}
}
int main() {
	//freopen("Text.txt", "r", stdin);
	scanf("%d", &N);
	int a, b;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9) {
				a = i; b = j;
			}
		}
	}
	map[a][b] = 0;
	bfs(a, b);
	printf("%d\n", ans);
	return 0;
}