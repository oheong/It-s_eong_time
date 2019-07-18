#include <stdio.h>
int T, M, A, Ax, Ay, By, Bx, ans;
typedef struct { int y; int x; int c; int p; }AP;
AP ap[10];
typedef struct { int w1; int w2; int a; int b; }VALUE;
VALUE value[8];
int man[2][102], by[5] = { 0,-1,0,1,0 }, bx[5] = { 0,0,1,0,-1 };
int abs(int a) {
	if (a < 0)return -1 * a;
	else return a;
}
void init() {
	for (int i = 0; i < A; i++) {
		value[i].w1 = 0;
		value[i].w2 = 0;
		value[i].a = 0;
		value[i].b = 0;
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d %d", &M, &A);
		for (int i = 0; i < 2; i++) {
			for (int m = 1; m <= M; m++) {
				scanf("%d", &man[i][m]);
			}
		}
		for (int i = 0; i < A; i++) {
			scanf("%d %d %d %d", &ap[i].x, &ap[i].y, &ap[i].c, &ap[i].p);
			ap[i].x--; ap[i].y--;
		}
		Ay = Ax = 0;
		By = Bx = 9;
		for (int m = 0; m <= M; m++) {//사람 이동 수
			Ay += by[man[0][m]]; Ax += bx[man[0][m]];
			By += by[man[1][m]]; Bx += bx[man[1][m]];
			for (int a = 0; a < A; a++) {//AP갯수
				value[a].w1 = value[a].w2 = a;
				int Da = abs(ap[a].y - Ay) + abs(ap[a].x - Ax);
				int Db = abs(ap[a].y - By) + abs(ap[a].x - Bx);
				if (ap[a].c >= Da && ap[a].c >= Db) { //둘다 안정권임
					value[a].a = ap[a].p;
					value[a].b = ap[a].p;

				}
				else if (ap[a].c >= Da && ap[a].c < Db) { //A만 잡힘
					value[a].a = ap[a].p;
					value[a].b = 0;
				}
				else if (ap[a].c < Da && ap[a].c >= Db) { //B만 잡힘
					value[a].a = 0;
					value[a].b = ap[a].p;
				}
				else {
					value[a].a = 0;
					value[a].b = 0;
				}
			}
			int tempsum = 0;
			for (int i = 0; i < A; i++) {
				for (int j = 0; j < A; j++) {
					int sb = value[i].a + value[j].b;
					if (A > 1 && value[i].w1 == value[j].w2)
						sb /= 2;
					if (tempsum < sb)
						tempsum = sb;
				}
			}
			ans += tempsum;
			init();
		}
		printf("#%d %d\n", test + 1, ans);
		ans = 0;
	}
	return 0;
}