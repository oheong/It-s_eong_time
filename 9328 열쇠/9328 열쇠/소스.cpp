#include <stdio.h>
#define SIZE 110
int W, H, T, key_count, door_count, ans, f = -1, r = -1;
int by[4] = { 0,0,1,-1 }, bx[4] = { 1,-1,0,0 }, visited[SIZE][SIZE];
char map[SIZE][SIZE], KEY[50];
typedef struct { int y; int x; }DOOR;
DOOR door[400];
DOOR q[SIZE*SIZE];
bool flag = false;
void enQ(int y, int x) {
	r++;
	q[r].y = y;
	q[r].x = x;
}
void deQ() { f++; }
int empty() {
	if (r == f) return 1;
	else return 0;
}
DOOR peek() { return q[f + 1]; }
int keyCount() {
	int c = 0;
	if (KEY[0] - 0 == 0)return 0;
	for (int i = 0; KEY[i] != '\0'; i++) {
		c++;
	}
	return c;
}
bool isOk(int y, int x) {
	if (y == 0 || y == H - 1 || x == 0 || x == W - 1)return true;
	else return false;
}
void init() {
	f = r = -1;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			visited[i][j] = 0;
		}
	}
}
void unlock() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			for (int k = 0; k < key_count; k++) {
				if (map[i][j] == KEY[k] - 32) {
					map[i][j] = '.';
					if (isOk(i, j) == true) {
						door[door_count].y = i;
						door[door_count++].x = j;
					}
				}
			}
		}
	}
}
void bfs() {
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < H && 0 <= nx && nx < W&&visited[ny][nx] == 0 && map[ny][nx] != '*') {
				if ('a' <= map[ny][nx] && map[ny][nx] <= 'z') {
					//소문자
					KEY[key_count++] = map[ny][nx];
					map[ny][nx] = '.';
					return;
				}
				else if (map[ny][nx] == '$') {
					ans++;
					enQ(ny, nx);
					visited[ny][nx] = 1;
					map[ny][nx] = '.';
				}
				else if (map[ny][nx] == '.') {
					enQ(ny, nx);
					visited[ny][nx] = 1;
				}
			}
		}
	}
	flag = true;
}
void push() {
	for (int i = 0; i < door_count; i++) {
		enQ(door[i].y, door[i].x);
		visited[door[i].y][door[i].x] = 1;
	}
}
int main() {
	//freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d %d\n", &H, &W);
		for (int i = 0; i < H; i++) {
			for (int j = 0; j <= W; j++) {
				scanf("%c", &map[i][j]);
				if (map[i][j] == '.' && isOk(i, j) == true) {
					door[door_count].y = i;
					door[door_count++].x = j;
				}
			}
		}
		scanf("%s", &KEY);
		key_count = keyCount();
		while (1) {
			unlock();
			push();
			bfs();
			if (flag == true)break;
			else init();
		}
		printf("%d\n", ans);
		ans = 0;
		key_count = door_count = 0;
		flag = false;
		init();
	}
	return 0;
}

/*
key 받은곳은 map에 가서 바로 언락해줌
가에서부터 돌림(문)

소문자 만남->KEY에 추가
또 돌려서 언락시켜주고,,,,,,,,,,,

*/

/*
1
3 5
*A***
*$*a.
*****
0

1
*/