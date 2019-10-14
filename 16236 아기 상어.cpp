#include <stdio.h>
#define SIZE 20
int N, f = -1, r = -1, eat_count, restart_x, restart_y, ans;
int map[SIZE][SIZE], visited[SIZE][SIZE], eat[SIZE][SIZE], by[4] = { -1,0,1,0 }, bx[4] = { 0,1,0,-1 };
typedef struct { int y; int x; int step; int size; }Queue;
Queue q[SIZE*SIZE*SIZE];
void enQ(int y, int x, int step, int size) {
	r++;
	q[r].y = y;
	q[r].x = x;
	q[r].step = step;
	q[r].size = size;
}
void deQ() { f++; }
Queue peek() { return q[f + 1]; }
int empty() {
	if (f == r)return 1;
	else return 0;
}
void what_eat() {
	f = r = -1;
	int flag = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (eat[i][j] == 1 && flag == 0) {
				restart_x = j; restart_y = i;
				map[i][j] = 0;
				flag = 1;
			}
			visited[i][j] = 0;
			eat[i][j] = 0;
		}
	}
	eat_count++;
}
void bfs() {
	int eat_flag = 0, eat_step = 0;
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		int tsize = peek().size;
		int tstep = peek().step;
		deQ();
		if (eat_flag == 1 && tstep != eat_step) {
			what_eat();
			if (tsize == eat_count) {
				tsize++;
				eat_count = 0;
			}
			enQ(restart_y, restart_x, tstep, tsize);
			visited[restart_y][restart_x] = tstep;
			ans = tstep;
			eat_flag = 0, eat_step = 0;
			continue;
		}
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < N&&visited[ny][nx] == 0) {
				if (map[ny][nx] > tsize) continue;
				else {
					if (0 < map[ny][nx] && map[ny][nx] < tsize) {
						eat[ny][nx] = 1;
						eat_flag = 1;
						eat_step = tstep;
					}
					enQ(ny, nx, tstep + 1, tsize);
					visited[ny][nx] = tstep + 1;
				}
			}
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9) {
				map[i][j] = 0;
				enQ(i, j, 0, 2);
				visited[i][j] = 1;
			}
		}
	}
	bfs();
	printf("%d\n", ans);
	return 0;
}