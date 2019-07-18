#include <stdio.h>
#define SIZE 40
/*
연구소 벽 쌓을때처럼 벽 쌓은 이후의것들만 체크하면됨!!!!!!!!!

시발 왜틀리는거지 안해 ㅅㅂ
*/
int T, N, M, H, a, b, max = -1, cnt = 1;
int map[SIZE][SIZE], bx[2] = { 1,-1 };
bool flag;
int search(int n) {
	for (int h = 0; h <= H; h++) {
		if (map[h][n] != 0) {
			for (int i = 0; i < 2; i++) {
				int nn = n + bx[i];
				if (map[h][n] == map[h][nn]) {
					n = nn;
					break;
				}
			}
		}
	}
	return n;
}
void dfs(int v, int d) {
	flag = false;
	for (int i = 0; i < N; i++) {
		if (i != search(i)) {
			flag = true;
			break;
		}
	}
	if (flag == false) {
		max = d;
		return;
	}
	if (d >= 3)return;
	for (int i = v; i < H*N - 1; i++) {
		int y = i / N;
		int x = i % N;
		if (x == 0 || map[y][x] != 0 || x == N - 1)continue;
		if (map[y][x] == 0 && map[y][x + 1] == 0) {
			map[y][x] = cnt;
			map[y][x + 1] = cnt++;
			dfs(i + 2, d + 1);
			map[y][x] = 0;
			map[y][x + 1] = 0;
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d %d", &N, &M, &H);
	int a, b;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		map[a - 1][b - 1] = cnt;
		map[a - 1][b] = cnt++;
	}
	dfs(0, 0);
	printf("%d\n", max);
	return 0;
}