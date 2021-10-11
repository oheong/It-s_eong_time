#include <stdio.h>
#define SIZE 52
int N, M;
int map[SIZE][SIZE], cloud[SIZE][SIZE], temp_cloud[SIZE][SIZE], plus_water[SIZE][SIZE];
int d[SIZE * 2], s[SIZE * 2];
int by[9] = { 0, 0,-1,-1,-1,0,1,1,1 }, bx[9] = { 0, -1,-1,0,1,1,1,0,-1 };

void move(int y, int x, int dir, int s) {
	// 구름 움직이기
	cloud[y][x] = 0;

	y += (by[dir] * s);
	x += (bx[dir] * s);

	y = y % N;
	if (y < 0)
		y += N;

	x = x % N;
	if (x < 0)
		x += N;

	temp_cloud[y][x] = 1;
}
void rain() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cloud[i][j] = 0;

			if (temp_cloud[i][j] == 1) { // 이동된 구름
				map[i][j]++;
				temp_cloud[i][j] = 0;
				cloud[i][j] = 1;
			}
		}
	}
}
void set_cloud() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			if (plus_water[i][j] == -2) {
				// 다음 구름 생길 위치
				cloud[i][j] = 1;
			}

			map[i][j] += plus_water[i][j];
			plus_water[i][j] = 0;
		}
	}
}

void water_copy() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (cloud[i][j] == 1) {
				for (int dir = 1; dir <= 4; dir++) {
					int ny = i + by[dir * 2];
					int nx = j + bx[dir * 2];
					if (0 <= ny && ny < N && 0 <= nx && nx < N && 0 < map[ny][nx]) {
						plus_water[i][j]++;
					}
				}
				cloud[i][j] = 0;
			}

			// 5. 물의양이 2 이상이면 -2해줌
			else {
				if (2 <= map[i][j]) {
					plus_water[i][j] -= 2;
				}
			}
		}
	}
}

int get_ans() {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sum += map[i][j];
		}
	}
	return sum;
}

int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	cloud[N - 2][0] = 1;
	cloud[N - 2][1] = 1;
	cloud[N - 1][0] = 1;
	cloud[N - 1][1] = 1;

	for (int m = 0; m < M; m++) {
		scanf("%d %d", &d[m], &s[m]);

		// 1. 구름 움직이기
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (cloud[i][j] == 1) {
					move(i, j, d[m], s[m]);
				}
			}
		}

		// 2. 각 구름에서 비와서 +1
		// 3. 구름 모두 사라짐
		rain();

		// 4. 물복사 + 5. 물2이상 구름생성
		water_copy();

		set_cloud();
	}

	printf("%d\n", get_ans());

	return 0;
}