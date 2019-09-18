#include <stdio.h>
#define SIZE 8
int T, N, K, max, max_value, f, r, top_count;
int map[SIZE][SIZE], visited[SIZE][SIZE], by[4] = { 0,0,1,-1 }, bx[4] = { 1,-1,0,0 };
typedef struct { int y; int x; int size; }Queue;
Queue q[SIZE*SIZE*SIZE*SIZE];
Queue top[5];
void enQ(int y, int x, int size) {
	r++;
	q[r].y = y;
	q[r].x = x;
	q[r].size = size;
}
void deQ() { f++; }
Queue peek() { return q[f + 1]; }
int empty() {
	if (f == r)return 1;
	else return 0;
}
void search_max() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == max_value) {
				top[top_count].y = i;
				top[top_count].x = j;
				top_count++;
			}
		}
	}
}
void init() {
	f = r = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] > max)max = visited[i][j];
			visited[i][j] = 0;
		}
	}
}
void bfs() {
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		int tsize = peek().size;
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < N) {
				if ((visited[ny][nx] == 0 && map[ty][tx] > map[ny][nx]) || (visited[ty][tx] > visited[ny][nx] && map[ty][tx] > map[ny][nx])) {
					visited[ny][nx] = tsize + 1;
					enQ(ny, nx, tsize + 1);
				}
			}
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d %d", &N, &K);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
				if (map[i][j] > max_value)max_value = map[i][j];
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k <= K; k++) {
					map[i][j] -= k;
					search_max();
					for (int how_many = 0; how_many < top_count; how_many++) {
						enQ(top[how_many].y, top[how_many].x, 1);
						visited[top[how_many].y][top[how_many].x] = 1;
						bfs();
						init();
					}
					top_count = 0;
					map[i][j] += k;
				}
			}
		}
		printf("#%d %d\n", test + 1, max);
		max = max_value = 0;
	}
	return 0;
}