#include <stdio.h>
#define SIZE 1000
int N, M, X;
int map[SIZE][SIZE];
void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j)continue;
			map[i][j] = 2123456789;
		}
	}
}
int main() {
	//freopen("Text.txt", "r", stdin);
	scanf("%d %d %d", &N, &M, &X);
	int a, b, c;
	init();
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		map[a - 1][b - 1] = c;
	}
	int max = 0;
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			if (k == i) continue;
			for (int j = 0; j < N; j++) {
				if (k == j || i == j) continue;
				if (map[i][k] != 2123456789 && map[k][j] != 2123456789 &&
					map[i][j] > map[i][k] + map[k][j]) {
					map[i][j] = map[i][k] + map[k][j];
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		int temp = map[i][X - 1] + map[X - 1][i];
		if (max < temp)max = temp;
	}
	printf("%d\n", max);
	return 0;
}