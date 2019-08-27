#include<stdio.h>
#define SIZE 50
int N, M, H, C, ans = 2123456789;
int map[SIZE][SIZE], visited[13], min[2 * SIZE];
typedef struct { int y; int x; }WHAT;
WHAT house[2 * SIZE], chicken[13];
int abs(int a) {
	if (a > 0)return a;
	else return -1 * a;
}
void init() {
	for (int i = 0; i < H; i++) min[i] = 2123456789;
}
void dfs(int d, int n) {
	if (d == M) {
		init();
		for (int i = 0; i < 13; i++) {
			if (visited[i] == 1) {//치킨집 골라서
				for (int h = 0; h < H; h++) {
					int t = abs(house[h].y - chicken[i].y) + abs(house[h].x - chicken[i].x);
					if (t < min[h])min[h] = t;
				}
			}
		}
		int sum = 0;
		for (int h = 0; h < H; h++) {
			sum += min[h];
		}
		if (ans > sum)ans = sum;
		return;
	}
	for (int i = n; i < C; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			dfs(d + 1, i + 1);
			visited[i] = 0;
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) {//집
				house[H].y = i;
				house[H].x = j;
				H++;
			}
			else if (map[i][j] == 2) {//치킨집
				chicken[C].y = i;
				chicken[C].x = j;
				C++;
			}
		}
	}
	dfs(0, 0);
	printf("%d\n", ans);
	return 0;
}