#include <stdio.h>
int N, M;
int arr[8], visited[8];
void dfs(int d,int n) {
	if (d == M) {
		for (int i = 0; i < N; i++) {
			if (visited[i] == 1) {
				printf("%d ", arr[i]);
			}
		}
		printf("\n");
		return;
	}
	for (int i = n; i < N; i++) {
		if (visited[i] == 1)continue;
		visited[i] = 1;
		dfs(d + 1, i);
		visited[i] = 0;
	}
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) arr[i] = i + 1;
	dfs(0, 0);
	return 0;
}