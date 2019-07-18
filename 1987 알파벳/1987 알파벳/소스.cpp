#include <stdio.h>
#define SIZE 25
int C, R, max = 0, x, y;
bool alph[26];
char map[SIZE][SIZE];
void dfs(int d, int yy, int xx) {
	if (yy < 0 || yy >= R || xx < 0 || xx >= C || alph[map[yy][xx] - 65] == true)
		return;
	if (max < d) {
		max = d;
	}

	alph[map[yy][xx] - 65] = true;

	dfs(d + 1, yy, xx + 1);//©Л

	dfs(d + 1, yy + 1, xx);//го

	dfs(d + 1, yy, xx - 1);//аб

	dfs(d + 1, yy - 1, xx);//╩С

	alph[map[yy][xx] - 65] = false;
}
int main() {
	//freopen("Text.txt", "r", stdin);
	scanf("%d %d\n", &R, &C);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j <= C; j++) {
			scanf("%c", &map[i][j]);
			if (i == 0 && j == 0) {
			}
		}
	}
	dfs(1, 0, 0);
	printf("%d\n", max);
	return 0;
}