#include <stdio.h>
#define SIZE 50
int N, M, virus, r = -1, f = -1, min = 2123456789;
int map[SIZE][SIZE], copy_map[SIZE][SIZE], visited[SIZE][SIZE], by[4] = { 0,0,1,-1 }, bx[4] = { 1,-1,0,0 };
typedef struct { int y; int x; int size; }Queue;
Queue v[11], q[SIZE*SIZE];
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
void copy() {
	f = r = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			copy_map[i][j] = map[i][j];
			visited[i][j] = 0;
		}
	}
}
int what_max() {
	//visited 다 정비하고 들어왔다?
	int max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == 0) {
				if (copy_map[i][j] == 2 || copy_map[i][j] == 1)continue;
				else return -1;
			}
			if (visited[i][j] > max)max = visited[i][j];
		}
	}
	return max;
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
			if (0 <= ny && ny < N && 0 <= nx && nx < N&&visited[ny][nx] == 0 && copy_map[ny][nx] == 0) {
				enQ(ny, nx, tsize + 1);
				visited[ny][nx] = tsize + 1;
			}
		}
	}
}
void dfs(int d, int n) {
	if (d == M) {
		copy();
		for (int i = 0; i < virus; i++) {
			if (v[i].size == 0) copy_map[v[i].y][v[i].x] = 0;
			else {
				enQ(v[i].y, v[i].x, 0);
				visited[v[i].y][v[i].x] = 1;
			}
		}
		bfs();
		for (int i = 0; i < virus; i++) {
			if (v[i].size == 1)
				visited[v[i].y][v[i].x] = 0;
		}
		int temp = what_max();
		if (temp != -1) {
			if (min > temp)min = temp;
		}
		return;
	}
	for (int i = n; i < virus; i++) {
		if (v[i].size == 0) {
			v[i].size = 1;
			dfs(d + 1, i);
			v[i].size = 0;
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) {
				v[virus].y = i; v[virus].x = j;
				virus++;
			}
		}
	}
	dfs(0, 0);
	if (min == 2123456789)	printf("%d\n", -1);
	else printf("%d\n", min);
	return 0;
}