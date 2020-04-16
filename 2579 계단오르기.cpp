#include <stdio.h>
int N;
int map[301], dp[301];
int max(int a, int b) {
	if (a < b)return b;
	else return a;
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &map[i]);
	}
	dp[1] = map[1];
	dp[2] = map[1] + map[2];
	dp[3] = max(map[1] + map[3], map[2] + map[3]);

	for (int i = 4; i <= N; i++) {
		dp[i] = max(dp[i - 2] + map[i], dp[i - 3] + map[i - 1] + map[i]);
		printf("%d\n", dp[i]);
	}
	printf("%d\n", dp[N]);
	return 0;
}