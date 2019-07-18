#include <stdio.h>
#define SIZE 100000
int T, N, n, max;
int arr[SIZE], ans[SIZE];
void init() {
	for (int i = 0; i < N; i++) {
		arr[i] = 0;
		ans[i] = 0;
	}
	max = 0;
}
void sort() {
	int temp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
int abs(int a) {
	if (a < 0)return -1 * a;
	else return a;
}
int main() {
	//freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);
		}
		sort();
		for (int i = 0; i < N; i++) {
			if (i % 2 == 0) 
				ans[i / 2] = arr[i];
			else 
				ans[N - i / 2 - 1] = arr[i];
		}

		int temp = abs(ans[N - 1] - ans[0]);
		if (temp > max)max = temp;
		for (int i = 1; i < N; i++) {
			temp = abs(ans[i] - ans[i - 1]);
			if (temp > max)max = temp;
		}
		printf("#%d %d\n",test+1, max);
		init();
	}
	return 0;
}