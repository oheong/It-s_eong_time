#include <stdio.h>
int N, start, link, min = 2123456789;
int map[20][20], visited[20];
int abs(int a) {
	if (a > 0)return a;
	else return -1 * a;
}
int return_sum(int n) {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i] == n && visited[j] == n)sum += map[i][j];
		}
	}
	return sum;
}
void dfs(int d, int n) {
	if (d == N / 2) {
		start = return_sum(1);
		link = return_sum(0);
		int t = abs(start - link);
		if (min > t)min = t;
		return;
	}
	for (int i = n; i < N; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			dfs(d + 1, i);
			visited[i] = 0;
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	dfs(0, 0);
	printf("%d\n", min);
	return 0;
}