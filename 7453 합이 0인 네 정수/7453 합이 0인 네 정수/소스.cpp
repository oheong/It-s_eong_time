#include <stdio.h>
#define SIZE 4000
int N, count;
int A[4][SIZE];
void dfs(int d, int sum) {
	if (d == 4) {
		if (sum == 0)count++;
		return;
	}
	for (int i = 0; i < N; i++) {
		dfs(d + 1, sum + A[d][i]);
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d %d", &A[0][i], &A[1][i], &A[2][i], &A[3][i]);
	}
	dfs(0, 0);
	printf("%d\n", count);
	return 0;
}