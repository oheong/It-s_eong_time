#include <stdio.h>
// 1¹ø ¹®Á¦
int N, K, max_inner;
int num[100001], count[10], map[10][100000];
int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%1d", &num[i]);
		map[num[i]][count[num[i]]] = i;
		count[num[i]]++;
	}
	for (int i = 9; 0 <= i; i--) {
		if (count[i] == 0)continue;

		for (int c = 0; c < count[i]; c++) {
			int start = map[i][c];
			int sum = 0;
			for (int k = 0; k < K; k++) {
				if (start + k < N) {
					sum = sum * 10;
					int temp = num[start + k];
					sum += temp;
				}
				else break;
			}
			if (max_inner < sum) {
				max_inner = sum;
			}
		}
	}
	printf("%d\n", max_inner);
	return 0;
}