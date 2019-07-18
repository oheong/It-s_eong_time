#include <stdio.h>
#define SIZE 100005
int T, N, Q, L, R;
int cow[3][SIZE];
int main() {
	//freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		printf("#%d\n", test + 1);
		scanf("%d %d", &N, &Q);
		int n;
		for (int i = 1; i <= N; i++) {
			scanf("%d", &n);
			cow[0][i] = cow[0][i - 1];
			cow[1][i] = cow[1][i - 1];
			cow[2][i] = cow[2][i - 1];
			cow[n - 1][i] = cow[n - 1][i - 1] + 1;
		}
		for (int q = 0; q < Q; q++) {
			scanf("%d %d", &L, &R);
			for (int a = 0; a < 3; a++) {
				printf("%d ", cow[a][R] - cow[a][L - 1]);
			}
			printf("\n");
		}
	}
	return 0;
}