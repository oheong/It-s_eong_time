#include <stdio.h>
#define SIZE 12
int N, M, r, c, d;
int map[SIZE][SIZE], by[4] = { -1,0,1,0 }, bx[4] = { 0,-1,0,1 };
int gogo(int y, int x, int d) {
	int clean = 0;//현재위치 청소
	int ty = y, tx = x, td = d;
	int ny, nx, nd, state = 0;
	while (1) {
		if (map[ty][tx] == 0) {
			map[ty][tx] = 9;
			clean++;
		}
		//다음 위치 지정
		nd = (td + 1) % 4;//왼쪽 보기
		ny = ty + by[nd];
		nx = tx + bx[nd];//다음 방향

		if (map[ny][nx] == 0) {//청소 안되어있으면?
			ty = ny;
			tx = nx;
			td = nd;
			state = 0;
		}
		else {//청소되어 있으면?
			td = nd;
			state++;
			if (state == 4) {
				//후진한당
				state = 0;
				nd = (td + 2) % 4;
				ny = ty + by[nd];
				nx = tx + bx[nd];
				if (map[ny][nx] == 1) {
					return clean; //후진불가 끝내
				}
				else {//후진 쌉가능
					ty = ny;
					tx = nx;
				}
			}
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d %d %d %d", &N, &M, &r, &c, &d);//d 방향
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	printf("%d\n", gogo(r, c, (4 - d) % 4));
	return 0;
}