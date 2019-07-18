#include <stdio.h>
#define SIZE 50
int C, R, T, f = -1, r = -1, uy, ux, dy, dx, ans;
int map[SIZE][SIZE], tempmap[SIZE][SIZE], by[4] = { 0,0,1,-1 }, bx[4] = { 1,-1,0,0 };
//tempmap은 계산해 줘야 할 것들임
typedef struct { int y; int x; }Queue;
Queue q[SIZE*SIZE];
void enQ(int y, int x) {
	r++;
	q[r].y = y;
	q[r].x = x;
}
void deQ() { f++; }
Queue peek() { return q[f + 1]; }
void init() {
	f = r = -1;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			map[i][j] += tempmap[i][j];
			tempmap[i][j] = 0;
		}
	}
}
void spread(int y, int x) {//작동 잘~~함
	enQ(y, x);
	int ty = peek().y;
	int tx = peek().x;
	int temp = map[ty][tx] / 5;
	int count = 0;
	deQ();
	for (int i = 0; i < 4; i++) {
		int ny = ty + by[i];
		int nx = tx + bx[i];
		if (0 <= ny && ny < R && 0 <= nx && nx < C&& map[ny][nx] != -1) {
			count++;
			tempmap[ny][nx] += temp;
		}
	}
	tempmap[ty][tx] += (-1 * temp * count);
}
void turnOn(int y, int x, int n) {
	int temp = 0;
	if (n == 0) {
		//윗 청정기 가동
		//반시계방향
		for (int i = uy; 0 < i; i--) {
			if (map[i][ux] == -1) temp = -1;
			else temp = map[i - 1][ux];
			map[i][ux] = temp;
		}
		for (int j = 0; j < C - 1; j++) {
			temp = map[0][j + 1];
			map[0][j] = temp;
		}
		for (int i = 0; i < uy; i++) {
			temp = map[i + 1][C - 1];
			map[i][C - 1] = temp;
		}
		for (int j = C - 1; 0 < j; j--) {
			if (map[uy][j - 1] == -1)temp = 0;
			else temp = map[uy][j - 1];
			map[uy][j] = temp;
		}
	}
	else {
		//아래 청정기 가동!
		//시계방향
		for (int i = dy; i < R - 1; i++) {
			if (map[i][dx] == -1)temp = -1;
			else temp = map[i + 1][dx];
			map[i][dx] = temp;
		}
		for (int j = 0; j < C - 1; j++) {
			temp = map[R - 1][j + 1];
			map[R - 1][j] = temp;
		}
		for (int i = R - 1; dy < i; i--) {
			temp = map[i - 1][C - 1];
			map[i][C - 1] = temp;
		}
		for (int j = C - 1; 0 < j; j--) {
			if (map[dy][j - 1] == -1) temp = 0;
			else temp = map[dy][j - 1];
			map[dy][j] = temp;
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d %d", &R, &C, &T);
	bool flag = false;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%d", &map[i][j]);
			if (flag == false && map[i][j] == -1) {
				uy = i; ux = j;
				dy = i + 1; dx = j;
				flag = true;
			}
		}
	}
	while (0 < T) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (map[i][j] >= 5)
					spread(i, j);
			}
		}
		init();
		//청정기 가동!
		turnOn(uy, ux, 0);
		turnOn(dy, dx, 1);
		T--;
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			ans += map[i][j];
		}
	}
	printf("%d\n", ans + 2);
	return 0;
}