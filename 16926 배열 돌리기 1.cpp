#include <stdio.h>
#define SIZE 300
int N, M, R;
int map[SIZE][SIZE];
int min(int a, int b) {
	if (a < b)return a;
	return b;
}
void change() {
	int y = 0, x = 0, n = N - 1, m = M - 1;
	int index = min(N, M); // 돌려야할 사각형 갯수
	for (int cnt = 0; cnt < index / 2; cnt++) {
		int temp_num = map[y][x];
		for (int j = x; j < m; j++) { // 위
			map[y][j] = map[y][j + 1];
		}
		for (int i = y; i < n; i++) { // 오
			map[i][m] = map[i + 1][m];
		}
		for (int j = m; x < j; j--) {
			map[n][j] = map[n][j - 1];
		}
		for (int i = n; y < i; i--) {
			map[i][x] = map[i - 1][x];
		}
		map[y + 1][x] = temp_num;
		y++; x++; n--; m--;
	}
}
void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d %d", &N, &M, &R);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 0; i < R; i++)
		change();
	print();
	return 0;
}