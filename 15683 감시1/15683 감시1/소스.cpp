#include <stdio.h>
#define SIZE 8
int N, M, c, c5, min = 2123456789;
int map[SIZE][SIZE], copy_map[SIZE][SIZE];
typedef struct { int y; int x; int w; int v; }CCTV;
CCTV cctv[SIZE], cctv5[SIZE];
void copy() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			copy_map[i][j] = map[i][j];
		}
	}
}
int count() {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (copy_map[i][j] == 0)
				sum++;
		}
	}
	return sum;
}
void start_cctv(int y, int x, int c, int arr[SIZE][SIZE]) {
	if (c == 1) {
		for (int i = y - 1; 0 <= i; i--) {
			if (arr[i][x] == 0)arr[i][x] = 8;
			else if (arr[i][x] == 6) return;
		}
	}
	else if (c == 2) {
		for (int j = x + 1; j < M; j++) {
			if (arr[y][j] == 0)arr[y][j] = 8;
			else if (arr[y][j] == 6) return;
		}
	}
	else if (c == 3) {
		for (int i = y + 1; i < N; i++) {
			if (arr[i][x] == 0)arr[i][x] = 8;
			else if (arr[i][x] == 6) return;
		}
	}
	else if (c == 4) {
		for (int j = x - 1; 0 <= j; j--) {
			if (arr[y][j] == 0)arr[y][j] = 8;
			else if (arr[y][j] == 6) return;
		}
	}
}
void choice_cctv(int y, int x, int w, int v) { // w == cctv Á¾·ù
	if (w == 1) {
		start_cctv(y, x, v, copy_map);
	}
	else if (w == 2) {
		if (v % 2 == 0) {
			start_cctv(y, x, 1, copy_map);
			start_cctv(y, x, 3, copy_map);
		}
		else {
			start_cctv(y, x, 2, copy_map);
			start_cctv(y, x, 4, copy_map);
		}
	}
	else if (w == 3) {
		if (v == 1) {
			start_cctv(y, x, 1, copy_map);
			start_cctv(y, x, 2, copy_map);
		}
		else if (v == 2) {
			start_cctv(y, x, 2, copy_map);
			start_cctv(y, x, 3, copy_map);
		}
		else if (v == 3) {
			start_cctv(y, x, 3, copy_map);
			start_cctv(y, x, 4, copy_map);
		}
		else {
			start_cctv(y, x, 4, copy_map);
			start_cctv(y, x, 1, copy_map);
		}
	}
	else if (w == 4) {
		if (v == 1) {
			start_cctv(y, x, 2, copy_map);
			start_cctv(y, x, 3, copy_map);
			start_cctv(y, x, 4, copy_map);
		}
		else if (v == 2) {
			start_cctv(y, x, 1, copy_map);
			start_cctv(y, x, 3, copy_map);
			start_cctv(y, x, 4, copy_map);
		}
		else if (v == 3) {
			start_cctv(y, x, 1, copy_map);
			start_cctv(y, x, 2, copy_map);
			start_cctv(y, x, 4, copy_map);
		}
		else {
			start_cctv(y, x, 1, copy_map);
			start_cctv(y, x, 2, copy_map);
			start_cctv(y, x, 3, copy_map);
		}
	}
}
void dfs(int d) {
	if (d == c) {
		copy();

		for (int i = 0; i < c; i++)
			choice_cctv(cctv[i].y, cctv[i].x, cctv[i].w, cctv[i].v);

		int t = count();
		if (min > t)min = t;
		return;
	}
	for (int i = 1; i <= 4; i++) {
		cctv[d].v = i;
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
				cctv[c].y = i;
				cctv[c].x = j;
				cctv[c].w = map[i][j];
				c++;
			}
			else if (map[i][j] == 5) {
				cctv5[c5].y = i;
				cctv5[c5].x = j;
				cctv5[c5].w = map[i][j];
				c5++;
			}
		}
	}

	for (int i = 0; i < c5; i++) {
		start_cctv(cctv5[i].y, cctv5[i].x, 1, map);
		start_cctv(cctv5[i].y, cctv5[i].x, 2, map);
		start_cctv(cctv5[i].y, cctv5[i].x, 3, map);
		start_cctv(cctv5[i].y, cctv5[i].x, 4, map);
	}
	dfs(0);
	printf("%d\n", min);
	return 0;
}