#include<stdio.h>
#define SIZE 101
int T, N, max;
int map[SIZE][SIZE], mapsum[SIZE][SIZE];
void sum() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			mapsum[i][j] = mapsum[i - 1][j] + mapsum[i][j - 1] + map[i][j] - mapsum[i - 1][j - 1];
		}
	}
}
void getnum(int s, int h, int ss, int e) {
	int temp = mapsum[h][e] - mapsum[s - 1][e] - mapsum[h][ss - 1] + mapsum[s - 1][ss - 1];

	if (max < temp)max = temp;
	return;
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d", &N);
		max = -2123456789;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		sum();
		for (int s = (N * N) - 1; 0 <= s; s--) {
			for (int h = s / N; 0 <= h; h--) {
				for (int e = s % N; 0 <= e; e--) {
					getnum(h + 1, s / N + 1, e + 1, s%N + 1);
				}
			}
		}
		printf("Case #%d\n%d\n", test + 1, max);
		max = 0;
	}
	return 0;
}
//6 25 33