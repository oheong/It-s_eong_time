#include <stdio.h>
#define SIZE 102
int N, K, L, info_count, f, r, ans;
int map[SIZE][SIZE], by[4] = { -1,0,1,0 }, bx[4] = { 0,1,0,-1 };
typedef struct { int time; char dir; }DIR_INFO;
DIR_INFO info[100];
typedef struct { int y; int x; int dir; int time; }SNAKE;
SNAKE snake[SIZE*SIZE];
void enQ(int y, int x, int dir, int time) {
	r++;
	map[y][x] = 1;
	snake[r].y = y;
	snake[r].x = x;
	snake[r].dir = dir;
	snake[r].time = time;
}
void deQ() {
	f++;
	map[snake[f].y][snake[f].x] = 0;
}
SNAKE peek() { return snake[r]; }
int make_dir(char next_dir, int dir) {
	if (next_dir == 'D') {//¿À¸¥ÂÊ
		if (dir == 0) return 1;
		else if (dir == 1) return 2;
		else if (dir == 2) return 3;
		else return 0;
	}
	else {//¿ÞÂÊ
		if (dir == 0) return 3;
		else if (dir == 1) return 0;
		else if (dir == 2) return 1;
		else return 2;
	}
}
int is_end(int y, int x) {
	if (y == 0 || y == N + 1 || x == 0 || x == N + 1)return -1;
	else if (map[y][x] == 1)return -1;
	else return 1;
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &N);
	scanf("%d", &K);
	int y, x;
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &y, &x);
		map[y][x] = 2;//»ç°ú ¸ÔÀ½
	}
	scanf("%d", &L);
	for (int i = 0; i < L; i++) scanf("%d %c", &info[i].time, &info[i].dir);
	f = r = -1;
	enQ(1, 1, 1, 0);
	info_count = 0;
	while (1) {
		int ty = peek().y;
		int tx = peek().x;
		int dir = peek().dir;
		int time = peek().time;
		if (info[info_count].time == time) {
			dir = make_dir(info[info_count].dir, dir);
			int ny = ty + by[dir], nx = tx + bx[dir];
			if (is_end(ny, nx) == 1) {
				if (map[ny][nx] != 2) deQ();
				enQ(ny, nx, dir, time + 1);
				info_count++;
			}
			else {
				ans = time + 1;
				break;
			}
		}
		else {
			int ny = ty + by[dir], nx = tx + bx[dir];
			if (is_end(ny, nx) == 1) {
				if (map[ny][nx] != 2) deQ();
				enQ(ny, nx, dir, time + 1);
			}
			else {
				ans = time + 1;
				break;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}