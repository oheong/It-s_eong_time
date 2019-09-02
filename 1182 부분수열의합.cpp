#include <stdio.h>
int N, S, ans;
int map[20], visited[20];
void dfs(int d) {
	if (d == N) {
		int count = 0;
		int temp = 0;
		for (int i = 0; i < N; i++) {
			if (visited[i] == 1) {
				temp += map[i];
			}
			else count++;
		}
		if (count == N) return;//공집합은 제외시킴
		else if (temp == S) ans++;
		return;
	}
	visited[d] = 1;
	dfs(d + 1);
	visited[d] = 0;
	dfs(d + 1);
}
int main() {
	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++) {
		scanf("%d", &map[i]);
	}
	dfs(0);
	printf("%d\n", ans);
	return 0;
}