#include <stdio.h>
#define SIZE 100
int R, C, M, r, c, s, d, z, ans;
int state[SIZE][SIZE], by[4] = { -1,1,0,0 }, bx[4] = { 0,0,1,-1 };
typedef struct { int ym; int r; int c; int s; int d; int z; }SHARK;
SHARK shark[SIZE*SIZE];
void get_shark(int man) {
	for (int i = 0; i < R; i++) {
		if (state[i][man] == 1) {
			for (int j = 0; j < M; j++) {
				if (shark[j].ym == 1 && shark[j].r == i && shark[j].c == man) {
					shark[j].ym = 0;
					ans += shark[j].z;
					state[i][man] = 0;
					return;
				}
			}
		}
	}
}
void move(int num, int y, int x, int dir, int speed) {
	state[y][x]--;//일단 state에 상어 없애줌
	for (int s = 0; s < speed; s++) {
		int ny = y + by[dir];
		int nx = x + bx[dir];
		if (0 <= ny && ny < R && 0 <= nx && nx < C) {
			y += by[dir];
			x += bx[dir];
		}
		else {
			//dir = (dir + 2) % 4;
			if (dir == 0)dir = 1;
			else if (dir == 1)dir = 0;
			else if (dir == 2)dir = 3;
			else if (dir == 3)dir = 2;
			y += by[dir];
			x += bx[dir];
		}
	}
	state[y][x]++;
	shark[num].r = y;
	shark[num].c = x;
	shark[num].d = dir;
}
void eat(int y, int x) {
	int w = 0, max = 0, dir = 0, speed = 0;
	for (int i = 0; i < M; i++) {
		if (shark[i].ym == 1 && shark[i].r == y && shark[i].c == x) {
			if (shark[i].z > max) {//크기 비교
				w = i;
				max = shark[i].z;
				dir = shark[i].d;
				speed = shark[i].s;
			}
			shark[i].ym = shark[i].s = shark[i].d = shark[i].z = 0;
		}
	}
	state[y][x] = 1;
	shark[w].ym = 1;
	shark[w].r = y;
	shark[w].c = x;
	shark[w].z = max;
	shark[w].d = dir;
	shark[w].s = speed;
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d %d", &R, &C, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
		shark[i].ym = 1;
		shark[i].r = r - 1;
		shark[i].c = c - 1;
		shark[i].s = s;
		shark[i].d = d - 1;
		shark[i].z = z;
		state[shark[i].r][shark[i].c] = 1;
	}
	int man = 0;
	while (man < C) {
		get_shark(man);
		for (int i = 0; i < M; i++) {
			if (shark[i].ym == 1) {
				move(i, shark[i].r, shark[i].c, shark[i].d, shark[i].s);
			}
		}
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (1 < state[i][j]) {
					eat(i, j);
				}
			}
		}
		man++;
	}
	printf("%d\n", ans);
	return 0;
}