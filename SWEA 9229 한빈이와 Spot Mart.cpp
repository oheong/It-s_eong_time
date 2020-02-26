#include <stdio.h>
int T, N, M;
int map[1000];
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d %d", &N, &M);
		int sum = 0, max = 0;
		for (int i = 0; i < N; i++)scanf("%d", &map[i]);
		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				sum = map[i] + map[j];
				if (M < sum)continue;
				if (max < sum)max = sum;
			}
		}
		if (max == 0)max = -1;
		printf("#%d %d\n", test + 1, max);
	}
	return 0;
}