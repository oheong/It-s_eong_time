#include <stdio.h>
int N, max;
int map[500][500];
void DP(int y, int x) {
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) //哭率
				map[i][j] += map[i - 1][j];
			else if (j == i) //坷弗率
				map[i][j] += map[i - 1][j - 1];
			else {//啊款单
				if (map[i - 1][j - 1] > map[i - 1][j])
					map[i][j] += map[i - 1][j - 1];
				else map[i][j] += map[i - 1][j];
			}
		}
	}
}
int main() {
	//freopen("Text.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	DP(0, 0);
	for (int i = 0; i < N; i++) {
		if (max < map[N - 1][i])
			max = map[N - 1][i];
	}
	printf("%d\n", max);
	return 0;
}