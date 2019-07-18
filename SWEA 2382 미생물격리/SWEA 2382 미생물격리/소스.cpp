#include <stdio.h>
#define SIZE 100
int map[SIZE][SIZE], by[5] = { 0, -1,1,0,0 }, bx[5] = { 0,0,0,-1,1 };
int T, N, M, K;
typedef struct { int y; int x; int size; int dir; }BUG;
BUG bug[SIZE * SIZE];
void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = 0;
		}
	}
}
void resetBug(int m) {
	bug[m].y = -1;
	bug[m].x = -1;
	bug[m].size = 0;
	bug[m].dir = 0;
}
void sumBug(int y, int x) {
	int max = 0, D = 0, sum = 0;
	for (int i = 0; i < K; i++) {
		if (bug[i].y == -1 && bug[i].x == -1) continue;
		else if (bug[i].y == y && bug[i].x == x) {
			sum += bug[i].size;
			if (max < bug[i].size) {
				max = bug[i].size;
				D = bug[i].dir;
			}
		}
	}
	for (int i = 0; i < K; i++) {
		if (bug[i].y == y && bug[i].x == x && bug[i].size != max) {
			resetBug(i);
		}
		else if (bug[i].y == y && bug[i].x == x && bug[i].size == max) {
			bug[i].size = sum;
		}
	}
}
void dieBug(int y, int x) {
	for (int i = 0; i < K; i++) {
		if (bug[i].y == y && bug[i].x == x) {
			bug[i].size /= 2;
			int dir = bug[i].dir;
			if (dir == 1)bug[i].dir = 2;
			else if (dir == 2)bug[i].dir = 1;
			else if (dir == 3)bug[i].dir = 4;
			else if (dir == 4)bug[i].dir = 3;
			return;
		}
	}
}
void search() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j]==1&&(i == 0 || i == N - 1 || j == 0 || j == N - 1)) {//벽에 닿았으니 미생물 반띵해주기
				dieBug(i, j);
			}
			if (map[i][j] > 1) {
				sumBug(i, j);
			}
		}
	}
}
void moveBug() {
	for (int k = 0; k < K; k++) {
		int y = bug[k].y;
		int x = bug[k].x;
		if (y == -1 && x == -1)continue;
		bug[k].y += by[bug[k].dir];
		bug[k].x += bx[bug[k].dir];
		map[bug[k].y][bug[k].x]++;
	}
}
int counting() {
	int ans = 0;
	for (int i = 0; i < K; i++) {
		if (bug[i].y != -1 && bug[i].x != -1)
			ans += bug[i].size;
	}
	return ans;
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d %d %d", &N, &M, &K);//N*N M시간 K마리
		for (int i = 0; i < K; i++) {
			scanf("%d %d %d %d", &bug[i].y, &bug[i].x, &bug[i].size, &bug[i].dir);
		}
		int time = 0;
		while (time < M) {
			moveBug();
			search();
			init();
			time++;
		}
		printf("#%d %d\n", test + 1, counting());
	}
	return 0;
}