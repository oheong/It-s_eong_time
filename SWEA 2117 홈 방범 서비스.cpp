#include <stdio.h>
#define SIZE 50
int T, N, M, operation_cost, f = -1, r = -1, total_cost, max, house_count;
int map[SIZE][SIZE], visited[SIZE][SIZE], by[4] = { 0,0,1,-1 }, bx[4] = { 1,-1,0,0 };
typedef struct { int y; int x; int size; }Queue;
Queue q[SIZE*SIZE], house[SIZE*SIZE];
void enQ(int y, int x, int size) {
	r++;
	q[r].y = y;
	q[r].x = x;
	q[r].size = size;
}
void deQ() { f++; }
Queue peek() { return q[f + 1]; }
int empty() {
	if (r == f)return 1;
	else return 0;
}
int bfs(int y, int x, int k, int sb) {
	f = r = -1;
	int house = 1;
	if (map[y][x] == 1)house = 1;
	else house = 0;
	enQ(y, x, 1);
	visited[y][x] = sb;
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		int tsize = peek().size;
		deQ();
		if (tsize == k) return house;
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < N&&visited[ny][nx] < sb) {
				enQ(ny, nx, tsize + 1);
				visited[ny][nx] = sb;
				if (map[ny][nx] == 1)house++;
			}
		}
	}
}
void init() {
	f = r = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 0;
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
				if (map[i][j] == 1) {
					house[house_count].y = i;
					house[house_count].x = j;
					house_count++;
				}
			}
		}
		for (int k = 1; k <= N + 5; k++) {
			operation_cost = k * k + (k - 1)*(k - 1);
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					int cost = bfs(i, j, k, i*N + j);
					if (cost*M >= operation_cost) {
						if (max < cost)max = cost;
					}
					//init();
				}
			}
			init();
			//for (int h = 0; h < house_count; h++) {
			//	int cost = bfs(house[h].y, house[h].x, k, h + 1);
			//	if (cost*M >= operation_cost) {
			//		if (max < cost)max = cost;
			//	}
			//}
			//init();
		}
		printf("#%d %d\n", test + 1, max);
		max = 0;
		house_count = 0;
	}
	return 0;
}