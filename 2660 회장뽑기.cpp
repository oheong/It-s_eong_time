#include <stdio.h>
#define SIZE 50
int N, hubo_count;
int map[SIZE][SIZE], total[SIZE];
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &N);
	int a, b;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j)continue;
			map[i][j] = 2123456789;
		}
	}
	while (1) {
		scanf("%d %d", &a, &b);
		if (a == -1 && b == -1)break;
		map[a - 1][b - 1] = 1;
		map[b - 1][a - 1] = 1;
	}
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			if (i == k)continue;
			for (int j = 0; j < N; j++) {
				if (k == j || i == j)continue;
				if (map[i][k] != 2123456789 && map[k][j] != 2123456789 && map[i][j] > map[i][k] + map[k][j]) {
					map[i][j] = map[i][k] + map[k][j];
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 2123456789)map[i][j] = 0;
		}
	}
	int min = 2123456789;
	for (int i = 0; i < N; i++) {
		int max = 0;
		for (int j = 0; j < N; j++) {
			if (map[i][j] > max)max = map[i][j];
		}
		total[i] = max;
		if (max < min) {
			min = max;
			hubo_count = 0;
		}
		if (min == max)hubo_count++;
	}
	printf("%d %d\n", min, hubo_count);
	for (int i = 0; i < N; i++) {
		if (total[i] == min) {
			printf("%d ", i + 1);
		}
	}
	printf("\n");
	return 0;
}