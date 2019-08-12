#include <stdio.h>
#define SIZE 50
int N, M, K, min = 2123456789;
int map[SIZE][SIZE], visited[6], check[7], copy_map[SIZE][SIZE];
typedef struct { int y; int x; int size; }ROLL;
ROLL rr[7];
void copy() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			copy_map[i][j] = map[i][j];
		}
	}
}
int is_out(int y, int x, int s) {
	if (y - s<0 || y + s>N - 1 || x - s<0 || x + s>M - 1)return 0;
	return 1;
}
int get_sum(int i) {
	int sum = 0;
	for (int j = 0; j < M; j++) {
		sum += copy_map[i][j];
	}
	return sum;
}
void roll(int y, int x, int s) {
	int t = copy_map[y - s][x - s];
	int size = s * 2;
	for (int i = 0; i < size; i++) copy_map[y - s + i][x - s] = copy_map[y - s + i + 1][x - s];

	for (int i = 0; i < size; i++) copy_map[y + s][x - s + i] = copy_map[y + s][x - s + i + 1];

	for (int i = 0; i < size; i++) copy_map[y + s - i][x + s] = copy_map[y + s - i - 1][x + s];

	for (int i = 0; i < size; i++) copy_map[y - s][x + s - i] = copy_map[y - s][x + s - i - 1];

	copy_map[y - s][x - s + 1] = t;
}
void dfs(int d) {
	if (d == K) {
		copy();
		for (int i = 0; i < K; i++) {
			int t = visited[i];
			if (is_out(rr[t].y, rr[t].x, rr[t].size) == 1) {
				for (int s = 1; s <= rr[t].size; s++) roll(rr[t].y, rr[t].x, s);
			}
		}
		for (int i = 0; i < N; i++) {
			int t = get_sum(i);
			if (min > t)min = t;
		}

		return;
	}
	for (int i = 1; i <= K; i++) {
		if (check[i] == 0) {
			check[i] = 1;
			visited[d] = i;
			dfs(d + 1);
			visited[d] = 0;
			check[i] = 0;
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	int r, c;
	for (int i = 1; i <= K; i++) {
		scanf("%d %d %d", &r, &c, &rr[i].size);
		rr[i].y = r - 1;
		rr[i].x = c - 1;
	}
	dfs(0);
	printf("%d\n", min);
	return 0;
}