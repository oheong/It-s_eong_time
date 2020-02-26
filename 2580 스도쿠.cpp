#include <stdio.h>
#define SIZE 9
int map[SIZE][SIZE], ans[SIZE][SIZE];
int count = 0;
int is_ok_line(int y, int x, int num) {
	for (int i = y - 1; 0 <= i; i--) {
		if (map[i][x] == num) return 0;
	}
	for (int i = y + 1; i < SIZE; i++) {
		if (map[i][x] == num)return 0;
	}
	for (int j = x - 1; 0 <= j; j--) {
		if (map[y][j] == num)return 0;
	}
	for (int j = x + 1; j < SIZE; j++) {
		if (map[y][j] == num)return 0;
	}
	return 1;
}
int is_ok_qube(int y, int x, int num) {
	y /= 3; y *= 3;
	x /= 3; x *= 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (map[y + i][x + j] == num) return 0;
		}
	}
	return 1;
}
void dfs(int d) {
	if (d == count) {
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				ans[i][j] = map[i][j];
			}
		}
		return;
	}
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (map[i][j] == 0) {
				for (int num = 1; num <= 9; num++) {
					if (is_ok_line(i, j, num) == 1 && is_ok_qube(i, j, num) == 1) {
						map[i][j] = num;
						dfs(d + 1);
						map[i][j] = 0;
					}
				}
			}
			if (map[i][j] == 0) return; // 이게 진짜 중요한듯
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0)count++;
		}
	}
	dfs(0);
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}