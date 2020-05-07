#include <stdio.h>
int N, money, max;
typedef struct { int d; int m; }RUN;
RUN r[15];
//ㅅㅂ 진짜 배부른소리 쳐 하고있네 일이나해라 시발 퇴사가 말이야방구야씨발
//하 시발,,,,이거 방법 알아놓기 DPS
void dfs(int d, int m) {
	if (d >= N) {
		if (m > max)max = m;
		return;
	}
	if (d + r[d].d <= N) {
		dfs(d + r[d].d, m + r[d].m);
	}
	dfs(d + 1, m);
}
int main() {
	//freopen("Text.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &r[i].d, &r[i].m);
	}
	dfs(0, 0);
	printf("%d\n", max);
	return 0;
}