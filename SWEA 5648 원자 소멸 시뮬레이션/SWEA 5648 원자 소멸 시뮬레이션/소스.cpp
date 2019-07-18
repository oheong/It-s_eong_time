#include <stdio.h>
#define SIZE 4001
//0.5초 마다 움직이는거 확인!!!!
int T, N, Y, X, W, E, f = -1, r = -1, Energy = 0, temp_step, t = -1;
int by[4] = { -1,1,0,0 }, bx[4] = { 0,0,1,-1 };
typedef struct { int y; int x; int w; int e; int step; }Queue;
typedef struct { int e; bool yn; }MAP;
typedef struct { int y; int x; }STACK;
STACK st[SIZE*SIZE];
MAP map[SIZE][SIZE][4];
Queue q[SIZE*SIZE];
void enQ(int y, int x, int w, int e, int step) {
	r++;
	q[r].y = y;
	q[r].x = x;
	q[r].w = w;
	q[r].e = e;
	q[r].step = step;
}
void deQ() { f++; }
Queue peek() { return q[f + 1]; }
int empty() {
	if (f == r)return 1;
	else return 0;
}
int abs(int a) {
	if (a < 0)return 0;
	else return 1;
}
void init() {
	f = r - 1;
	t = -1;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			for (int cnt = 0; cnt < 4; cnt++) {
				map[i][j][cnt].e = 0;
				map[i][j][cnt].yn = false;
			}
		}
	}
}
void bfs() {
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		int tw = peek().w;
		int te = peek().e;
		int tstep = peek().step;
		if (temp_step != tstep) {
			for (int s = 0; s <= t; s++) {
				for (int cnt = 0; cnt < 4; cnt++) {
					Energy += map[st[s].y][st[s].x][cnt].e;
					map[st[s].y][st[s].x][cnt].e = 0;
					map[st[s].y][st[s].x][cnt].yn = false;
				}
			}

		}
		map[ty][tx][0].e = 0;
		map[ty][tx][0].yn = false;
		deQ();
		int ny = ty + by[tw];
		int nx = tx + bx[tw];
		if (0 <= ny && ny < SIZE && 0 <= nx && nx < SIZE) {
			temp_step = tstep;
			enQ(ny, nx, tw, te, tstep + 1);
			if (map[ny][nx][0].yn == true) {
				//0에 누가있다?
				//printf("%d %d\n", ny, nx);
				for (int cnt = 1; cnt < 4; cnt++) {
					if (map[ny][nx][cnt].yn == false) {
						map[ny][nx][cnt].yn = true;
						map[ny][nx][cnt].e = te;
						st[++t].y = ny;
						st[t].x = nx;
						break;
					}
				}
			}
			else {
				map[ny][nx][0].yn = true;
				map[ny][nx][0].e = te;
			}
		}

	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d %d %d %d", &X, &Y, &W, &E);
			int tempx, tempy;
			//if (X < SIZE / 2) {
			//	if (Y < SIZE / 2) {
			//		//3사분면
			//		enQ(SIZE / 2 - Y * 2, SIZE / 2 + X * 2, W, E, 0);
			//	}
			//	else {
			//		//2사분면
			//		enQ(SIZE / 2 - Y * 2, SIZE / 2 + X * 2, W, E, 0);
			//	}
			//}
			//else {
			//	if (Y < SIZE / 2) {
			//		//1사분면
			//		enQ(SIZE / 2 - Y * 2, SIZE / 2 + X * 2, W, E, 0);
			//	}
			//	else {
			//		//4사분면
			//		enQ(SIZE / 2 - Y * 2, SIZE / 2 + X * 2, W, E, 0);
			//	}
			//}
			if (X != 0) {
				tempx = SIZE / 2 + X * 2;
			}
			else tempx = 0;
			if (Y != 0) {
				tempy = SIZE / 2 - Y * 2;
			}
			else tempy = 0;
			enQ(tempy,tempx , W, E, 0);

		}

		Energy = 0;
		bfs();

		printf("#%d %d\n", test + 1, Energy);
		init();
	}
	return 0;
}