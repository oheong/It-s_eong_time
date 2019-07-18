#include <stdio.h>
int N, flag;
int input[40][21], map[21][21];
void make_first(int n) {
	flag = 1;
	int j = 0;
	if (n < N) {
		int here = 0;
		for (int i = 1; i <= input[n][0]; i++) {
			for (j = 0; j < input[n][i]; j++) {//1ÀÌ ÀûÈú °¹¼ö
				map[n][here++] = 1;
			}
			map[n][here++] = 0;
		}
	}
	else {
		int here = 0;
		for (int i = 1; i <= input[n][0]; i++) {
			for (int j = 0; j < input[n][i]; j++) {//1ÀÌ ÀûÈú °¹¼ö
				map[here++][(n / N) - 1] = 1;
			}
			map[here++][(n / N) - 1] = 0;
		}
	}
}
void make_zero(int check, int num, int n) {
	if (check == 1) {//¼¼·Î
		for (int i = 0; i < n; i++) map[i][num - 8] = 0;
	}
	else {//°¡·Î
		for (int i = 0; i < n; i++) map[num][i] = 0;
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N * 2; i++) {
		scanf("%d", &input[i][0]);
		int sum = input[i][0];
		for (int j = 1; j <= input[i][0]; j++) {
			scanf("%d", &input[i][j]);
			sum += input[i][j];
		}
		//if (sum - 1 == N) {
		//	make_first(i);
		//}
	}
	for (int i = 0; i < N / 2; i++) {
		//N-1-i 
		//i 
		if (input[N - 1 - i][0] == 0) make_zero(1, N - 1 - i, i + 1);

		//N/2-1-i
		//N/2+i
	}

	return 0;
}