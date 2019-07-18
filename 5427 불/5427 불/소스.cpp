#include <stdio.h>
#define SIZE 1010
//1002
int testcase, H, W, jiny, jinx, f = -1, r = -1, min = 2123456789;
int bx[4] = { 1, -1,0,0 }, by[4] = { 0,0,1,-1 }, visited[SIZE][SIZE];
char c, map[SIZE][SIZE];
typedef struct Queue { int state; int y; int x; int step; };
Queue q[SIZE*SIZE * 2];
void enQ(int state, int y, int x, int step) {
	r++;
	q[r].state = state;
	q[r].x = x;
	q[r].y = y;
	q[r].step = step;
}
void deQ() { f++; }
Queue peek() { return q[f + 1]; }
int empty() {
	if (f == r) return 1;
	else return 0;
}
void init(int H, int W) {
	min = 2123456789;
	f = r = -1;
	for (int h = 0; h < H; h++) {
		for (int w = 0; w <= W; w++) {
			visited[h][w] = 0;
			map[h][w] = '\0';
		}
	}
}
bool final_point(int y, int x) {//탈출가능하면 return true 탈출불가능이면 return false
	if (visited[y][x] == 9) return false;
	if (visited[y][x] == 2) return false;
	if (y == 0 || y == H - 1) {
		for (int i = 0; i < W; i++) {
			if (x == i)
				return true;
		}
		return false;
	}
	else if (x == 0 || x == W - 1) {
		for (int i = 0; i < H; i++) {
			if (y == i)
				return true;
		}
		return false;
	}
	return false;
}
void bfs() {
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		int tstate = peek().state;
		int tstep = peek().step;
		if (final_point(ty, tx) == true) {
			printf("%d\n", tstep);
			return;
		}
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < H && 0 <= nx && nx < W) {
				if (tstate == 1 && visited[ny][nx] == 0) {
					//사람
					if (final_point(ny, nx) == true) {
						printf("%d\n", tstep + 1);
						return;
					}
					else {
						map[ty][tx] = '\0';
						map[ny][nx] = '@';
						visited[ny][nx] = 1;
						enQ(1, ny, nx, tstep + 1);
					}
				}
				else if (tstate == 2 && visited[ny][nx] != 2 && visited[ny][nx] != 9 && map[ny][nx] != '@') {
					//불
					visited[ny][nx] = 2;
					enQ(2, ny, nx, 0);
				}
			}
		}
	}
	printf("IMPOSSIBLE\n");
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &testcase);
	for (int test = 0; test < testcase; test++) {
		scanf("%d %d\n", &W, &H);
		int a, b;
		for (int h = 0; h < H; h++) {
			for (int w = 0; w <= W; w++) {
				scanf("%c", &map[h][w]);
				if (map[h][w] == '*') {//불
					visited[h][w] = 2;
					enQ(2, h, w, 0);
				}
				else if (map[h][w] == '@') {//사람
					visited[h][w] = 1;
					jiny = h; jinx = w;
				}
				else if (map[h][w] == '#')visited[h][w] = 9;
			}
		}
		enQ(1, jiny, jinx, 1);
		bfs();
		init(H, W);
	}
	return 0;
}
/* Text.txt
2
5
IMPOLLSIBLE
IMPOLLSIBLE
IMPOLLSIBLE
1
1
1995
*/

/*Text2.txt
1
IMPOSSIBLE
2
IMPOSSIBLE
6
5
IMPOSSIBLE
IMPOSSIBLE
28
IMPOSSIBLE
IMPOSSIBLE
IMPOSSIBLE
4
4
4
4
4
4
4
4
2
*/