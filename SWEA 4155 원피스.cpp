#include <stdio.h>
#define SIZE 51
int T, N, M, f = -1, r = -1, ans = -1, step;
char map[SIZE][SIZE];
int visited[64][SIZE][SIZE], key[6], by[4] = { 0,0,1,-1 }, bx[4] = { 1,-1,0,0 };
typedef struct { int y; int x; int step; int key; }Queue;
Queue q[SIZE*SIZE * 64];
void enQ(int y, int x, int step, int key) {
	r++;
	q[r].y = y;
	q[r].x = x;
	q[r].step = step;
	q[r].key = key;
}
void deQ() { f++; }
Queue peek() { return q[f + 1]; }
int empty() {
	if (r == f)return 1;
	else return 0;
}
void init() {
	ans = f = r = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 64; k++)
				visited[k][i][j] = 0;
		}
	}
}
void bfs() {
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		int tstep = peek().step;
		int key = peek().key;
		deQ();
		if (map[ty][tx] == '1') {
			ans = tstep;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < M&&map[ny][nx] != '#'&&visited[key][ny][nx] == 0) {
				if (map[ny][nx] == '.' || map[ny][nx] == '0' || map[ny][nx] == '1') {
					visited[key][ny][nx] = 1;
					enQ(ny, nx, tstep + 1, key);
				}
				else if ('a' <= map[ny][nx] && map[ny][nx] <= 'f') {
					int nkey = 1 << (map[ny][nx] - 'a');
					nkey |= key;
					visited[nkey][ny][nx] = 1;///////////////////////////////////////////////////
					visited[key][ny][nx] = 1;
					enQ(ny, nx, tstep + 1, nkey);
				}
				else if ('A' <= map[ny][nx] && map[ny][nx] <= 'F') {
					int door = 1 << (map[ny][nx] - 'A');
					if (0 < (key&door)) {
						visited[key][ny][nx] = 1;
						enQ(ny, nx, tstep + 1, key);
					}
				}
			}
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d %d\n", &N, &M);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= M; j++) {
				scanf("%c", &map[i][j]);
				if (map[i][j] == '0') {
					enQ(i, j, 0, 0);
					visited[0][i][j] = 1;
				}
			}
		}
		bfs();
		printf("#%d %d\n", test + 1, ans);
		init();
	}
	return 0;
}