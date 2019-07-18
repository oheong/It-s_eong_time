#include <stdio.h>
int arr[101];
int ans, n;
void init() {
	ans = 0;
	for (int i = 1; i < 101; i++) arr[i] = 0;
}
void count() {
	for (int i = 1; i < 51; i++) {
		if (arr[i] == 1 && arr[i * 2] == 1) ans++;
	}
}
int main() {
	//freopen("Text.txt", "r", stdin);
	while (n != -1) {
		scanf("%d", &n);
		if (n == 0) {
			count();
			printf("%d\n", ans);
			init();
		}
		else arr[n] = 1;
	}
	return 0;
}