#include <stdio.h>
#define SIZE 15
int T, N, W, H, f, r, min;
int map[SIZE][SIZE], copy_map[SIZE][SIZE], visited[SIZE][SIZE], bomb[SIZE], copy_arr[SIZE];
typedef struct { int y; int x; int size; }Queue;
Queue q[SIZE*SIZE];
void enQ(int y, int x, int size) {
	r++;
	q[r].y = y;
	q[r].x = x;
	q[r].size = size;
}
void deQ() { f++; }
Queue peek() { return q[f + 1]; }
int empty() {
	if (f == r)return 1;
	else return 0;
}
int copy() {
	int count = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (copy_map[i][j] != 0) count++;
			copy_map[i][j] = map[i][j];
		}
	}
	return count;
}
void falling() {
	for (int j = 0; j < W; j++) {
		int count = 0;
		for (int i = H - 1; 0 <= i; i--) {
			visited[i][j] = 0;
			if (copy_map[i][j] != 0) copy_arr[count++] = copy_map[i][j];
			copy_map[i][j] = 0;
		}
		for (int i = 0; i < count; i++) {
			copy_map[H - 1 - i][j] = copy_arr[i];//tq
		}
	}
}
void remove_block() {
	while (empty() == 0) {
		int y = peek().y;
		int x = peek().x;
		int size = peek().size;
		deQ();
		copy_map[y][x] = 0;
		for (int i = 0; i < size; i++) {
			if (0 <= y - i) {
				if (copy_map[y - i][x] <= 1)
					copy_map[y - i][x] = 0;
				else {
					if (visited[y - i][x] == 0) {
						visited[y - i][x] = 1;
						enQ(y - i, x, copy_map[y - i][x]);
					}
				}
			}
			if (y + i < H) {
				if (copy_map[y + i][x] <= 1)
					copy_map[y + i][x] = 0;
				else {
					if (visited[y + i][x] == 0) {
						visited[y + i][x] = 1;
						enQ(y + i, x, copy_map[y + i][x]);
					}
				}
			}
			if (0 <= x - i) {
				if (copy_map[y][x - i] <= 1)
					copy_map[y][x - i] = 0;
				else {
					if (visited[y][x - i] == 0) {
						visited[y][x - i] = 1;
						enQ(y, x - i, copy_map[y][x - i]);
					}
				}
			}
			if (x + i < W) {
				if (copy_map[y][x + i] <= 1)
					copy_map[y][x + i] = 0;
				else {
					if (visited[y][x + i] == 0) {
						visited[y][x + i] = 1;
						enQ(y, x + i, copy_map[y][x + i]);
					}
				}
			}
		}
	}
}
void throw_bomb(int line) {
	for (int i = 0; i < H; i++) {
		if (copy_map[i][line] != 0) { // 터지기 시작해야함
			enQ(i, line, copy_map[i][line]);
			remove_block();
			return;
		}
	}
}
void dfs(int d) {
	if (d == N) {
		f = r = -1;
		for (int i = 0; i < N; i++) {
			throw_bomb(bomb[i]);
			falling();
		}
		int temp = copy();
		if (temp < min)min = temp;
		return;
	}
	for (int i = 0; i < W; i++) {
		bomb[d] = i;
		dfs(d + 1);
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d %d %d", &N, &W, &H);
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				scanf("%d", &map[i][j]);
				copy_map[i][j] = map[i][j];
			}
		}
		min = 2123456789;
		dfs(0);
		printf("#%d %d\n", test + 1, min);
	}
	return 0;
}