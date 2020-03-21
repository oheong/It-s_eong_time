#include <stdio.h>
#define SIZE 101
int T, H, W, key_mine, f, r, ans;
char map[SIZE][SIZE], key[28];
int visited[SIZE][SIZE], by[4] = { 0,0,1,-1 }, bx[4] = { 1,-1,0,0 };
typedef struct { int y; int x; }Queue;
Queue q[SIZE*SIZE];
void enQ(int y, int x) {
	r++;
	q[r].y = y;
	q[r].x = x;
}
void deQ() { f++; }
int empty() {
	if (r == f)return 1;
	else return 0;
}
Queue peek() {
	return q[f + 1];
}
void get_already_key() {
	if (key[0] == '0')return;
	for (int i = 0; key[i] != '\0'; i++) {
		int how_many = key[i] - 96;
		key_mine |= (1 << how_many);
		key[i] = '\0';
	}
}
void bfs(int y, int x) {
	f = r = -1;
	enQ(y, x);
	visited[y][x] = 1;
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < H && 0 <= nx && nx < W&&visited[ny][nx] < key_mine && map[ny][nx] != '*') {
				if (map[ny][nx] == '$') {
					ans++;
					map[ny][nx] = '.';
				}
				else if ('a' <= map[ny][nx] && map[ny][nx] <= 'z') { // 열쇠
					int temp_key = map[ny][nx] - 96;
					key_mine |= (1 << temp_key);
				}
				else if ('A' <= map[ny][nx] && map[ny][nx] <= 'Z') { // 문
					int door = map[ny][nx] - 64;
					if ((key_mine & (1 << door)) == 0) { // 열쇠 없어서 문 못연다
						continue;
					}
				}
				enQ(ny, nx);
				visited[ny][nx] = key_mine;
			}
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		key_mine = 1;
		ans = 0;
		scanf("%d %d", &H, &W);
		for (int i = 0; i < H; i++) {
			scanf("%s", map[i]);
			for (int j = 0; j < W; j++) {
				if ('a' <= map[i][j] && map[i][j] <= 'z' && (i == 0 || j == 0 || i == H - 1 || j == W - 1)) {
					int how_many = map[i][j] - 96;
					key_mine |= (1 << how_many);
					map[i][j] = '.';
				}
				visited[i][j] = 0;
			}
		}
		scanf("%s", &key);
		get_already_key();
		for (int i = 0; i < H; i++) {
			if (map[i][0] == '*') continue;
			if (map[i][0] == '.') bfs(i, 0);
			else if ('A' <= map[i][0] && map[i][0] <= 'Z') {
				int door = map[i][0] - 64;
				if ((key_mine & (1 << door)) != 0) {
					bfs(i, 0);
				}
			}
		}
		for (int i = 0; i < H; i++) {
			if (map[i][W - 1] == '*') continue;
			if (map[i][W - 1] == '.') bfs(i, W - 1);
			else if ('A' <= map[i][W - 1] && map[i][W - 1] <= 'Z') {
				int door = map[i][W - 1] - 64;
				if ((key_mine & (1 << door)) != 0) {
					bfs(i, W - 1);
				}
			}
		}
		for (int j = 0; j < W; j++) {
			if (map[0][j] == '*') continue;
			if (map[0][j] == '.')bfs(0, j);
			else if ('A' <= map[0][j] && map[0][j] <= 'Z') {
				int door = map[0][j] - 64;
				if ((key_mine & (1 << door)) != 0) {
					bfs(0, j);
				}
			}
		}
		for (int j = 0; j < W; j++) {
			if (map[H - 1][j] == '*') continue;
			if (map[H - 1][j] == '.')bfs(H - 1, j);
			else if ('A' <= map[H - 1][j] && map[H - 1][j] <= 'Z') {
				int door = map[H - 1][j] - 64;
				if ((key_mine & (1 << door)) != 0) {
					bfs(H - 1, j);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}