#include <stdio.h>
#define SIZE 20
int T, N, M, temp, max, ans; // 최대 정답, 사람 수
int p[SIZE];
int main() {
	scanf("%d", &T);
	for (int test = 0;test < T;test++) {
		scanf("%d %d", &N, &M);
		max = ans = 0;
		for (int i = 0;i < N;i++) {
			int sum = 0;
			for (int j = 0;j < M;j++) {
				scanf("%d", &temp);
				if (temp == 1)sum += 1;
			}
			p[i] = sum;
			if (max < sum)max = sum;
		}
		for (int i = 0;i < N;i++)
			if (p[i] == max) ans++;
		printf("#%d %d %d\n", test + 1, ans, max);
	}
	return 0;
}