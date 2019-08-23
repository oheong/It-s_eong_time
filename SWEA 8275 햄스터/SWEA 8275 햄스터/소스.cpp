#include <stdio.h>
int T, N, M, X, l, r, s, flag;
int map[10][3], visited[7], sum[7];
void hap() {
	sum[1] = visited[1];
	for (int i = 2; i <= N; i++) {
		sum[i] = visited[i] + sum[i - 1];
	}
}
int check() {
	for (int i = 0; i < M; i++) {
		if (sum[map[i][1]] - sum[map[i][0] - 1] != map[i][2]) return 0;
	}
	return 1;
}
void dfs(int d, int t) {
	if (d == 0) {
		hap();
		if (check() == 1) {
			flag = 1;
			printf("#%d ", t);
			for (int i = 1; i <= N; i++)
				printf("%d ", visited[i]);
			printf("\n");
		}
		return;
	}
	for (int i = X; 0 <= i; i--) {
		visited[d] = i;
		dfs(d - 1, t);
		if (flag == 1) return;
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d %d %d", &N, &X, &M);
		for (int i = 0; i < M; i++) {
			scanf("%d %d %d", &l, &r, &s);
			map[i][0] = l;
			map[i][1] = r;
			map[i][2] = s;
		}
		flag = 0;
		dfs(N, test + 1);
		if (flag == 0) {
			printf("#%d %d\n", test + 1, -1);
		}
	}
	return 0;
}