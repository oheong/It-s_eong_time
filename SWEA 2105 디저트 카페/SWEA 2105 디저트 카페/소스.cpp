#include<stdio.h>
#define SIZE 20
#define nyam 101
int T, N, max, startX, startY, right, left;
int map[SIZE][SIZE], visited[SIZE][SIZE], eat[nyam], by[4] = { 1,1,-1,-1 }, bx[4] = { -1,1,1,-1 };
int isEat(int y, int x) {//이미 먹었던 디저트인가?
	if (eat[map[y][x]] == 1) return 1;//먹었던거임;;
	else return 0;//먹었던거 아님
}
int isIn(int y, int x) {//범위 안인가?
	if (0 <= y && y < N && 0 <= x && x < N) return 0;//ㅇㅇ범위 안임
	else return 1;//범위 안 아님ㅠ
}
void round(int d, int ty, int tx, int r, int l) {
	if (ty == startY && tx == startX && d > 3) {
		if (max < d) max = d;
		return;
	}
	if (isEat(ty, tx) == 1)
		return;
	if (isIn(ty, tx) == 1)
		return;
	eat[map[ty][tx]] = 1;
	visited[ty][tx] = 1;

	/*
	왼쪽아래 0
	오른쪽 아래 1
	오른쪽 위 2
	왼쪽 위 3
	*/


	//와 시발 이거 조건 죽인다,,,,,,,나는 개 빡대가리야,,,,,,,,,
	if (left < l&&right < r) {
		round(d + 1, ty + by[0], tx + bx[0], r, l - 1);
	}
	else if (left == l && right < r) {
		round(d + 1, ty + by[1], tx + bx[1], r - 1, l);
	}
	else if (0 < l&&l <= left && right == r) {
		round(d + 1, ty + by[2], tx + bx[2], r, l - 1);
	}
	else if (l == 0 && r <= right) {
		round(d + 1, ty + by[3], tx + bx[3], r - 1, l);
	}
	eat[map[ty][tx]] = 0;
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
		max = -1;
		for (int r = 1; r < N - 1; r++) {
			for (int l = 1; l < N - 1; l++) {
				if (r + l <= N - 1) {
					for (int i = 0; i < N - 1; i++) {
						for (int j = 1; j < N; j++) { //왼쪽 아래로 내려갈 수 있나?
							startY = i;
							startX = j;
							right = r;
							left = l;
							round(0, i, j, 2 * r, 2 * l);
						}
					}
				}
			}
		}
		printf("#%d %d\n", test + 1, max);
	}
	return 0;
}