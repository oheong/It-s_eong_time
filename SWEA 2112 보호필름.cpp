#include <stdio.h>
int T, D, W, K, ans;
int map[13][20], copy_map[13][20], visited[13];
typedef struct { int what_d; int visited; }AORB;
AORB AorB[13];
void copy() {
	for (int i = 0; i < D; i++) {
		for (int j = 0; j < W; j++) {
			copy_map[i][j] = map[i][j];
		}
	}
}
void insert_cell(int i, int what_insert) { for (int j = 0; j < W; j++)copy_map[i][j] = what_insert; }
int is_ok(int j) {
	for (int i = 0; i <= D - K; i++) {
		int start = copy_map[i][j];
		int flag = 1;
		for (int k = i + 1; k < i + K; k++) {
			if (start == copy_map[k][j]) flag++;
		}
		if (flag == K)return 1;
		else continue;
	}
	return -1;
}
void choice_AorB(int d, int n) {
	if (d == n) {
		for (int j = 0; j < W; j++)
			if (is_ok(j) == -1)return;
		if (ans > n)ans = n;
		return;
	}
	AorB[d].visited = 1;
	insert_cell(AorB[d].what_d, AorB[d].visited);
	choice_AorB(d + 1, n);
	AorB[d].visited = 0;
	insert_cell(AorB[d].what_d, AorB[d].visited);
	choice_AorB(d + 1, n);
}
void dfs_choice_D(int d, int n, int end) {
	if (d == end) {
		copy();
		choice_AorB(0, end);
		return;
	}
	for (int i = n; i < D; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			AorB[d].what_d = i;
			dfs_choice_D(d + 1, i, end);
			visited[i] = 0;
			AorB[d].what_d = 0;
		}
	}
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
		ans = 2123456789;
		dfs_choice_D(0, 0, 0);
		for (int i = 0; i <= K; i++) dfs_choice_D(0, 0, i);
		printf("#%d %d\n", test + 1, ans);
	}
	return 0;
}