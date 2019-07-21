#include <stdio.h>
#define SIZE 51
int N, M, V = 0, f = -1, r = -1, min = 2123456789, max;
int map[SIZE][SIZE], copy_map[SIZE][SIZE], visited[SIZE][SIZE], virus_visited[SIZE], by[4] = { 0,0,1,-1 }, bx[4] = { 1,-1,0,0 };
typedef struct { int y; int x; int step; }Queue;
Queue virus[SIZE], q[SIZE*SIZE];
void enQ(int y, int x, int step) {
	r++;
	q[r].y = y;
	q[r].x = x;
	q[r].step = step;
}
void deQ() { f++; }
Queue peek() { return q[f + 1]; }
int empty() {
	if (r == f) return 1;
	else return 0;
}
void copy() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			copy_map[i][j] = map[i][j];//벽 위치 옮겨줌
			if (map[i][j] == -1)visited[i][j] = 9;
		}
	}
	for (int i = 0; i < V; i++) {
		if (virus_visited[i] == 0) {//비활성 바이러스
			copy_map[virus[i].y][virus[i].x] = -2;
		}
		else {//활성 바이러스
			enQ(virus[i].y, virus[i].x, 0);
			visited[virus[i].y][virus[i].x] = 1;
		}
	}
}
void bfs() {
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		int tstep = peek().step;
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < N&&visited[ny][nx] == 0 && copy_map[ny][nx] != -1) {
				if (copy_map[ny][nx] == -2) {
					//활성화 될 바이러스
					copy_map[ny][nx] = 0;
					enQ(ny, nx, tstep + 1);
				}
				else {
					copy_map[ny][nx] = tstep + 1;
					enQ(ny, nx, tstep + 1);
				}
				visited[ny][nx] = tstep + 1;
			}
		}
	}
}
void get_max() {
	max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (copy_map[i][j] == 0 && visited[i][j] == 0) {
				max = 2123456789;
				return;
			}
			if (max < copy_map[i][j] && visited[i][j] != 0)
				max = copy_map[i][j];
		}
	}
}
void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 0;
		}
	}
	f = r = -1;
}
void dfs(int d, int n) {
	if (d == M) {
		copy();
		bfs();
		//get_max();
		//if (max == 3) {
		//	for (int i = 0; i < V; i++) {
		//		printf("%d ", virus_visited[i]);
		//	}
		//	printf("\n");
		//}
		get_max();
		init();
		//printf("%d", max);
		if (max < min)
			min = max;
		//printf("\t%d\n", min);
		return;
	}
	for (int i = n; i < V; i++) {
		if (virus_visited[i] == 0) {
			virus_visited[i] = 1;
			dfs(d + 1, i);
			virus_visited[i] = 0;
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	int a;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &a);
			if (a == 1) {
				map[i][j] = -1;//벽은 -1로 세워줌
			}
			else if (a == 2) {
				virus[V].y = i;
				virus[V].x = j;
				V++;
			}
		}
	}
	dfs(0, 0);
	if (min == 2123456789) printf("%d\n", -1);
	else printf("%d\n", min);
	return 0;
}