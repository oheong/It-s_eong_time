#include <stdio.h>
int map[10][10], moveA[100], moveB[100];
int bx[5] = { 0,0,1,0,-1 }, by[5] = { 0,-1,0,1,0 };
int testcase, M, A, C, max = 0;//M이동시간 A충전기(BC)의갯수 C충전범위 
typedef struct INFOBC { int y;	int x;	int c;	int p; }INFOBC;
INFOBC infobc[8];
typedef struct PLUS { int a; int b; int ai; int bi; }PLUS;
PLUS plus[8];
int abs(int a) {
	if (a < 0)return -1 * a;
	else return a;
}
int getDistance(int BCy, int BCx, int MEy, int MEx) {
	return abs(BCx - 1 - MEx) + abs(BCy - 1 - MEy);
}
void init(int a) {
	if (a == 0) {
		for (int i = 0; i < A; i++) {
			plus[i].a = 0;
			plus[i].b = 0;
		}
	}
	else {
		max = 0;
		for (int i = 0; i < M; i++) {
			moveA[i] = 0;
			moveB[i] = 0;
			infobc[i].x = 0;
			infobc[i].y = 0;
			infobc[i].c = 0;
			infobc[i].p = 0;
		}
	}
}
void charge(int ay, int ax, int by, int bx) {
	for (int i = 0; i < A; i++) {//모든 충전기와 현재 내 위치와의 거리를 계산한다.
		int Da = getDistance(infobc[i].y, infobc[i].x, ay, ax);
		int Db = getDistance(infobc[i].y, infobc[i].x, by, bx);

		plus[i].ai = plus[i].bi = i;

		if (infobc[i].c >= Da && infobc[i].c >= Db) {//A B둘다 잡힘
			plus[i].a = infobc[i].p;
			plus[i].b = infobc[i].p;
		}
		else if (infobc[i].c < Da && infobc[i].c >= Db) {//B만 잡힘
			plus[i].a = 0;
			plus[i].b = infobc[i].p;
		}
		else if (infobc[i].c >= Da && infobc[i].c < Db) {//A만 잡힘
			plus[i].a = infobc[i].p;
			plus[i].b = 0;
		}
		else {//둘다 안잡힘
			plus[i].a = 0;
			plus[i].b = 0;
		}
	}
	int tempmax = 0, sb = 0;
	for (int i = 0; i < A; i++) {
		for (int j = 0; j < A; j++) {
			sb = plus[i].a + plus[j].b;
			if (A > 1 && plus[i].ai == plus[j].bi)
				sb /= 2;

			if (tempmax < sb)
				tempmax = sb;
		}
	}
	max += tempmax;
	init(0);
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &testcase);
	for (int test = 0; test < testcase; test++) {
		scanf("%d %d", &M, &A);//이동시간, 충전기의 갯수
		for (int i = 0; i < M; i++)scanf("%d", &moveA[i]);
		for (int i = 0; i < M; i++)scanf("%d", &moveB[i]);

		for (int i = 0; i < A; i++)scanf("%d %d %d %d", &infobc[i].x, &infobc[i].y, &infobc[i].c, &infobc[i].p);

		int Ax = 0, Ay = 0, Bx = 9, By = 9;
		charge(Ay, Ax, By, Bx);
		for (int i = 0; i < M; i++) {
			Ay += by[moveA[i]];
			Ax += bx[moveA[i]];
			By += by[moveB[i]];
			Bx += bx[moveB[i]];
			charge(Ay, Ax, By, Bx);
		}
		printf("#%d %d\n", test + 1, max);
		init(1);
	}
	return 0;
}