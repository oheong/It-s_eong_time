#include <stdio.h>
#define SIZE 401
int T, N, M, min = 2123456789;
int map[SIZE][SIZE], visited[SIZE];
typedef struct { int y; int x; }INIT;
INIT init[SIZE*SIZE];
void dfs(int start, int n, int sum) {
	if (min <= sum)return;
	if (visited[n] == 1) {
		if (sum < min)min = sum;
		return;
	}
	visited[n] = 1;
	for (int i = 1; i <= N; i++) {
		if (map[n][i] != 0) {
			dfs(start, i, sum + map[n][i]);
		}
	}
	visited[n] = 0;
}
void init_f() {
	for (int i = 0; i < M; i++) {
		map[init[i].y][init[i].x] = 0;
	}
	min = 2123456789;
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d %d", &N, &M);
		for (int i = 0; i < M; i++) {
			int s, e, c;
			scanf("%d %d %d", &s, &e, &c);
			map[s][e] = c;
			init[i].y = s;
			init[i].x = e;
		}
		for (int i = 1; i <= N; i++) {
			dfs(i, i, 0);
		}
		if (min == 2123456789)min = -1;
		printf("#%d %d\n", test + 1, min);
		init_f();
	}
	return 0;
}