#include <stdio.h>
#define SIZE 10
int paper[6];
int map[SIZE][SIZE];
int count = 0, min = 2123456789;
int is_ok(int s, int y, int x) {
	if (paper[s] == 5) return 0;
	if (SIZE < s + y || SIZE < s + x) return 0;
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
			if (map[y + i][x + j] != 1) {
				return 0;
			}
		}
	}
	return 1;
}
void change(int s, int y, int x, int what) {
	for (int i = y; i < y + s; i++) {
		for (int j = x; j < x + s; j++) {
			map[i][j] = what;
		}
	}
}
int check() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (map[i][j] == 1)return-1;
		}
	}
	return 1;
}

void dfs(int d, int total) {
	if (count < total)return;
	if (check() == 1) {
		if (d < min)min = d;
		return;
	}
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (map[i][j] == 1) {
				for (int s = 5; 1 <= s; s--) {
					if (is_ok(s, i, j) == 1) {
						change(s, i, j, 0);
						paper[s]++;
						dfs(d + 1, total + s * s);
						paper[s]--;
						change(s, i, j, 1);
					}
				}
				// return; // 색종이를 못덮는 경우 => 있어도되고 없어도됨
			}
			if (map[i][j] == 1) return; // 덮고나서도 해당 좌표를 못지우는 경우 
			// 이부분 진심 어떻게 생각함?
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) count++;
		}
	}
	dfs(0, 0);

	if (min == 2123456789) min = -1;
	printf("%d\n", min);

	return 0;
}

//21퍼