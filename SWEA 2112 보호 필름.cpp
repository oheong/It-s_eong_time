#include <stdio.h>
int T, D, W, K, min, drug_cnt;
int map[13][20], copy_map[13][20], visited[13], drug[2][13]; // 0에 index 1에 약물종류
void copy() {
	for (int i = 0; i < D; i++) {
		for (int j = 0; j < W; j++) {
			copy_map[i][j] = map[i][j];
		}
	}
}
void push(int y, int c) {
	for (int j = 0; j < W; j++) {
		copy_map[y][j] = c;
	}
}
int testing(int x) {
	for (int i = 0; i <= D - K; i++) {
		int count = 0;
		int key = copy_map[i][x];
		for (int k = 0; k < K; k++) {
			if (key == copy_map[i + k][x]) count++;
			else break;
		}
		if (count == K)return 1;
	}
	return -1;
}
void choice_drug(int d, int n) {
	if (d == n) {
		// 검사를 시작하지

		for (int j = 0; j < W; j++) {
			if (testing(j) == -1) return;
		}

		if (d < min)
			min = d;

		return;
	}
	drug[1][d] = 0;
	push(drug[0][d], 0);
	choice_drug(d + 1, n);
	drug[1][d] = 1;
	push(drug[0][d], 1);
	choice_drug(d + 1, n);
}
void dfs(int d, int c) {
	if (c > K)return;
	if (d == D) {
		copy();
		choice_drug(0, c);
		return;
	}
	visited[d] = 0;
	dfs(d + 1, c);

	visited[d] = 1;
	drug[0][c] = d;
	dfs(d + 1, c + 1);
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d %d %d", &D, &W, &K);
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		min = 2123456789;
		dfs(0, 0);
		printf("#%d %d\n", test + 1, min);
	}
	return 0;
}