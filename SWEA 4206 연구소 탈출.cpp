#include <stdio.h>
#define SIZE 10
int T, N, M, f = -1, r = -1, ans = 2123456789;
int map[SIZE][SIZE], visited[SIZE][SIZE], by[4] = { 0,0,1,-1 }, bx[4] = { 1,-1,0,0 };
typedef struct { int type; int y; int x; int step; }Queue;
Queue q[SIZE*SIZE*SIZE*SIZE];
void enQ(int type, int y, int x, int step) {
	r++;
	q[r].type = type;
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
int init() {
	ans = 2123456789;
	f = r = -1;
	int flag = 0, a = -1;
	for (int i = 1; i <= M; i++) {
		if (visited[0][i] != 0) {
			if (ans > visited[0][i]) ans = visited[0][i];
			visited[0][i] = 0;
			a = 0; flag = 1;
		}
		else if (visited[N + 1][i] != 0) {
			if (ans > visited[N + 1][i]) ans = visited[N + 1][i];
			visited[N + 1][i] = 0;
			a = 0; flag = 1;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (visited[i][0] != 0) {
			if (ans > visited[i][0]) ans = visited[i][0];
			visited[i][0] = 0;
			a = 0; flag = 1;
		}
		else if (visited[i][M + 1] != 0) {
			if (ans > visited[i][M + 1]) ans = visited[i][M + 1];
			visited[i][M + 1] = 0;
			a = 0; flag = 1;
		}
	}
	//flag==1 이면 탈출한거임
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (flag == 0 && map[i][j] == 3 && a != 1 && visited[i][j] == 2) {
				a = 1;
			}
			visited[i][j] = 0;
			map[i][j] = 0;// 이거 추가하니까 맞은 갯수 14->15됨 시팔
		}
	}
	return a;
}
void bfs() {
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		int type = peek().type;
		int tstep = peek().step;
		deQ();
		if (ty == -1 && tx == -1)return;
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (type == 1 && map[ny][nx] == 0 && visited[ny][nx] == 0 && visited[ty][tx] != 2) {//사람
				if (0 < ny && ny <= N && 0 < nx && nx <= M) {
					enQ(1, ny, nx, tstep + 1);
					visited[ny][nx] = 1;
				}
				else visited[ny][nx] = tstep + 1;
			}
			else if (type == 2 && map[ny][nx] != 1 && visited[ny][nx] < 2) {//바이러스
				if (0 < ny && ny <= N && 0 < nx && nx <= M) {
					enQ(2, ny, nx, tstep);
					visited[ny][nx] = 2;
				}
			}
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		enQ(1, -1, -1, 0);
		scanf("%d %d", &N, &M);//8*8 max
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				scanf("%d", &map[i][j]);
				if (map[i][j] == 2) {
					enQ(2, i, j, 0);
					visited[i][j] = 2;
				}
				else if (map[i][j] == 3) {
					q[0].y = i;
					q[0].x = j;
					visited[i][j] = 1;
				}
			}
		}
		bfs();
		printf("#%d ", test + 1);
		int temp = init();
		if (temp == -1)printf("CANNOT ESCAPE\n");
		else if (temp == 0) printf("%d\n", ans);
		else printf("ZOMBIE\n");
	}
	return 0;
}