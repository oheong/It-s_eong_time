#include <stdio.h>
#define SIZE 20
int N, f, r, eat_step, count, ans, eat_flag;
int map[SIZE][SIZE], visited[SIZE][SIZE], eat_map[SIZE][SIZE];
int by[4] = { 0,0,1,-1 }, bx[4] = { 1,-1,0,0 };
typedef struct { int y; int x; int size; int step; }Queue;
Queue q[SIZE*SIZE];
void enQ(int y, int x, int size, int step) {
	r++;
	q[r].y = y;
	q[r].x = x;
	q[r].size = size;
	q[r].step = step;
}
void deQ() { f++; }
int empty() {
	if (f == r)return 1;
	else return 0;
}
Queue peek() { return q[f + 1]; }
void eating(int size, int step) {
	int flag = 0;
	f = r = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 0;
			if (eat_map[i][j] == 1 && flag == 0) {
				count++; // 먹었음
				flag = 1;
				if (count == size) {
					size++;
					count = 0;
				}
				enQ(i, j, size, step);
				visited[i][j] = step;
				map[i][j] = 0;
			}
			eat_map[i][j] = 0;
		}
	}
}
void bfs() {
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		int tsize = peek().size;
		int tstep = peek().step;
		deQ();
		if (eat_flag == 1 && eat_step < tstep) {
			// 먹이를 먹을 수 있었던 상태보다 더 나간거니까 이제 먹이먹으러 ㄱㄱ
			eat_flag = 0;
			eating(tsize, tstep);
			ans = tstep;
			continue;
		}
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < N&&visited[ny][nx] == 0 && map[ny][nx] <= tsize) {
				if (0 < map[ny][nx] && map[ny][nx] < tsize) {
					// 먹이로 먹을수 있음!!! 체크체크
					eat_step = tstep;
					eat_map[ny][nx] = 1;
					eat_flag = 1;
				}
				enQ(ny, nx, tsize, tstep + 1);
				visited[ny][nx] = tstep + 1;
			}
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &N);
	f = r = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9) {
				enQ(i, j, 2, 0);
				visited[i][j] = 1;
				map[i][j] = 0;
			}
		}
	}
	bfs();
	printf("%d\n", ans);
	return 0;
}