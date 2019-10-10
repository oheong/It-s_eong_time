#include <stdio.h>
#define SIZE 8
int N, M, cctv_count, min = 2123456789;
int map[SIZE][SIZE], copy_map[SIZE][SIZE];
typedef struct { int y; int x; int cctv; int visited; }CCTV;
CCTV cctv[8];
void gogo_five(int y, int x) {
	for (int i = y - 1; 0 <= i; i--) {
		if (map[i][x] == 6)break;
		if (1 <= map[i][x] && map[i][x] <= 5)continue;
		map[i][x] = 9;
	}
	for (int i = y + 1; i < N; i++) {
		if (map[i][x] == 6)break;
		if (1 <= map[i][x] && map[i][x] <= 5)continue;
		map[i][x] = 9;
	}
	for (int j = x - 1; 0 <= j; j--) {
		if (map[y][j] == 6)break;
		if (1 <= map[y][j] && map[y][j] <= 5)continue;
		map[y][j] = 9;
	}
	for (int j = x + 1; j < M; j++) {
		if (map[y][j] == 6)break;
		if (1 <= map[y][j] && map[y][j] <= 5)continue;
		map[y][j] = 9;
	}
}
void copy() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			copy_map[i][j] = map[i][j];
		}
	}
}
int counting() {
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (copy_map[i][j] == 0)count++;
		}
	}
	return count;
}
void gogo(int dir, int y, int x) {
	if (dir == 0) {
		for (int i = y - 1; 0 <= i; i--) {
			if (copy_map[i][x] == 6)break;
			if (1 <= copy_map[i][x] && copy_map[i][x] <= 5)continue;
			copy_map[i][x] = 9;
		}
	}
	if (dir == 2) {
		for (int i = y + 1; i < N; i++) {
			if (copy_map[i][x] == 6)break;
			if (1 <= copy_map[i][x] && copy_map[i][x] <= 5)continue;
			copy_map[i][x] = 9;
		}
	}
	if (dir == 3) {
		for (int j = x - 1; 0 <= j; j--) {
			if (copy_map[y][j] == 6)break;
			if (1 <= copy_map[y][j] && copy_map[y][j] <= 5)continue;
			copy_map[y][j] = 9;
		}
	}
	if (dir == 1) {
		for (int j = x + 1; j < M; j++) {
			if (copy_map[y][j] == 6)break;
			if (1 <= copy_map[y][j] && copy_map[y][j] <= 5)continue;
			copy_map[y][j] = 9;
		}
	}
}
void look(int y, int x, int cctv, int dir) {
	if (cctv == 1) gogo(dir, y, x);
	else if (cctv == 2) {
		if (dir % 2 == 0) {
			gogo(0, y, x);
			gogo(2, y, x);
		}
		else {
			gogo(1, y, x);
			gogo(3, y, x);
		}
	}
	else if (cctv == 3) {
		if (dir == 0) {
			gogo(0, y, x);
			gogo(1, y, x);
		}
		else if (dir == 1) {
			gogo(1, y, x);
			gogo(2, y, x);
		}
		else if (dir == 2) {
			gogo(2, y, x);
			gogo(3, y, x);
		}
		else if (dir == 3) {
			gogo(3, y, x);
			gogo(0, y, x);
		}
	}
	else if (cctv == 4) {
		if (dir == 0) {
			gogo(0, y, x);
			gogo(1, y, x);
			gogo(3, y, x);
		}
		else if (dir == 1) {
			gogo(0, y, x);
			gogo(1, y, x);
			gogo(2, y, x);
		}
		else if (dir == 2) {
			gogo(1, y, x);
			gogo(2, y, x);
			gogo(3, y, x);
		}
		else if (dir == 3) {
			gogo(2, y, x);
			gogo(3, y, x);
			gogo(0, y, x);
		}
	}
}
void dfs(int d) {
	if (d == cctv_count) {
		copy();
		for (int i = 0; i < cctv_count; i++) {
			look(cctv[i].y, cctv[i].x, cctv[i].cctv, cctv[i].visited);
		}
		int temp = counting();
		if (min > temp)min = temp;
		return;
	}
	for (int i = 0; i < 4; i++) {
		cctv[d].visited = i;
		dfs(d + 1);
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (1 <= map[i][j] && map[i][j] <= 4) {
				cctv[cctv_count].y = i;
				cctv[cctv_count].x = j;
				cctv[cctv_count++].cctv = map[i][j];
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 5) {
				gogo_five(i, j);
			}
		}
	}
	dfs(0);
	printf("%d\n", min);
	return 0;
}