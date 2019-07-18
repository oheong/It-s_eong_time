#include<stdio.h>
#define SIZE 20
int T, N, max = -1, starty, startx;
int map[SIZE][SIZE], visited[SIZE][SIZE], dessert[101], by[4] = { 1,1,-1,-1 }, bx[4] = { 1,-1,-1,1 };
int way[4];
int isOk(int y, int x) {
	if (y < 0 || y >= N || x < 0 || x >= N) return 0;//범위 벗어남
	else return 1;// 범위 안벗어남
}
void init() {
	for (int i = 1; i < 101; i++)dessert[i] = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 0;
		}
	}
}
void dfs(int depth, int ty, int tx, int d, int r, int u, int l) {
	if (ty == starty && tx == startx && depth > 1) {
		if (max < depth)max = depth;
		return;
	}
	if (isOk(ty, tx) == 0 || dessert[map[ty][tx]] == 1)
		return;

	dessert[map[ty][tx]] = 1;
	visited[ty][tx] = 2;
	if (d > 0) {
		dfs(depth + 1, ty + by[0], tx + bx[0], d - 1, r, u, l);
	}
	else if (d == 0 && r > 0) {
		dfs(depth + 1, ty + by[1], tx + bx[1], d, r - 1, u, l);
	}
	else if (d == 0 && r == 0 && u > 0) {
		dfs(depth + 1, ty + by[2], tx + bx[2], d, r, u - 1, l);
	}
	else if (d == 0 && r == 0 && u == 0 && l > 0) {
		dfs(depth + 1, ty + by[3], tx + bx[3], d, r, u, l - 1);
	}
}
int main() {
	//freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		for (int y = 1; y < N - 1; y++) {
			for (int x = 1; x < N - 1; x++) {//x,y 길이. 만들어 지는 사각형의 선분길이!!
				if (y + x <= N) {
					for (int i = 0; i < 4; i++) {
						if (i % 2 == 0) way[i] = y;
						else way[i] = x;
					}
					for (int i = 0; i < N - 1; i++) {
						for (int j = 1; j < N - 1; j++) {
							//시작점 어느 i,j 좌표에서 시작할것인가?
							starty = i; startx = j;
							dessert[map[i][j]] = 1;
							visited[i][j] = 1;
							dfs(1, i + by[0], j + bx[0], y - 1, x, y, x);
							init();
						}
					}
				}
			}
		}
		init();
		printf("#%d %d\n", test + 1, max);
		max = -1;
	}
	return 0;
}