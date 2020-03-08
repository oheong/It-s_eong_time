#include <stdio.h>
#include<iostream>

using namespace std;

#define SIZE 1000001
int T, X, minimum, cnt, len;
int map[10], num[SIZE];
int get_len(int t) {
	int l = 0;
	while (t > 0) {
		t /= 10;
		l++;
	}
	return l;
}
void dfs(int d, int n) { // 지금 만드는 숫자 길이, 
	if (d > len)return;
	if (n > X)return;
	if (0 < d&&n == 0)return;
	num[cnt++] = n;
	if (n == X)minimum = len + 1;
	for (int i = 0; i < 10; i++) {
		if (map[i] == 1) {
			dfs(d + 1, n * 10 + i);
		}
	}
}
void get_ans(int d, int n, int ans) {
	if (d > len)return;
	if (n == 1) {
		if (ans < minimum)minimum = ans;
		return;
	}
	if (minimum < ans)return;

	for (int i = 0; i < cnt; i++) {
		if (num[i] == 0)continue;
		if (n%num[i] == 0) {
			get_ans(d + 1, n / num[i], ans + get_len(num[i]) + 1);
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		for (int i = 0; i < 10; i++)
			scanf("%d", &map[i]);
		scanf("%d", &X);
		len = get_len(X);
		cnt = 0;
		minimum = 2123456789;
		dfs(0, 0);

		if (X == 1 && map[1] == 1) {
			printf("#%d %d\n", test + 1, 2);
			continue;
		}
		get_ans(0, X, 0);

		if (minimum == 2123456789)minimum = -1;
		printf("#%d %d\n", test + 1, minimum);
	}
	return 0;
}
//99개,,,,,?ㅠ