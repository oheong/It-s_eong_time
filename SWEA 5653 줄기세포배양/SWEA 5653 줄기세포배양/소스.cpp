#include <stdio.h>
#define SIZE 300
int T, N, M, K, count;
int f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10;
int map[SIZE * 2][SIZE * 2], visited[SIZE * 2][SIZE * 2], bx[4] = { 1,-1,0,0 }, by[4] = { 0,0,1,-1 };
typedef struct { int y; int x; int step; }Queue;
Queue q[11][SIZE*SIZE];
void enQ(int n, int y, int x, int step) {//
	int r;
	switch (n) {
	case 1: r1++; r = r1; break;
	case 2: r2++; r = r2; break;
	case 3: r3++; r = r3; break;
	case 4: r4++; r = r4; break;
	case 5: r5++; r = r5; break;
	case 6: r6++; r = r6; break;
	case 7: r7++; r = r7; break;
	case 8: r8++; r = r8; break;
	case 9: r9++; r = r9; break;
	case 10: r10++; r = r10; break;
		//獣降せせせせせせせせせせせせせせせせせせせせせせせせせせせせせせせせせせせせせせせせせせせせせせ
	}
	q[n][r].y = y;
	q[n][r].x = x;
	q[n][r].step = step;
}
void deQ(int n) {
	int f;
	switch (n) {
	case 1: f1++; break;
	case 2: f2++; break;
	case 3: f3++; break;
	case 4: f4++; break;
	case 5: f5++; break;
	case 6: f6++; break;
	case 7: f7++; break;
	case 8: f8++; break;
	case 9: f9++; break;
	case 10: f10++; break;
	}
}
Queue peek(int n) {
	int f;
	switch (n) {
	case 1: return q[n][f1 + 1];
	case 2: return q[n][f2 + 1];
	case 3: return q[n][f3 + 1];
	case 4: return q[n][f4 + 1];
	case 5: return q[n][f5 + 1];
	case 6: return q[n][f6 + 1];
	case 7: return q[n][f7 + 1];
	case 8: return q[n][f8 + 1];
	case 9: return q[n][f9 + 1];
	case 10: return q[n][f10 + 1];
	}
}
int empty(int n) {
	switch (n) {
	case 1: if (f1 == r1)return 1; break;
	case 2: if (f2 == r2)return 1; break;
	case 3: if (f3 == r3)return 1; break;
	case 4: if (f4 == r4)return 1; break;
	case 5: if (f5 == r5)return 1; break;
	case 6: if (f6 == r6)return 1; break;
	case 7: if (f7 == r7)return 1; break;
	case 8: if (f8 == r8)return 1; break;
	case 9: if (f9 == r9)return 1; break;
	case 10:if (f10 == r10)return 1; break;
	}
	return 0;
}
void bfs() {
	int k = 1, c = 0;
	while (k <= K) {
		if (k == K) {
			//朝錘特馬奄
			count = 0;
			count += r1 - f1 + 1;
			count += r2 - f2 + 1;
			count += r3 - f3 + 1;
			count += r4 - f4 + 1;
			count += r5 - f5 + 1;
			count += r6 - f6 + 1;
			count += r7 - f7 + 1;
			count += r8 - f8 + 1;
			count += r9 - f9 + 1;
			count += r10 - f10 + 1;
			printf("%d %d %d %d %d %d %d %d %d %d \n", f1, f2, f3, f4, f5, f6, f7, f8, f9, f10);
			printf("%d %d %d %d %d %d %d %d %d %d \n", r1, r2, r3, r4, r5, r6, r7, r8, r9, r10);
			return;
		}
		for (int n = 10; 0 < n; n--) {
			if (empty(n) == 0) {
				int tstep = peek(n).step;
				//if (tstep + n * 2 == k) {
				//	deQ(n);
				//}
				 if (tstep + n == k) {
					//遁走奄
					//遁霜凶 赤澗暗 陥 遁閃醤喫 獣降,,,,,,,,,,,
					while (tstep == peek(n).step) {
						tstep = peek(n).step;
						int tx = peek(n).x;
						int ty = peek(n).y;
						deQ(n);
						for (int i = 0; i < 4; i++) {
							int ny = ty + by[i];
							int nx = tx + bx[i];
							if (visited[ny][nx] == 0) {
								enQ(n, ny, nx, k + 1);
								visited[ny][nx] = 1;
							}
						}
					}
				}
			}
		}
		k++;
	}
}
void init() {
	for (int i = 0; i < SIZE * 2; i++) {
		for (int j = 0; j < SIZE * 2; j++)
			visited[i][j] = 0;
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d %d %d", &N, &M, &K);
		f1 = f2 = f3 = f4 = f5 = f6 = f7 = f8 = f9 = f10 = r1 = r2 = r3 = r4 = r5 = r6 = r7 = r8 = r9 = r10 = -1;
		int temp;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%d", &temp);
				map[i + SIZE][j + SIZE] = temp;
				if (temp != 0) {
					enQ(temp, i + SIZE, j + SIZE, 0);//段奄雌殿
					visited[i + SIZE][j + SIZE] = 1;
				}
			}
		}
		bfs();
		printf("#%d %d\n", test + 1, count);
		init();
		count = 0;
	}
	return 0;
}