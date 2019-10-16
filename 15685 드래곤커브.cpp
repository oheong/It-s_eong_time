#include <stdio.h>
int N;
int map[101][101], dragon[20][1024], by[4] = { 0,-1,0,1 }, bx[4] = { 1,0,-1,0 };
typedef struct { int y; int x; int d; int g; }DRAGON;
DRAGON D[20];
int zegop(int n) {
	int num = 1;
	for (int i = 0; i < n; i++)num *= 2;
	return num;
}
int return_dir(int dir) { return (dir + 1) % 4; }
void get_dir(int now) {
	dragon[now][0] = D[now].d;//0세대
	for (int n = 1; n <= D[now].g; n++) {//세대만큼
		int num = zegop(n);
		for (int i = num / 2; i < num; i++)
			dragon[now][i] = return_dir(dragon[now][num - 1 - i]);
	}
}
int return_ans() {
	int sum = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] == 1 && map[i + 1][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j + 1] == 1)sum++;
		}
	}
	return sum;
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d %d %d %d", &D[i].x, &D[i].y, &D[i].d, &D[i].g);//방향, 세대
	for (int i = 0; i < N; i++) get_dir(i);
	for (int i = 0; i < N; i++) {
		int y = D[i].y;
		int x = D[i].x;
		map[y][x] = 1;
		for (int j = 0; j < zegop(D[i].g); j++) {
			y += by[dragon[i][j]];
			x += bx[dragon[i][j]];
			map[y][x] = 1;
		}
	}
	printf("%d\n", return_ans());
	return 0;
}