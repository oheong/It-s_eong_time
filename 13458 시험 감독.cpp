#include <stdio.h>
long long N, A, B, C, ans;
long long map[1000000];
int get_ans(int a) {
	a -= B;
	if (a <= 0)return 1;
	else {
		if (a%C == 0) return (a / C) + 1;
		else return (a / C) + 2;
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d ", &map[i]);
	}
	scanf("%d %d", &B, &C);
	for (int i = 0; i < N; i++) ans += get_ans(map[i]);
	printf("%ld\n", ans);
	return 0;
}