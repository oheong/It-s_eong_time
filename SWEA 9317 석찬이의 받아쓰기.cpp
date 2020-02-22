#include <stdio.h>
char Ans[100001], chan[100001];
int T, len;
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d\n", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d", &len);
		scanf("%s", &Ans);
		scanf("%s", &chan);
		int dif = 0;
		for (int i = 0; i < len; i++) {
			if (Ans[i] == chan[i])dif++;
		}
		printf("#%d %d\n", test + 1, dif);
	}
	return 0;
}