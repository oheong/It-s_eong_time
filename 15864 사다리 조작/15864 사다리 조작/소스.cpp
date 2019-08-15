#include <stdio.h>
int N, M, H, min = 2123456789, c = 1;
int map[31][11], visited[31][11], check[11];
void down_sadari(int start_x) {
	int j = start_x;
	for (int i = 0; i <= H; i++) {
		if (map[i][j] != 0) {
			int cmt = map[i][j];
			visited[i][j] = start_x;
			if (map[i][j + 1] == cmt && visited[i][j + 1] != start_x) {
				i--;
				j++;
			}
			else if (map[i][j - 1] == cmt && visited[i][j - 1] != start_x) {
				j--;
				i--;
			}
		}
	}
	check[j] = start_x;
}
void init() {
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			visited[i][j] = 0;
		}
	}
}
int check_func() {
	for (int i = 1; i <= N; i++) {
		if (i != check[i])return 0;
	}
	return 1;
}
void dfs(int d, int n, int k) {
	if (d == k) {
		for (int i = 1; i <= N; i++) down_sadari(i);
		if (check_func() == 1) {
			if (min > d)min = d;
		}
		init();
		return;
	}
	for (int i = n; i < N * H; i++) {
		int y = (i / N) + 1;
		int x = (i % N) + 1;
		if (x == N) continue;
		if (map[y][x + 1] != 0)continue;
		if (map[y][x] == 0) {
			map[y][x] = c;
			map[y][x + 1] = c;
			c++;
			dfs(d + 1, i + 1, k);
			map[y][x] = 0;
			map[y][x + 1] = 0;
			c--;
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d %d", &N, &M, &H);
	int a, b;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		map[a][b] = c;
		map[a][b + 1] = c;
		c++;
	}
	for (int k = 0; k < 4; k++)
		dfs(0, 0, k);
	if (min == 2123456789)printf("%d\n", -1);
	else printf("%d\n", min);
	return 0;
}