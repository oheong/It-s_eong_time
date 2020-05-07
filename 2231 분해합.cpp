#include <stdio.h>
#define SIZE 7
int N, min = 2123456789, n, last_num, temp, ssj;
int arr[SIZE];
int get_n(int a) {
	int i;
	for (i = 0; i < SIZE; i++) {
		a /= 10;
		if (a < 1)
			return i + 1;
		last_num = a;
	}
}
int get_ssj() {
	temp = 0, ssj = 0;
	for (int i = n - 1; 0 <= i; i--) {
		ssj += arr[i];//자릿수 숫자대로 계속 더하고
		temp += arr[i];//전체숫자를 구함
		if (i != 0)
			temp *= 10;
	}
	ssj += temp;
	return ssj;
}
void dfs(int d) {
	if (d == -1) {
		int value = get_ssj();
		if (value == N) {
			if (min > temp) min = temp;
		}
		return;
	}
	for (int i = 0; i < 10; i++) {
		arr[d] = i;
		dfs(d - 1);
	}
}
int main() {
	scanf("%d", &N);
	n = get_n(N);//n자리 숫자

	for (int i = 0; i <= last_num; i++) {
		arr[n - 1] = i;
		dfs(n - 1);
	}
	if (min == 2123456789)printf("%d\n", 0);
	else
		printf("%d\n", min);
	return 0;
}