#include <stdio.h>
#define SIZE 19
int T, N, H, min = 2123456789;
int map[SIZE][SIZE], copy_map[SIZE][SIZE], check[SIZE], by[4] = { -1,0,1,0 }, bx[4] = { 0,1,0,-1 };
typedef struct { int y; int x; int v; }HOUSE;
HOUSE house[SIZE];
void copy() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			copy_map[i][j] = map[i][j];
		}
	}
}
void connect(int n, int y, int x, int d) {
	int s = 0;
	if (copy_map[y + by[d - 1]][x + bx[d - 1]] == 9) {//내 바로옆에 집 있음
		check[n] = 0;
		return;
	}
	if (y + 1 == N + 1 || y - 1 == 0 || x + 1 == N + 1 || x - 1 == 0) {
		check[n] = 0;
		return;
	}
	if (d == 1) {
		for (int i = y - 1; 0 < i; i--) {
			if (copy_map[i][x] == 0) {
				copy_map[i][x] = 1;
				s++;
			}
			else if (copy_map[i][x] == 1 || copy_map[i][x] == 9) return;
		}
	}
	else if (d == 2) {
		for (int j = x + 1; j <= N; j++) {
			if (map[y][j] == 0) {
				copy_map[y][j] = 1;
				s++;
			}
			else if (copy_map[y][j] == 1 || copy_map[y][j] == 9) return;
		}
	}
	else if (d == 3) {
		for (int i = y + 1; i <= N; i++) {
			if (copy_map[i][x] == 0) {
				copy_map[i][x] = 1;
				s++;
			}
			else if (copy_map[i][x] == 1 || copy_map[i][x] == 9) return;
		}
	}
	else {
		for (int j = x - 1; 0 < j; j--) {
			if (map[y][j] == 0) {
				copy_map[y][j] = 1;
				s++;
			}
			else if (copy_map[y][j] == 1 || copy_map[y][j] == 9) return;
		}
	}
	check[n] = s;
}
void init() {
	for (int i = 0; i < H; i++)check[i] = -1;
}
void map_init() {
	min = 2123456789;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			map[i][j] = 0;
		}
	}
}
void dfs(int d) {
	if (d == H) {
		//for (int i = 0; i < H; i++) {
		//	printf("%d ", house[i].v);
		//}
		//printf("\n");
		copy();
		init();
		for (int i = 0; i < H; i++)
			connect(i, house[i].y, house[i].x, house[i].v);
		int t = 0;
		for (int i = 0; i < H; i++) {
			if (check[i] == -1) {
				init();
				return;
			}
			else t += check[i];
		}


		//for (int i = 0; i < H; i++) {
		//	printf("%d ", house[i].v);
		//}printf("\n");
		//for (int i = 0; i < H; i++) {
		//	printf("%d ", check[i]);
		//}printf("\n");


		if (min > t)min = t;
		return;
	}
	for (int i = 1; i <= 4; i++) {
		house[d].v = i;
		dfs(d + 1);
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d\n%d", &N, &H);
		int x, y;
		for (int i = 0; i, i < H; i++) {
			scanf("%d %d", &x, &y);
			house[i].x = x + 1;
			house[i].y = y + 1;
			map[y + 1][x + 1] = 9;//집
		}
		dfs(0);
		if (min == 2123456789)
			printf("#TestCase%d\n%d\n", test + 1, -1);
		else
			printf("#TestCase%d\n%d\n", test + 1, min);
		map_init();
	}
	return 0;
}