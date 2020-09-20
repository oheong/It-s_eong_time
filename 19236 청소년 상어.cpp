// 백트래킹,,, ㅠ
#include <stdio.h>
int a, b, fish_count, max;
int real_map[4][4], by[8] = { -1,-1,0,1,1,1,0,-1 }, bx[8] = { 0,-1,-1,-1,0,1,1,1 };
typedef struct { int num; int y; int x; int dir; }FISH;
FISH real_fish[17];
void swap(int a, int b) {
	int tn = real_fish[a].num;
	int td = real_fish[a].dir;
	int ty = real_fish[a].y;
	int tx = real_fish[a].x;

	real_fish[a].num = real_fish[b].num;
	real_fish[a].dir = real_fish[b].dir;
	real_fish[a].y = real_fish[b].y;
	real_fish[a].x = real_fish[b].x;

	real_fish[b].num = tn;
	real_fish[b].dir = td;
	real_fish[b].y = ty;
	real_fish[b].x = tx;
}
void sort() {
	for (int i = 1; i < 17; i++) {
		for (int j = 1; j < 17 - i; j++) {
			if (real_fish[j].num > real_fish[j + 1].num) {
				swap(j, j + 1);
			}
		}
	}
}
void init(int map[4][4], FISH fish[17], int a) {
	map[fish[a].y][fish[a].x] = -1;
	fish[a].num = -1;
	fish[a].dir = -1;
	fish[a].y = -1;
	fish[a].x = -1;
}
int is_ok(int y, int x) {
	if (y < 0 || 4 <= y || x < 0 || 4 <= x) return 0;
	return 1;
}
void fish_swap(int map[4][4], FISH fish[17], int i, int ny, int nx) {
	int now_y = fish[i].y;
	int now_x = fish[i].x;

	int next_fish = map[ny][nx];
	int next_y = fish[next_fish].y;
	int next_x = fish[next_fish].x;

	fish[i].y = next_y;
	fish[i].x = next_x;
	fish[next_fish].y = now_y;
	fish[next_fish].x = now_x;
	map[fish[i].y][fish[i].x] = fish[i].num;
	map[fish[next_fish].y][fish[next_fish].x] = next_fish;
}
void moving_fish(int map[4][4], FISH fish[17]) { // 상어 : -1
	for (int i = 1; i < 17; i++) {
		if (fish[i].num == -1)continue;

		int ny = fish[i].y + by[fish[i].dir];
		int nx = fish[i].x + bx[fish[i].dir];

		bool flag = false;

		if (is_ok(ny, nx) == 0 || map[ny][nx] == -1) { // 이동 불가능
			// 이동할 수 있을 때 까지 방향 회전
			for (int j = 1; j < 8; j++) {
				int nny = fish[i].y + by[(fish[i].dir + j) % 8];
				int nnx = fish[i].x + bx[(fish[i].dir + j) % 8];

				if (is_ok(nny, nnx) == 1 && 1 <= map[nny][nnx]) {
					fish[i].dir = (fish[i].dir + j) % 8;
					fish_swap(map, fish, i, nny, nnx); // 빈칸으로 swap될때는 또 따로 해줘야할것같음 
					flag = true;
					break;
				}
				else if (is_ok(nny, nnx) == 1 && 0 == map[nny][nnx]) { // 빈칸이랑 스왑될 때
					fish[i].dir = (fish[i].dir + j) % 8;
					map[fish[i].y][fish[i].x] = 0;
					fish[i].y = nny;
					fish[i].x = nnx;
					map[fish[i].y][fish[i].x] = fish[i].num;
					flag = true;
					break;
				}
			}
		}
		if (1 <= map[ny][nx] && flag == false)  // 이동 가능
			fish_swap(map, fish, i, ny, nx);
		else if (map[ny][nx] == 0 && flag == false) {
			map[fish[i].y][fish[i].x] = 0;
			fish[i].y = ny;
			fish[i].x = nx;
			map[fish[i].y][fish[i].x] = fish[i].num;
		}
	}
}
void input_shark(FISH fish[17], int y, int x, int dir) {
	fish[0].y = y;
	fish[0].x = x;
	fish[0].dir = dir;
}
void copy_map(int copy_map[4][4], int origin_map[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			copy_map[i][j] = origin_map[i][j];
		}
	}
}
void copy_fish(FISH copy_fish[17], FISH origin_fish[17]) {
	for (int i = 0; i < 17; i++) {
		copy_fish[i] = origin_fish[i];
	}
}
int dfs(int origin_map[4][4], int y, int x, FISH origin_fish[17]) {
	int map[4][4];
	FISH fish[17];
	copy_map(map, origin_map);
	copy_fish(fish, origin_fish);

	int eat = map[y][x];
	int ans = 0;
	input_shark(fish, y, x, fish[eat].dir);
	init(map, fish, eat);


	// 물고기 이동
	moving_fish(map, fish);

	// 상어 이동
	int ny = y + by[fish[0].dir];
	int nx = x + bx[fish[0].dir];

	while (is_ok(ny, nx) == 1) {
		if (map[ny][nx] != 0) {
			map[y][x] = 0;
			int temp = dfs(map, ny, nx, fish);
			if (ans < temp)
				ans = temp;
		}
		ny += by[fish[0].dir];
		nx += bx[fish[0].dir];
	}
	return ans + eat;
}
int main() {
	freopen("Text.txt", "r", stdin);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d %d", &a, &b);
			real_fish[++fish_count].num = a;
			real_fish[fish_count].dir = b - 1;
			real_fish[fish_count].y = i;
			real_fish[fish_count].x = j;
			real_map[i][j] = a;
		}
	}
	sort();

	printf("%d\n", dfs(real_map, 0, 0, real_fish));
	return 0;
}