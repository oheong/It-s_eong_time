#include <stdio.h>
int T, N, min, max;
int map[12], calc[4];
void dfs(int d, int num) {
	if (d == N - 1) {
		if (num < min)
			min = num;
		if (max < num)
			max = num;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (calc[i] != 0) {
			calc[i]--;
			if (i == 0)
				dfs(d + 1, num + map[d + 1]);
			else if (i == 1)
				dfs(d + 1, num - map[d + 1]);
			else if (i == 2)
				dfs(d + 1, num * map[d + 1]);
			else
				dfs(d + 1, num / map[d + 1]);
			calc[i]++;
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		min = 2123456789;
		max = -2123456789;
		scanf("%d", &N);
		for (int i = 0; i < 4; i++) {
			scanf("%d", &calc[i]);
		}
		for (int i = 0; i < N; i++) {
			scanf("%d", &map[i]);
		}

		dfs(0, map[0]);
		printf("#%d %d\n", test + 1, max - min);
	}
	return 0;
}