#include <stdio.h>
#define SIZE 51
int N, M, K, f, r;
int count[SIZE][SIZE], dirs[SIZE][SIZE][SIZE*SIZE], speeds[SIZE][SIZE][SIZE*SIZE], ms[SIZE][SIZE][SIZE*SIZE];
int by[8] = { -1,-1,0,1,1,1,0,-1 }, bx[8] = { 0,1,1,1,0,-1,-1,-1 };
typedef struct { int y; int x; int m; int s; int d; }Queue;
Queue q[SIZE*SIZE*SIZE*SIZE];
void enQ(int y, int x, int m, int s, int d) {
	r++;
	q[r].y = y;
	q[r].x = x;
	q[r].m = m;
	q[r].s = s;
	q[r].d = d;
}
void deQ() { f++; }
int empty() {
	if (f == r)return 1;
	else return 0;
}
Queue peek() { return q[f + 1]; }
void change_fire() {
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		int tm = peek().m;
		int ts = peek().s;
		int td = peek().d;
		deQ();
		if (tm == 0)continue;
		int ny = ty + (ts%N) * by[td];
		int nx = tx + (ts%N) * bx[td];
		if (ny < 0)
			ny += N;
		else if (N <= ny)
			ny -= N;
		if (nx < 0)
			nx += N;
		else if (N <= nx)
			nx -= N;

		dirs[ny][nx][count[ny][nx]] = td;
		speeds[ny][nx][count[ny][nx]] = ts;
		ms[ny][nx][count[ny][nx]++] = tm;
	}
}
void calc_fire() {
	f = r = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (count[i][j] == 0) continue;
			if (count[i][j] == 1) {
				enQ(i, j, ms[i][j][0], speeds[i][j][0], dirs[i][j][0]);
				count[i][j] = 0;
				continue;
			}
			int ndir = 0;
			int start_dir = dirs[i][j][0] % 2;
			for (int cnt = 1; cnt < count[i][j]; cnt++) {
				if (dirs[i][j][cnt] % 2 != start_dir) {
					ndir = 1;
					break;
				}
			}
			int sum_s = 0, sum_m = 0;
			for (int c = 0; c < count[i][j]; c++) {
				sum_s += speeds[i][j][c];
				sum_m += ms[i][j][c];
			}
			for (int dir = 0; dir < 4; dir++) {
				enQ(i, j, sum_m / 5, sum_s / count[i][j], dir * 2 + ndir);
			}
			count[i][j] = 0; // init
		}
	}
}
int ans() {
	int sum = 0;
	while (empty() == 0) {
		int m = peek().m;
		sum += m;
		deQ();
	}
	return sum;
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d %d", &N, &M, &K);
	f = r = -1;
	int y, x, m, s, d;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d %d %d", &y, &x, &m, &s, &d);
		enQ(y - 1, x - 1, m, s, d);
	}
	while (0 < K) {
		change_fire();
		calc_fire();
		K--;
	}
	printf("%d\n", ans());
	return 0;
}