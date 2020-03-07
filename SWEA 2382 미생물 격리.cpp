#include <stdio.h>
#define SIZE 100
int T, N, M, K;
int map[SIZE][SIZE];
int by[5] = { 0,-1,1,0,0 }, bx[5] = { 0,0,0,-1,1 };
typedef struct { int y; int x; int size; int dir; }VIRUS;
VIRUS virus[1000];
int is_drug(int y, int x) {
	if (y == 0 || y == N - 1 || x == 0 || x == N - 1)return 1;
	else return 0;
}
int change_dir(int dir) {
	if (dir == 1)return 2;
	if (dir == 2)return 1;
	if (dir == 3)return 4;
	if (dir == 4)return 3;
}
void change_bug(int y, int x) {
	for (int i = 0; i < K; i++) {
		if (virus[i].y == y && virus[i].x == x) {
			virus[i].dir = change_dir(virus[i].dir);
			virus[i].size /= 2;
			return;
		}
	}
}
void sum_bug(int y, int x) {
	int max_i = 1, max_size = 0, max_dir = 0, total_size = 0;
	for (int i = 0; i < K; i++) {
		if (virus[i].y == y && virus[i].x == x) {
			if (max_size < virus[i].size) {
				max_size = virus[i].size;
				max_dir = virus[i].dir;
				max_i = i;
			}
			virus[i].y = -1;
			virus[i].x = -1;
			total_size += virus[i].size;
		}
	}
	virus[max_i].y = y;
	virus[max_i].x = x;
	virus[max_i].dir = max_dir;
	virus[max_i].size = total_size;
}
void search_bug() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1 && is_drug(i, j) == 1) {
				change_bug(i, j);
			}
			if (1 < map[i][j]) {
				sum_bug(i, j);
			}
			map[i][j] = 0;
		}
	}
}
void move_bug() {
	for (int i = 0; i < K; i++) {
		if (virus[i].y == -1 && virus[i].x == -1)continue;
		virus[i].y += by[virus[i].dir];
		virus[i].x += bx[virus[i].dir];
		map[virus[i].y][virus[i].x]++;
	}
}
int get_sum() {
	int sum = 0;
	for (int i = 0; i < K; i++) {
		if (virus[i].y == -1 && virus[i].x == -1) continue;
		sum += virus[i].size;
	}
	return sum;
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d %d %d", &N, &M, &K); // 셀 갯수, 격리시간, 미생물 군집 수
		for (int i = 0; i < K; i++) {
			scanf("%d %d %d %d", &virus[i].y, &virus[i].x, &virus[i].size, &virus[i].dir);
		}
		int time = 0;
		while (time < M) {
			move_bug();
			search_bug();
			time++;
		}
		printf("#%d %d\n", test + 1, get_sum());
	}
	return 0;
}