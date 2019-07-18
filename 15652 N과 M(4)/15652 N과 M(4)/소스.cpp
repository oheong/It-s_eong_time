#include <stdio.h>
int N, M;
int arr[8];
void dfs(int d, int n) {
	if (d == M) {
		for (int i = 0; i < M; i++)printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	for (int i = n; i < N; i++) {
		arr[d] = i + 1;
		dfs(d + 1, i);
	}
}
int main() {
	scanf("%d %d", &N, &M);
	dfs(0, 0);
	return 0;
}