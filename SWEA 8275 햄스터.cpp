#include <stdio.h>
int T, N, X, M, flag;
typedef struct { int l; int r; int s; }HAM;
HAM hamster[10];
int visited[10], ans[10];
void dfs(int d) {
	if (d == -1) {
		for (int i = 0; i < M; i++) {
			int sum = 0;
			for (int j = hamster[i].l; j <= hamster[i].r; j++) {
				sum += visited[j];
			}
			if (sum != hamster[i].s) return;
		}
		if (flag == 0) {
			flag = 1;
			for (int i = 0; i < N; i++) {
				ans[i] = visited[i];
			}
		}
		return;
	}
	for (int i = X; 0 <= i; i--) {
		visited[d] = i;
		dfs(d - 1);
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d %d %d", &N, &X, &M);
		for (int i = 0; i < M; i++) {
			scanf("%d %d %d", &hamster[i].l, &hamster[i].r, &hamster[i].s);
			hamster[i].l--;
			hamster[i].r--;
		}
		flag = 0;
		dfs(N-1);
		printf("#%d ", test + 1);
		if (flag == 0) {
			printf("-1\n");
			continue;
		}
		for (int i = 0; i < N; i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
	return 0;
}