#include <stdio.h>
#define SIZE 20
int N, M, f, r, ans, max, max_rain, cnt_rain;
int by[4] = { -1,0,1,0 }, bx[4] = { 0,1,0,-1 };
int map[SIZE][SIZE], visited[SIZE][SIZE], copy_map[SIZE][SIZE], copy_visited[SIZE][SIZE];
typedef struct { int y; int x; }Queue;
Queue q[SIZE*SIZE];
void enQ(int y, int x) {
	r++;
	q[r].y = y;
	q[r].x = x;
}
void deQ() { f++; }
Queue peek() { return q[f + 1]; }
int empty() {
	if (f == r)return 0;
	return 1;
}
int bfs(int y, int x, int num, int visited_num) {
	f = r = -1;
	enQ(y, x);
	visited[y][x] = visited_num;
	cnt_rain = 0;
	int cnt = 1;
	while (empty() == 1) {
		int ty = peek().y;
		int tx = peek().x;
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < N&&visited[ny][nx] != visited_num && (map[ny][nx] == 0 || map[ny][nx] == num)) {
				visited[ny][nx] = visited_num;
				enQ(ny, nx);
				cnt++;
				if (map[ny][nx] == 0)cnt_rain++;
			}
		}
	}
	return cnt;
}
void init(int num) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (copy_visited[i][j] == num) {
				map[i][j] = 9;
			}
			visited[i][j] = 0;
			copy_visited[i][j] = 0;
		}
	}
}
void copy(int map1[SIZE][SIZE], int map2[SIZE][SIZE]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map1[i][j] = map2[i][j];
		}
	}
}
void gravity() {
	for (int j = 0; j < N; j++) {
		int temp_arr[SIZE] = { 0, };
		int index = 0;
		int start = N - 1;

		for (int i = N - 1; 0 <= i; i--) {
			if (map[i][j] == -1) {
				for (int id = 0; id < index; id++) { // 인덱스만큼 돌면서
					map[start - id][j] = temp_arr[id];
				}
				start = i - 1;
				index = 0;
				continue;
			}
			else if (0 <= map[i][j] && map[i][j] <= M) {
				temp_arr[index++] = map[i][j];
			}
			map[i][j] = 9;
		}
		if (index != 0) {
			for (int id = 0; id < index; id++) { // 인덱스만큼 돌면서
				map[start - id][j] = temp_arr[id];
			}
		}
	}
}

void turn() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			copy_map[i][j] = map[i][j];
		}
	}
	for (int i = N - 1; 0 <= i; i--) {
		for (int j = 0; j < N; j++) {
			map[N - 1 - j][i] = copy_map[i][j];
		}
	}
}

int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	while (1) {
		// 1
		int visited_num = 1;
		max = 1;
		max_rain = 0;
		int del_num = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j] == 0 && 0 < map[i][j] && map[i][j] <= M) {
					int temp = bfs(i, j, map[i][j], visited_num++);
					if (max < temp) {
						max = temp;
						del_num = visited_num - 1;
						copy(copy_visited, visited);
						//if (max_rain <= cnt_rain) // 이자식,,,
							max_rain = cnt_rain;
					}
					else if (max == temp) {
						if (max_rain <= cnt_rain) {
							del_num = visited_num - 1;
							copy(copy_visited, visited);
							max_rain = cnt_rain;
						}
					}
				}
			}
		}
		if (max == 1) break;

		// 2
		init(del_num);
		if (max != 1) {
			ans += (max*max);
		}
		// 3
		gravity();
		// 4
		turn();
		// 5
		gravity();
	}
	printf("%d\n", ans);
	return 0;
}