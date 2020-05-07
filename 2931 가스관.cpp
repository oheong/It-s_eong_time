#include <stdio.h>
#define SIZE 26
int C, R, r = -1, f = -1, mx, my, zx, zy, ansy, ansx, c, choice;
int visited[SIZE][SIZE], by[4] = { -1,0,1,0 }, bx[4] = { 0,1,0,-1 };
char map[SIZE][SIZE], ans;
bool flag = false;
int gogo[8][4] = {
	{1,0,1,0},
	{0,1,0,1},
	{1,1,1,1},
	{0,1,1,0},
	{1,1,0,0},
	{1,0,0,1},
	{0,0,1,1},
	{0,0,0,0} };
typedef struct { int y; int x; }Queue;
Queue q[SIZE*SIZE*SIZE*SIZE];
void enQ(int y, int x) {
	r++;
	q[r].y = y;
	q[r].x = x;
}
void deQ() { f++; }
Queue peek() { return q[f + 1]; }
int empty() {
	if (r == f)return 1;
	else return 0;
}
char getNext(int y, int x) {
	for (int i = 0; i < 7; i++) {// 도형 정해놓고 시작
		int count = 0;
		for (int j = 0; j < 4; j++) {//상하좌우 다 돌아가는가?
			int ny = y + by[j];
			int nx = x + bx[j];

			if (map[ny][nx] == '|') c = 0;
			else if (map[ny][nx] == '-') c = 1;
			else if (map[ny][nx] == '+') c = 2;
			else if (map[ny][nx] == '1') c = 3;
			else if (map[ny][nx] == '2') c = 4;
			else if (map[ny][nx] == '3') c = 5;
			else if (map[ny][nx] == '4') c = 6;
			else if (map[ny][nx] == '.' || 0 > ny || ny >= R || 0 > nx || nx >= C)c = 7;
			else if (map[ny][nx] == 'M' || map[ny][nx] == 'Z')c = 2;
			else break;


			if (gogo[i][j] != gogo[c][(j + 2) % 4])
				break;
			else
				count++;
			if (count == 4) {
				//이 까지오면
				if (i == 0) ans = '|';
				if (i == 1) ans = '-';
				if (i == 2) ans = '+';
				if (i == 3) ans = '1';
				if (i == 4) ans = '2';
				if (i == 5) ans = '3';
				if (i == 6) ans = '4';

				map[y][x] = ans;
				flag = true;
				return ans;
			}
		}
	}
	ans = '.';
	return ans;
}
void bfs(int y, int x) {
	visited[y][x] = 1;
	enQ(y, x);
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		deQ();
		if (map[ty][tx] == 'Z') return;

		if (map[ty][tx] == '|') choice = 0;
		else if (map[ty][tx] == '-') choice = 1;
		else if (map[ty][tx] == '+' || map[ty][tx] == 'M') choice = 2;
		else if (map[ty][tx] == '1') choice = 3;
		else if (map[ty][tx] == '2') choice = 4;
		else if (map[ty][tx] == '3') choice = 5;
		else if (map[ty][tx] == '4') choice = 6;

		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < R && 0 <= nx && nx < C&&gogo[choice][i] == 1 && visited[ny][nx] < visited[ty][tx]) {
				if (map[ny][nx] != '.') {
					visited[ny][nx]++;
					enQ(ny, nx);
				}
				else if (map[ny][nx] == '.'&flag == false) {
					ansy = ny;
					ansx = nx;
					if (getNext(ny, nx) != '.') {
						enQ(ny, nx);
						visited[ny][nx]++;
					}
				}
			}
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d\n", &R, &C);
	for (int i = 0; i <= R; i++) {
		for (int j = 0; j <= C; j++) {
			scanf("%c", &map[i][j]);
			if (map[i][j] == 'M') {
				my = i; mx = j;
			}
			else if (map[i][j] == 'Z') {
				zy = i; zx = j;
			}
		}
	}
	bfs(my, mx);
	if (ans != NULL)
		printf("%d %d %c\n", ansy + 1, ansx + 1, ans);
	return 0;
}