#include <stdio.h>
int N, money, max;
typedef struct { int d; int m; }RUN;
RUN r[15];
//���� ��¥ ��θ��Ҹ� �� �ϰ��ֳ� ���̳��ض� �ù� ��簡 ���̾߹汸�߾���
//�� �ù�,,,,�̰� ��� �˾Ƴ��� DPS
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