#include <stdio.h>
int N, ans;
int getN(int a) {
	int r = 1;
	while (1) {
		a = a / 10;
		if (a < 1)return r;
		else r++;
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		ans += getN(i);
	}
	printf("%d\n", ans);
}