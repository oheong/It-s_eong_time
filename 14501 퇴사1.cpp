#include <stdio.h>
int N, max;
typedef struct { int day; int money; }MAP;
MAP map[15];
void dfs(int day, int money) {
	if (day >= N) {
		if (money > max)max = money;
		return;
	}
	if (day + map[day].day <= N) dfs(day + map[day].day, money + map[day].money);//¤µ¤²
	dfs(day + 1, money);
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &map[i].day, &map[i].money);
	}
	dfs(0, 0);
	printf("%d\n", max);
	return 0;
}