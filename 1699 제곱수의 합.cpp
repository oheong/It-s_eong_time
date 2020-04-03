#include<stdio.h>
#include<math.h>
#define SIZE 100001
int N;
int map[SIZE];
int min(int a, int b) {
	if (a < b)return a;
	else return b;
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		map[i] = i; // 1^iÀÇ °¹¼ö
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 2; j*j <= i; j++) {
			map[i] = min(map[i], map[i - j * j] + 1);
		}
	}
	printf("%d\n", map[N]);
	return 0;
}