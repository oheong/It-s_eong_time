#include<stdio.h>
int T, map[12][12], visited[11], max;
void dfs(int d, int sum) {
	if (d == 12) {
		if (max < sum) max = sum;
		return;
	}
	for (int i = 0; i < 11; i++) {
		if (map[i][d] != 0 && visited[i] == 0) {
			visited[i] = d;
			dfs(d + 1, sum + map[i][d]);
			visited[i] = 0;
		}
	}
}
int main() {
	//freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		max = 0;
		for (int i = 0; i < 11; i++) {
			for (int j = 1; j <= 11; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		dfs(1, 0);
		printf("%d\n", max);
	}
	return 0;
}
