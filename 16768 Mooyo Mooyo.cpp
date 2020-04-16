#include <stdio.h>
#define SIZE 10//0
int N, K, f, r;
int map[SIZE][10], visited[SIZE][10], group[SIZE * 10], temp[SIZE];
int by[4] = { 0,0,1,-1 }, bx[4] = { 1,-1,0,0 };
typedef struct { int y; int x; }Queue;
Queue q[SIZE * SIZE];
void enQ(int y, int x) {
	r++;
	q[r].y = y;
	q[r].x = x;
}
void deQ() { f++; }
Queue peek() { return q[f + 1]; }
int empty() {
	if (f == r)return 1;
	else return 0;
}
void bfs(int y, int x, int me, int cnt) {
	f = r = -1;
	enQ(y, x);
	visited[y][x] = cnt;
	int count = 1;
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < 10 && map[ny][nx] == me && visited[ny][nx] == 0) {
				enQ(ny, nx);
				visited[ny][nx] = cnt;
				count++;
			}
		}
	}
	group[cnt] = count;
}
void gravity() {
	for (int j = 0; j < 10; j++) {
		int count = 0;
		for (int i = N - 1; 0 <= i; i--) {
			if (map[i][j] != 0) {
				temp[count++] = map[i][j];
			}
			map[i][j] = 0;
		}
		for (int i = 0; i < count; i++) {
			map[N - 1 - i][j] = temp[i];
		}
	}
}
void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%d", map[i][j]);
		}
		printf("\n");
	}
}
void init(int n) {
	for (int i = 0; i < n; i++) {
		group[i] = 0;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			visited[i][j] = 0;
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	while (1) {
		int count = 1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 10; j++) {
				if (map[i][j] != 0 && visited[i][j] == 0) {
					group[count] = 0;
					bfs(i, j, map[i][j], count++);
				}
			}
		}

		// 없앨거 없애고
		int flag = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 10; j++) {
				if (group[visited[i][j]] >= K) {
					map[i][j] = 0;
					flag = 1;
				}
			}
		}
		if (flag == 0) break;
		// 중력 적용시키고
		gravity();
		init(count);
	}
	print();
	return 0;
}