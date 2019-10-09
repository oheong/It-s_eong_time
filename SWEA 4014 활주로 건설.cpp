#include <stdio.h>
#define S 20
int T, N, X, ans;
int arr[S][S], map[S], visited[S];
int abs(int a) {
	if (a > 0)return a;
	else return -1 * a;
}
void get_map(int dir, int i) {
	for (int j = 0; j < N; j++) {
		if (dir == 0) map[j] = arr[i][j]; //가로로 가져오는거
		else map[j] = arr[j][i];//세로로 가져오는거
		visited[j] = 0;
	}
}
int up_stair(int n) {
	if (n - X < 0)return -1;
	for (int i = n - 1; n - X <= i; i--) if (visited[i] == 1) return -1;
	for (int i = n - 1; n - X <= i; i--)visited[i] = 1;
}
int down_stair(int n) {
	if (N <= n + X) return -1;
	for (int i = n + 1; i < n + X; i++) if (abs(map[i] - map[i + 1]) != 0)return-1;
	for (int i = n + 1; i <= n + X; i++)visited[i] = 1;
}
void check_map() {
	for (int i = 0; i < N - 1; i++) {
		int stair = abs(map[i] - map[i + 1]);
		if (stair == 0 || (visited[i] == 1 && visited[i + 1] == 1)) continue;
		else if (stair == 1) {
			if (map[i] < map[i + 1]) {
				if (up_stair(i + 1) == -1)return;
			}
			else {
				if (down_stair(i) == -1)return;
			}
		}
		else return;
	}
	ans++;
}
int main() {
	//freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d %d", &N, &X);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &arr[i][j]);
			}
		}
		for (int i = 0; i < N; i++) {
			get_map(0, i);
			check_map();
			get_map(1, i);
			check_map();
		}
		printf("#%d %d\n", test + 1, ans);
		ans = 0;
	}
	return 0;
}