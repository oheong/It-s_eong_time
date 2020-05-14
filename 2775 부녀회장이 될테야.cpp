#include <stdio.h>
int T, k, n;
int map[15][15];
int main() {
	freopen("Text.txt", "r", stdin);
	for (int i = 0; i < 15; i++) {
		map[0][i] = i;
	}
	for (int i = 1; i < 15; i++) {
		for (int j = 1; j < 15; j++) {
			map[i][j] = map[i - 1][j] + map[i][j - 1];
		}
	}
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d %d", &k, &n);
		printf("%d\n", map[k][n]);
	}
	return 0;
}