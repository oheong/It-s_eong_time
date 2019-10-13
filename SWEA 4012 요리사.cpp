#include <stdio.h>
#define SIZE 16
int T, N, min = 2123456789;
int map[SIZE][SIZE], visited[SIZE];
int get_sum(int choice) {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (visited[i] == choice && visited[j] == choice) {
				sum += map[i][j];
				sum += map[j][i];
			}
		}
	}
	return sum;
}
int abs(int a) {
	if (a < 0)return -1 * a;
	else return a;
}
void dfs(int d, int n) {
	if (d == N / 2) {
		int temp = abs(get_sum(0) - get_sum(1));
		if (min > temp)min = temp;
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
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		dfs(0, 0);//а╤гу
		printf("#%d %d\n\n", test + 1, min);
		min = 2123456789;
	}
	return 0;
}