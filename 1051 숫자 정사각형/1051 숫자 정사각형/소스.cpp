#include <Stdio.h>
#define SIZE 50
int N, M, max, ans;
int map[SIZE][SIZE];
int what_is() {
	if (N > M) return M;
	else return N;
}
int square(int num1, int num2, int num3, int num4) {
	if (num1 == num2 && num1 == num3 && num1 == num4) return 1;
	else return 0;
}
void search(int size) {
	for (int i = 0; i <= N - size; i++) {
		for (int j = 0; j <= M - size; j++) {
			if (square(map[i][j], map[i][j + size - 1], map[i + size - 1][j], map[i + size - 1][j + size - 1]) == 1) {
				int temp = size * size;
				if (ans < temp)ans = temp;
			}
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	max = what_is();

	for (int i = 1; i <= max; i++) search(i);
	printf("%d\n", ans);
	return 0;
}