#include <stdio.h>
#define SIZE 100
int T, H, W, f = -1, r = -1, max;
char map[SIZE][SIZE];
int visited[SIZE][SIZE], by[4] = { 1,-1,0,0 }, bx[4] = { 0,0,1,-1 };
typedef struct { int y; int x; int door; }Queue;
Queue q[SIZE*SIZE*SIZE];
void enQ(int y, int x, int door) {
	r++;
	q[r].y = y;
	q[r].x = x;
	q[r].door = door;
}
void deQ() { f++; }
Queue peek() { return q[f + 1]; }
int empty() {
	if (r == f)return 1;
	else return 0;
}
bool isEnd(int y, int x) {
	if (y == 0 || y == H - 1 || x == 0 || x == W - 1)return true;//ㅇㅇ 여기는 문임
	else return false;
}
void init() {
	max = 0;
	f = r = -1;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			visited[i][j] = 0;
		}
	}
}
void bfs() {
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		int tdoor = peek().door;
		if (isEnd(ty, tx) == true) {
			if (tdoor > max)max = tdoor;
		}
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (isEnd(ny, nx) == false && map[ny][nx] != '*'&&visited[ny][nx] < visited[ty][tx]) {
				if (map[ny][nx] == '#') {
					if (visited[ny][nx] == 0) tdoor++;
				}
				visited[ny][nx]++;
				enQ(ny, nx, tdoor);
			}
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d %d\n", &H, &W);
		for (int i = 0; i < H; i++) {
			for (int j = 0; j <= W; j++) {
				scanf("%c", &map[i][j]);
				if (map[i][j] == '$') {
					enQ(i, j, 0);
					visited[i][j] = 1;
				}
			}
		}
		bfs();
		printf("%d\n", max);
		init();
	}
	return 0;
}