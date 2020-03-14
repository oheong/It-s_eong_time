#include <stdio.h>
char map[6][6];
int ans, f, r;
int visited[5][5], bfs_visited[5][5], by[4] = { 0,0,1,-1 }, bx[4] = { 1,-1,0,0 };
typedef struct { int y; int x; }Queue;
Queue q[30];
void print() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%d ", visited[i][j]);
		}printf("\n");
	}printf("\n");
}
void enQ(int y, int x) {
	r++;
	q[r].y = y;
	q[r].x = x;
}
void deQ() { f++; }
int empty() {
	if (f == r)return 1;
	else return 0;
}
Queue peek() { return q[f + 1]; }
void init() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			bfs_visited[i][j] = 0;
		}
	}
}
void bfs(int y, int x) {
	f = r = -1;
	enQ(y, x);
	bfs_visited[y][x] = 1;
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < 5 && 0 <= nx && nx < 5 && bfs_visited[ny][nx] == 0 && visited[ny][nx] == 1) {
				enQ(ny, nx);
				bfs_visited[ny][nx] = 1;
			}
		}
	}
}
void dfs(int d, int n, int s) {
	if (d == 7) {
		if (s >= 4) {
			// 연결되었는지 안되었는지
			int count = 0;
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if (visited[i][j] == 1 && bfs_visited[i][j] == 0) {
						bfs(i, j);
						count++;
					}
				}
			}
			if (count == 1) {
				ans++;
				print();
			}
			init();
		}
		return;
	}
	for (int i = n; i < 25; i++) {
		int y = i / 5;
		int x = i % 5;
		if (visited[y][x] == 0) {
			visited[y][x] = 1;
			if (map[y][x] == 'S')dfs(d + 1, i, s + 1);
			else dfs(d + 1, i, s);
			visited[y][x] = 0;
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	for (int i = 0; i < 5; i++) {
		scanf("%s", map[i]);
	}

	dfs(0, 0, 0);

	printf("%d\n", ans);
	return 0;
}