/*
LIS 알고리즘 https://jason9319.tistory.com/113
*/
#include <stdio.h>
#define SIZE 1050
int N, ans, l;
int input1[SIZE], input2[SIZE];
int up[SIZE], down[SIZE];
void gogo(int real[], int copy[]) {
	copy[0] = 1;
	for (int i = 1; i < N; i++) {
		copy[i] = 1;
		for (int j = 0; j < i; j++) {
			if (real[j] < real[i] && copy[j] + 1 > copy[i])
				copy[i] = copy[j] + 1;
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &input1[i]);
		input2[N - 1 - i] = input1[i];
	}
	gogo(input1, up);
	gogo(input2, down);
	int max = 0;
	for (int i = 0; i < N; i++) {
		ans = up[i] + down[N - 1 - i] - 1;
		if (max < ans)max = ans;
	}
	printf("%d\n", max);
	return 0;
}