#include <stdio.h>
int min = 2123456789, T;
int A, B, C, D, E, F, N, M, aa, bb, cc, dd, ty, tx, fy, fx;
int getnum[3][4], map[3][4], visited[2][100][7][7];
void make_square(int a, int b, int c, int d, int e, int f, int in_f, int in_t) {
	for (int i = 0; i < 4; i++)	getnum[0][i] = a;
	getnum[1][0] = b; getnum[1][1] = d; getnum[1][2] = e; getnum[1][3] = f;
	for (int i = 0; i < 4; i++)	getnum[2][i] = c;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			if (getnum[i][j] == in_f) {//front
				map[2][2] = getnum[i][j];
				fy = i; fx = j;
				if (getnum[i][(j + 2) % 4] != getnum[i][j]) {//ÁÂ¿ì
					map[0][2] = getnum[i][(j + 2) % 4];
				}
				else if (getnum[(i + 2) % 4][j] != getnum[i][j]) {//À§¾Æ·¡
					map[0][2] = getnum[(i + 2) % 4][j];
				}
			}
			else if (getnum[i][j] == in_t) {//top
				map[1][2] = getnum[i][j];
				ty = i; tx = j;
				if (getnum[i][(j + 2) % 4] != getnum[i][j]) {//ÁÂ¿ì
					map[1][0] = getnum[i][(j + 2) % 4];
				}
				else if (getnum[(i + 2) % 4][j] != getnum[i][j]) {//À§¾Æ·¡
					map[1][0] = getnum[(i + 2) % 4][j];
				}
			}
			if (i == 0 || 3)break;
		}
	}
	int rr = 0, ll = 0;
	if (fy == ty) {
		if (fx < tx) {
			ll = getnum[ty - 1][tx];
			rr = getnum[ty + 1][tx];
		}
		else {
			ll = getnum[ty + 1][tx];
			rr = getnum[ty - 1][tx];
		}
	}
	else if (fy > ty) {
		if (getnum[fy][fx] == getnum[fy][fx + 1]) {
			ll = getnum[1][3];
			rr = getnum[ty][tx + 1];
		}
		else {
			ll = getnum[1][3];
			rr = getnum[fy][fx + 1];
		}
	}
	else {
		if (getnum[fy][fx] == getnum[fy][fx + 1]) {
			ll = getnum[ty][tx + 1];
			rr = getnum[1][3];
		}
		else {
			ll = getnum[fy][fx + 1];
			rr = getnum[1][3];
		}
	}
	map[1][3] = rr;
	map[1][1] = ll;
}
void dfs(int d, int front, int top, int back, int down, int left, int right, int y, int x) {
	if (y < 0 || N <= y || x < 0 || M <= x) return;
	if (d > M*N) return;
	if (front == cc && top == dd && y == N - 1 && x == M - 1) {
		if (min > d)min = d;
		return;
	}
	//printf("%d %d %d %d %d %d\n", front, top, back, down, left, right);
	if (visited[y][x][front][top] == 1) return;
	visited[y][x][front][top] = 1;
	//¿À¸¥
	dfs(d + 1, front, left, back, right, down, top, y, x + 1);
	//¾Æ·¡
	dfs(d + 1, top, back, down, front, left, right, y + 1, x);
	//¿Þ
	dfs(d + 1, front, right, back, left, top, down, y, x - 1);
	//À§
	dfs(d + 1, down, front, top, back, left, right, y - 1, x);
	visited[y][x][front][top] = 0;
}
int main(void) {
	freopen("Text1.txt", "r", stdin);
	scanf("%d", &T);
	for (int test_case = 0; test_case < T; test_case++)
	{
		scanf("%d %d %d %d %d %d %d %d %d %d %d %d", &A, &B, &C, &D, &E, &F, &N, &M, &aa, &bb, &cc, &dd);

		make_square(A, B, C, D, E, F, aa, bb);
		dfs(0, map[2][2], map[1][2], map[0][2], map[1][0], map[1][1], map[1][3], 0, 0);

		printf("Case #%d\n", test_case + 1);

		if (min == 2123456789)printf("%d\n", -1);
		else printf("%d\n", min);
		min = 2123456789;
		//init();
	}
	return 0;
}
/*
2
-1
5
-1
7
9
-1
*/