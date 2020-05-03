#include <stdio.h>
#define SIZE 52
char map[SIZE][SIZE], temp[SIZE];
int visited[SIZE][SIZE][5][2][2];
int N, M, f, r, delivery_count = 2, cy, cx, dy, dx;
int by[5] = { 0,-1,0,1,0 }, bx[5] = { 0, 0,1,0,-1 };
typedef struct { int y; int x; int dir; int c; int d; }Queue;
Queue q[SIZE*SIZE * 4 * 2 * 2 * 2];
void enQ(int y, int x, int dir, int c, int d) {
	r++;
	q[r].y = y;
	q[r].x = x;
	q[r].dir = dir;
	q[r].c = c;
	q[r].d = d;
}
void deQ() { f++; }
int empty() {
	if (r == f)return 1;
	else return 0;
}
Queue peek() { return q[f + 1]; }
void bfs() {
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		int tdir = peek().dir;
		int tc = peek().c;
		int td = peek().d;
		deQ();
		for (int ndir = 1; ndir < 5; ndir++) {
			if (ndir == tdir)continue;
			int ny = ty + by[ndir];
			int nx = tx + bx[ndir];
			int nc = tc;
			int nd = td;
			if (0 <= ny && ny < N && 0 <= nx && nx < M&&map[ny][nx] != '#') {
				if (0 <= ny && ny < N && 0 <= nx && nx < M&&map[ny][nx] != '#') {
					if (map[ny][nx] == 'C'&&tc == 0)
						nc = 1;
					else if (map[ny][nx] == 'D'&&td == 0)
						nd = 1;
					if (visited[ny][nx][ndir][nc][nd] == 0) {
						enQ(ny, nx, ndir, nc, nd);
						visited[ny][nx][ndir][nc][nd] = visited[ty][tx][tdir][tc][td] + 1;
					}
				}
			}
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d\n", &N, &M);
	f = r = -1;
	for (int i = 0; i < N; i++) {
		scanf("%s", &temp);
		for (int j = 0; j < M; j++) {
			map[i][j] = temp[j];
			if (map[i][j] == 'S') {
				enQ(i, j, 0, 0, 0);
				visited[i][j][0][0][0] = 1;
			}
			else if (map[i][j] == 'C') {
				if (delivery_count == 2) {
					map[i][j] = 'D';
					dy = i;
					dx = j;
				}
				else {
					cy = i;
					cx = j;
				}
				delivery_count--;
			}
		}
	}
	bfs();
	int min = 2123456789;
	for (int i = 1; i < 5; i++) {
		if (visited[cy][cx][i][1][1] == 0) continue;
		if (visited[cy][cx][i][1][1] < min)
			min = visited[cy][cx][i][1][1];
	}
	for (int i = 1; i < 5; i++) {
		if (visited[dy][dx][i][1][1] == 0) continue;
		if (visited[dy][dx][i][1][1] < min)
			min = visited[dy][dx][i][1][1];
	}
	if (min == 2123456789)min = 0;
	printf("%d\n", min - 1);
	return 0;
}
