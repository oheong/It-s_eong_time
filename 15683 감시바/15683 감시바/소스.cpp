#include <stdio.h>
int N, M, count, cnt, min;
int map[8][8], copymap[8][8], visited[8];
typedef struct { int y; int x; int cctv; }CCTV;
CCTV cctv[8];
void sort() {
	int temp, ty, tx;
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count - 1 - i; j++) {
			if (cctv[j].cctv < cctv[j + 1].cctv) {
				temp = cctv[j].cctv;
				ty = cctv[j].y;
				tx = cctv[j].x;
				cctv[j].cctv = cctv[j + 1].cctv;
				cctv[j].y = cctv[j + 1].y;
				cctv[j].x = cctv[j + 1].x;
				cctv[j + 1].cctv = temp;
				cctv[j + 1].y = ty;
				cctv[j + 1].x = tx;
			}
		}
	}
}
int counting() {
	int c = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (copymap[i][j] == 0) c++;
		}
	}
	return c;
}
void copy() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			copymap[i][j] = map[i][j];
		}
	}
}
void lookNo5(int y, int x) {
	for (int i = y; i < N; i++) {//아래 
		if (map[i][x] == 6)break;
		else if (map[i][x] == 0) map[i][x] = 9;
	}
	for (int i = y; 0 <= i; i--) {//위
		if (map[i][x] == 6)break;
		else if (map[i][x] == 0) map[i][x] = 9;
	}
	for (int i = x; i < M; i++) {//오른쪽
		if (map[y][i] == 6)break;
		else if (map[y][i] == 0) map[y][i] = 9;
	}
	for (int i = x; 0 <= i; i--) {//왼쪽
		if (map[y][i] == 6)break;
		else if (map[y][i] == 0) map[y][i] = 9;
	}
}
void look(int y, int x, int n) {
	if (n == 1) {//위
		for (int i = y; 0 <= i; i--) {//위
			if (copymap[i][x] == 6)break;
			else if (copymap[i][x] == 0) copymap[i][x] = 9;
		}
	}
	else if (n == 2) {//오
		for (int i = x; i < M; i++) {//오른쪽
			if (copymap[y][i] == 6)break;
			else if (copymap[y][i] == 0) copymap[y][i] = 9;
		}
	}
	else if (n == 3) {//아
		for (int i = y; i < N; i++) {//아래
			if (copymap[i][x] == 6)break;
			else if (copymap[i][x] == 0) copymap[i][x] = 9;
		}
	}
	else if (n == 4) {//왼
		for (int i = x; 0 <= i; i--) {//왼쪽
			if (copymap[y][i] == 6)break;
			else if (copymap[y][i] == 0) copymap[y][i] = 9;
		}
	}
}
void dfs(int d) {
	if (d == count - cnt) {
		copy();
		for (int i = cnt; i < count; i++) {
			if (cctv[i].cctv == 1) {
				look(cctv[i].y, cctv[i].x, visited[i]);
			}
			else if (cctv[i].cctv == 2) {
				if (visited[i] % 2 == 0) {
					look(cctv[i].y, cctv[i].x, 1);
					look(cctv[i].y, cctv[i].x, 3);
				}
				else {
					look(cctv[i].y, cctv[i].x, 2);
					look(cctv[i].y, cctv[i].x, 4);
				}
			}
			else if (cctv[i].cctv == 3) {
				if (visited[i] == 1) {
					look(cctv[i].y, cctv[i].x, 1);
					look(cctv[i].y, cctv[i].x, 2);
				}
				else if (visited[i] == 2) {
					look(cctv[i].y, cctv[i].x, 2);
					look(cctv[i].y, cctv[i].x, 3);
				}
				else if (visited[i] == 3) {
					look(cctv[i].y, cctv[i].x, 3);
					look(cctv[i].y, cctv[i].x, 4);
				}
				else if (visited[i] == 4) {
					look(cctv[i].y, cctv[i].x, 4);
					look(cctv[i].y, cctv[i].x, 1);
				}
			}
			else if (cctv[i].cctv == 4) {
				if (visited[i] == 1) {
					look(cctv[i].y, cctv[i].x, 1);
					look(cctv[i].y, cctv[i].x, 2);
					look(cctv[i].y, cctv[i].x, 4);
				}
				else if (visited[i] == 2) {
					look(cctv[i].y, cctv[i].x, 1);
					look(cctv[i].y, cctv[i].x, 2);
					look(cctv[i].y, cctv[i].x, 3);
				}
				else if (visited[i] == 3) {
					look(cctv[i].y, cctv[i].x, 2);
					look(cctv[i].y, cctv[i].x, 3);
					look(cctv[i].y, cctv[i].x, 4);
				}
				else if (visited[i] == 4) {
					look(cctv[i].y, cctv[i].x, 4);
					look(cctv[i].y, cctv[i].x, 1);
					look(cctv[i].y, cctv[i].x, 3);
				}
			}
		}
		int temp = counting();
		if (min > temp) min = temp;
		return;
	}
	for (int i = 1; i < 5; i++) {
		visited[d + cnt] = i;
		dfs(d + 1);
	}
}
int main() {
	//freopen("Text.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] != 0 && map[i][j] != 6) {
				cctv[count].cctv = map[i][j];
				cctv[count].y = i;
				cctv[count++].x = j;
			}
			if (map[i][j] == 5) cnt++;
		}
	}
	min = 2123456789;
	sort();
	for (int i = 0; i < cnt; i++) lookNo5(cctv[i].y, cctv[i].x);
	dfs(0);
	printf("%d\n", min);
	return 0;
}