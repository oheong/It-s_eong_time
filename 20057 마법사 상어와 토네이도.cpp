#include <stdio.h>
#define SIZE 505
int N, temp, ans;
int map[SIZE][SIZE], temp_map[5][5];
int spread_sheet[4][25] = {
	{
		0,0,5,0,0,
		0,10,-1,10,0,
		2,7,0,7,2,
		0,1,0,1,0,
		0,0,0,0,0
	},
	{
		0,0,2,0,0,
		0,1,7,10,0,
		0,0,0,-1,5,
		0,1,7,10,0,
		0,0,2,0,0
	},
	{
		0,0,0,0,0,
		0,1,0,1,0,
		2,7,0,7,2,
		0,10,-1,10,0,
		0,0,5,0,0
	},
	{
		0,0,2,0,0,
		0,10,7,1,0,
		5,-1,0,0,0,
		0,10,7,1,0,
		0,0,2,0,0
	}
};
int is_ok(int y, int x) {
	if (2 <= y && y < N + 2 && 2 <= x && x < N + 2) return 1;
	return 0;
}
void spread(int dir, int y, int x) { // (y,x)가 기준 값
	int center = map[y][x];
	map[y][x] = 0;
	int temp_y, temp_x = 0;
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (spread_sheet[dir][i * 5 + j] == -1) {
				temp_y = i;
				temp_x = j;
				continue;
			}
			temp_map[i][j] = center * spread_sheet[dir][i * 5 + j] * 0.01;
			sum += temp_map[i][j];
		}
	}
	temp_map[temp_y][temp_x] = center - sum;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (temp_map[i][j] == 0) continue;
			if (is_ok(y - 2 + i, x - 2 + j) == 1)  // 범위 안이다
				map[y - 2 + i][x - 2 + j] += temp_map[i][j];
			else
				ans += temp_map[i][j];
			temp_map[i][j] = 0;
		}
	}

}
void go_tornado(int start_y, int start_x) {
	int dir = -1;
	for (int i = 1; i <= N; i++) {
		for (int x = 0; x < i; x++) {
			start_x += dir;
			if (dir == -1)
				spread(3, start_y, start_x);
			else
				spread(1, start_y, start_x);
		}
		if (i == N) break;
		dir *= -1;
		for (int y = 0; y < i; y++) {
			start_y += dir;
			if (dir == -1)
				spread(0, start_y, start_x);
			else
				spread(2, start_y, start_x);
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 2; i < N + 2; i++) {
		for (int j = 2; j < N + 2; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	go_tornado((N + 4) / 2, (N + 4) / 2);
	printf("%d\n", ans);
	return 0;
}