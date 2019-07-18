#include <stdio.h>
#define SIZE 8
int N, M, min = 2123456789, count;
int map[SIZE][SIZE];
typedef struct { int y; int x; int n; }V;
V visited[SIZE];
int counting() {
	int c = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) c++;
		}
	}
	return c;
}
void remap() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 9) map[i][j] = 0;
		}
	}
}
void cctv(int y, int x, int g) {//현 위치, 다음에 가야 할 방향
	if (g == 1) {
		for (int i = y; 0 <= i; i--) {//위
			if (map[i][x] == 6) break;
			else if (map[i][x] == 0) map[i][x] = 9;
		}
	}
	else if (g == 2) {
		for (int i = x; 0 <= i; i--) {//왼
			if (map[y][i] == 6) break;
			else if (map[y][i] == 0) map[y][i] = 9;
		}
	}
	else if (g == 3) {
		for (int i = y; i < N; i++) {//아래
			if (map[i][x] == 6) break;
			else if (map[i][x] == 0) map[i][x] = 9;
		}
	}
	else if (g == 4) {
		for (int i = x; i < M; i++) {//오른
			if (map[y][i] == 6) break;
			else if (map[y][i] == 0) map[y][i] = 9;
		}
	}
}
void dfs(int d) {
	if (d == count) {//감시할 수 있는 구역 구하기
		for (int i = 0; i < count; i++) {
			int ty = visited[i].y;
			int tx = visited[i].x;
			int Cctv = map[ty][tx];
			if (Cctv == 1) {
				cctv(ty, tx, visited[i].n);
			}
			else if (Cctv == 2) {
				if (visited[i].n % 2 == 0) {
					cctv(ty, tx, 1);//위
					cctv(ty, tx, 3);//아래
				}
				else {
					cctv(ty, tx, 4);//오
					cctv(ty, tx, 2);//왼
				}
			}
			else if (Cctv == 3 || Cctv == 4) {
				if (visited[i].n == 1) {
					cctv(ty, tx, 1);//위
					cctv(ty, tx, 4);//오
					if (Cctv == 4) cctv(ty, tx, 2);//왼
				}
				else if (visited[i].n == 2) {
					cctv(ty, tx, 4);//오
					cctv(ty, tx, 3);//아래
					if (Cctv == 4) cctv(ty, tx, 1);//위
				}
				else if (visited[i].n == 3) {
					cctv(ty, tx, 3);//아래
					cctv(ty, tx, 2);//왼
					if (Cctv == 4) cctv(ty, tx, 4);//오
				}
				else if (visited[i].n == 4) {
					cctv(ty, tx, 2);//왼
					cctv(ty, tx, 1);//위
					if (Cctv == 4) cctv(ty, tx, 3);//아래
				}
			}
			else if (Cctv == 4) {
				if (visited[i].n == 1) {
					cctv(ty, tx, 1);//위
					cctv(ty, tx, 4);//오
					cctv(ty, tx, 2);//왼
				}
				else if (visited[i].n == 2) {
					cctv(ty, tx, 4);//오
					cctv(ty, tx, 3);//아래
					cctv(ty, tx, 1);//위
				}
				else if (visited[i].n == 3) {
					cctv(ty, tx, 3);//아래
					cctv(ty, tx, 2);//왼
					cctv(ty, tx, 4);//오
				}
				else if (visited[i].n == 4) {
					cctv(ty, tx, 2);//왼
					cctv(ty, tx, 1);//위
					cctv(ty, tx, 3);//아래
				}
			}
			else if (Cctv == 5) {
				cctv(ty, tx, 1);//위
				cctv(ty, tx, 4);//오
				cctv(ty, tx, 3);//아래
				cctv(ty, tx, 2);//왼
			}
		}
		int tempmin = counting();
		if (min > tempmin) min = tempmin;
		remap();
		return;
	}
	for (int i = 1; i < 5; i++) {
		visited[d].n = i;
		dfs(d + 1);
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (1 <= map[i][j] && map[i][j] <= 5) {
				visited[count].y = i;
				visited[count].x = j;
				count++;
			}
		}
	}
	dfs(0);
	printf("%d\n", min);
	return 0;
}