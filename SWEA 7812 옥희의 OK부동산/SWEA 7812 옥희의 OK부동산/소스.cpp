#include <stdio.h>
#define SIZE 10002
int N, M, T;
long int map[SIZE];
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		int a;
		scanf("%d %d", &N, &M);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &a);
			map[i] = map[i - 1] + a;
		}
		int ans = 0, i = 0, j = 0;
		while (i <= N && j <= N) {
			int t = map[j] - map[i];
			if (t == M) {
				i++;
				ans++;
			}
			else if (t < M) j++;
			else if (t >= M) i++;
		}
		printf("#%d %d\n", test + 1, ans);
	}
	return 0;
}