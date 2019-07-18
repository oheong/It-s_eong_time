//시뮬레이션
#include <stdio.h>
#define SIZE 1000
int T, N, M, K, count;//테케, map크기, 격리시간, 미생물 군집
int map[SIZE][SIZE], by[5] = { 0,-1,1,0,0 }, bx[5] = { 0,0,0,-1,1 };
typedef struct { int y; int x; int size; int go; }BUG;
BUG b[1000];
BUG t[4];
int isWall(int y, int x) {
	if (y == 0 || y == N - 1 || x == 0 || x == N - 1) return 1;//ㅇㅇ 벽임
	else return 0;
}
int change(int go) {
	if (go == 1) return 2;
	else if (go == 2) return 1;
	else if (go == 3) return 4;
	else if (go == 4) return 3;
}
void push(int i, int y, int x, int size, int go) {
	b[i].y = y;
	b[i].x = x;
	b[i].size = size;
	b[i].go = go;
}
void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = 0;
		}
	}
}
void del(int i) {
	b[i].y = 0;
	b[i].x = 0;
	b[i].size = 0;
	b[i].go = 0;
}
void king(int s) {
	int max = t[0].size;
	int max_i = 0;
	int sum = t[0].size;
	for (int i = 1; i < count; i++) {
		sum += t[i].size;
		if (max < t[i].size) {
			max_i = i;
		}
	}
	push(s, t[0].y, t[0].x, sum, t[max_i].go);
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d %d %d", &N, &M, &K);
		for (int i = 0; i < K; i++) {
			scanf("%d %d %d %d", &b[i].y, &b[i].x, &b[i].size, &b[i].go);
			map[b[i].y][b[i].x]++;
		}
		init();
		while (0 < M) {
			for (int i = 0; i < K; i++) {//일단 먼저 다 넣고
				int ny = b[i].y + by[b[i].go];
				int nx = b[i].x + bx[b[i].go];
				map[ny][nx]++;
				push(i, ny, nx, b[i].size, b[i].go);
			}

			for (int i = 0; i < K; i++) {//겹치는것들이 있는지 없는지?
				int y = b[i].y;
				int x = b[i].x;
				if (y == 0 && x == 0) continue;
				int size = b[i].size;
				int go = b[i].go;

				if (map[y][x] <2) {
					if (isWall(y, x) == 1) {//다음에 약물벽임
						push(i, y, x, size / 2, change(go));
					}
				}
				else {//두개이상 모임
					count = 0;
					t[count].y = y;
					t[count].x = x;
					t[count].size = size;
					t[count++].go = go;
					for (int s = i + 1; s < K; s++) {
						if (b[s].y == y && b[s].x == x) {
							t[count].y = b[s].y;
							t[count].x = b[s].x;
							t[count].size = b[s].size;
							t[count++].go = b[s].go;
							del(s);
						}
					}
					king(i);
				}
			}
			init();
			M--;
		}
		int ans = 0;
		for (int i = 0; i < K; i++) {
			//printf("%d\n", b[i].size);
			ans += b[i].size;
		}
		printf("#%d %d\n", test + 1, ans);
	}
	return 0;
}