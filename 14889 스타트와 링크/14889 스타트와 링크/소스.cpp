/* а╤гу */
#include <stdio.h>
#define SIZE 20
int N, ans = 2123456789;
int map[SIZE][SIZE], visited[SIZE];
int abs(int a) {
	if (a < 0)return -1 * a;
	else return a;
}
int getsum(int a) {
	int temp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i] == visited[j] && visited[i] == a) {
				temp += map[i][j];
			}
		}
	}
	return temp;
}
void dfs(int d, int n) {
	if (d == N / 2) {
		int start = 0, link = 0;
		start = getsum(1);
		link = getsum(0);
		int temp = abs(start - link);
		if (temp < ans)ans = temp;
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
	//freopen("Text.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	dfs(0, 0);
	printf("%d\n", ans);
	return 0;
}