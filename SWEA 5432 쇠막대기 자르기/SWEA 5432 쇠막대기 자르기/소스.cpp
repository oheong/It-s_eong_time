#include <stdio.h>
#define SIZE 100002
int T, count, ans;
char arr[SIZE];
void init() {
	ans = 0;
	count = 0;
	for (int i = 0; arr[i] != '\0'; i++) arr[i] = '\0';
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%s", arr);
		for (int i = 0; i < arr[i] != '\0'; i++) {
			if (arr[i] == '(') {
				if (arr[i + 1] == ')') {
					i++; ans += count;
				}
				else {
					ans++;
					count++;
				}
			}
			else {
				count--;
			}
		}

		printf("#%d %d\n", test + 1, ans);
		init();
	}
	return 0;
}