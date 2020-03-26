#include <stdio.h>
int N, count, flag;
int visited[10];
long long ans = -1;
void dfs(int d, int end, int n, long long num) {
	if (num > 9876543210)return;
	if (d == end) {
		count++;
		//printf("%d %d : %lld\n", d+1, count, num);
		if (count == N) {
			ans = num;
			flag = 1;
		}
		return;
	}
	for (int i = 0; i < n; i++) {
		dfs(d + 1, end, i, num * 10 + i);
	}
}
int main() {
	scanf("%d", &N);
	if (0 <= N && N < 10) {
		printf("%d\n", N);
		return 0;
	}
	else if (N <= 1000000) {
		count = 9;
		for (int i = 0; i <= 10; i++) { // ÀÚ¸´¼ö
			for (int j = 1; j < 10; j++) {
				dfs(0, i, j, j);
				if (flag == 1) {
					printf("%lld\n", ans);
					return 0;
				}
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}

//31%?