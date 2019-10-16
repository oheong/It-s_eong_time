//자료형 ㅅㅂ 진짜ㅎㅎ
#include <stdio.h>
#define SIZE 1000000
int N, A, B, C;
long long map[SIZE], ans;
int get_ans(int a) {
	a -= B;
	if (a > 0) {
		if (a%C == 0) return a / C + 1;
		else return a / C + 2;
	}
	return 1;
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++)scanf("%d ", &map[i]);
	scanf("%d %d", &B, &C);
	for (int i = 0; i < N; i++) ans += get_ans(map[i]);
	printf("%ld\n", ans);
	return 0;
}