#include <stdio.h>
#define SIZE 55
int T, N, M, f, r, sx, sy, ay, ax, ans = -1;
char map[SIZE][SIZE], str[SIZE + 5];
int visited[SIZE][SIZE];
int by[4] = { 0,0,1,-1 }, bx[4] = { 1,-1,0,0 };
typedef struct { char c; int y; int x; int step; }Queue;
Queue q[SIZE*SIZE*SIZE*SIZE];
void enQ(int y, int x, char c, int step) {
	r++;
	q[r].y = y;
	q[r].x = x;
	q[r].c = c;
	q[r].step = step;
}
void deQ() { f++; }
int empty() {
	if (r == f) return 1;
	else return 0;
}
Queue peek() { return q[f + 1]; }
void bfs(int y, int x) {
	visited[y][x] = 1; // 수연이가 있는 장소
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		int tc = peek().c;
		int tstep = peek().step;
		deQ();
		if (ty == ay && tx == ax) {
			ans = tstep;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < M&&map[ny][nx] != 'X'&&visited[ny][nx] != 2) {
				if (tc == 'S') {
					// 수연이일떄
					if (visited[ty][tx] == 2) continue; // 지금 있는 자리에 불 와있으면 끝
					if (visited[ny][nx] == 0) {
						enQ(ny, nx, tc, tstep + 1);
						visited[ny][nx] = 1;
					}
				}
				else if (tc == '*') {
					// 악마일때
					if (map[ny][nx] != 'D') {
						enQ(ny, nx, tc, 0);
						visited[ny][nx] = 2;
					}
				}
			}
		}
	}
}
void init() {
	ans = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = 0;
		}
	}
}
int main() {
	freopen("text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d %d\n", &N, &M);
		f = -1; r = 0;
		for (int i = 0; i < N; i++) {
			scanf("%s", &str);
			for (int j = 0; j < M; j++) {
				map[i][j] = str[j];
				if (map[i][j] == 'S') {
					sy = i;
					sx = j;
				}
				else if (map[i][j] == '*') {
					enQ(i, j, map[i][j], 0);
					visited[i][j] = 2; // 불 시작 장소
				}
				else if (map[i][j] == 'D') {
					ay = i;
					ax = j;
				}
			}
		}
		q[0].y = sy;
		q[0].x = sx;
		q[0].c = 'S';
		q[0].step = 0;
		bfs(sy, sx);
		if (ans == -1)
			printf("#%d GAME OVER\n", test + 1);
		else
			printf("#%d %d\n", test + 1, ans);
		init();
	}
	return 0;
}