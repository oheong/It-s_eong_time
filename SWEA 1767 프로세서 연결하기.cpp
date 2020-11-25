#include <stdio.h>
#define SIZE 14
typedef struct {
	int y;
	int x;
	int count;
}PROCESSOR;
PROCESSOR processor[SIZE];
int T, N, p_count, max, min = 2123456789;
int map[SIZE][SIZE], by[5] = { 0,-1,0,1,0 }, bx[5] = { 0,0,1,0,-1 };
int is_ok(int temp_map[SIZE][SIZE], int y, int x, int dir) {
	int count = 0;
	for (int i = 1; i <= N; i++) {
		y += by[dir];
		x += bx[dir];
		count++;
		if (temp_map[y][x] == 1)
			return -1;
		if (temp_map[y][x] == 1 || temp_map[y][x] == 2)
			return 0;
		if (y == 0 || y == N + 1 || x == 0 || x == N + 1)
			return count - 1;
	}
}
void change(int temp_map[SIZE][SIZE], int y, int x, int dir, int count, int num) {
	for (int i = 0; i < count; i++) {
		y += by[dir];
		x += bx[dir];
		temp_map[y][x] = num;
	}
}
int counting(int temp_map[SIZE][SIZE]) {
	int count = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (temp_map[i][j] == 2)
				count++;
		}
	}
	return count;
}
void copy(int temp_map[SIZE][SIZE], int map[SIZE][SIZE]) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			temp_map[i][j] = map[i][j];
		}
	}
}
void init() {
	min = 2123456789;
	max = 0;
	p_count = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			map[i][j] = 0;
		}
	}
}
void dfs(int map[SIZE][SIZE], int d, int processor_cnt) {
	if (p_count - d + processor_cnt < max) return;
	if (d == p_count) {
		int temp = counting(map);
		if (temp < processor[processor_cnt - 1].count) {
			processor[processor_cnt - 1].count = temp;
			if (max < processor_cnt)
				max = processor_cnt;
		}
		return;
	}
	int temp_map[SIZE][SIZE] = { 0, };
	copy(temp_map, map);
	for (int i = 0; i < 5; i++) {
		// 전선 그어주기
		if (i == 0)
			dfs(temp_map, d + 1, processor_cnt);
		int ok_num = is_ok(temp_map, processor[d].y, processor[d].x, i);
		if (ok_num == -1) // 주위가 프로세서인것
			continue;
		else if (ok_num == 0) // 주위가 전선인것
			dfs(temp_map, d + 1, processor_cnt);
		//continue;
		else {
			change(temp_map, processor[d].y, processor[d].x, i, ok_num, 2);
			dfs(temp_map, d + 1, processor_cnt + 1);
			change(temp_map, processor[d].y, processor[d].x, i, ok_num, 0);
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				scanf("%d", &map[i][j]);
				if (map[i][j] == 0) continue;
				if (map[i][j] == 1 && (i == 1 || i == N || j == 1 || j == N)) // 이미 벽에 붙어있는 프로세서이기때문에 체크를 해줄 필요가 없음
					continue;
				else {
					processor[p_count].count = 2123456789;
					processor[p_count].y = i;
					processor[p_count++].x = j;
				}
			}
		}
		dfs(map, 0, 0);

		for (int i = p_count - 1; 0 <= i; i--) {
			if (processor[i].count != 2123456789) {
				printf("#%d %d\n", test + 1, processor[i].count);
				break;
			}
		}
		init();
	}
	return 0;
}
// 49/50 와 한개머야!!!!!!!!!!!!

/*
1
5
1 1 1 1 1
1 1 0 0 1
0 0 0 1 1
0 0 0 1 1
1 0 1 1 1
ans : 6
*/

// 개빡쳨ㅋㅋㅋㅋㅋㅋㅋ큐ㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠ