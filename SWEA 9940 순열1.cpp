#include <stdio.h>
#define SIZE 100001
int T, N, a;
int map[SIZE];
void init() {
	for (int i = 1; i <= N; i++) {
		map[i] = 0;
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d", &N);
		bool flag = false;
		for (int i = 0; i < N; i++) {
			scanf("%d", &a);
			map[a]++;
			if (1 < map[a])
				flag = true;
		}
		if (flag == true) 
			printf("#%d No\n", test + 1);
		else printf("#%d Yes\n", test + 1);
		init();
	}
	return 0;
}
// 5°³´Â ¹¹¾ß?