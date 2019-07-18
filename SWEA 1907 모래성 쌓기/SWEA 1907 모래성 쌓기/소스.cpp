//와 시발,,,,,,,, 생각을 이렇게 할 수 도 있구나 씨발,,,,
#include <stdio.h>
#define SIZE 1010
int T, H, W, f = -1, r = -1, ans;
int map[SIZE][SIZE], visited[SIZE][SIZE], by[8] = { -1,-1,0,1,1,1,0,-1 }, bx[8] = { 0,1,1,1,0,-1,-1,-1 };
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
	if (f == r)return 1;
	else return 0;
}
void init() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			map[i][j] = 0;
			visited[i][j] = 0;
		}
	}
}
void bfs() {
	while (empty() == 0) {
		ans++;
		int size = r - f;
		for (int s = 0; s < size; s++) {
			int ty = peek().y;
			int tx = peek().x;
			deQ();
			//지금 들어온놈은 이제 걍 0이란거임ㅇㅇ 무너졌음.
			for (int i = 0; i < 8; i++) {
				int ny = ty + by[i];
				int nx = tx + bx[i];
				if (map[ny][nx] > visited[ny][nx]) visited[ny][nx]++;
				else continue;
				if (map[ny][nx] <= visited[ny][nx]) {
					enQ(ny, nx);//다음에 무너질 것
				}
			}
		}
	}
}
int main() {
	//freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	char c;
	for (int test = 0; test < T; test++) {
		ans = 0;
		f = r = -1;
		scanf("%d %d\n", &H, &W);
		for (int i = 0; i < H; i++) {
			for (int j = 0; j <= W; j++) {
				scanf("%c", &c);
				if (c == '.') continue;
				else if (c == '1')map[i][j] = 1;
				else if (c == '2')map[i][j] = 2;
				else if (c == '3')map[i][j] = 3;
				else if (c == '4')map[i][j] = 4;
				else if (c == '5')map[i][j] = 5;
				else if (c == '6')map[i][j] = 6;
				else if (c == '7')map[i][j] = 7;
				else if (c == '8')map[i][j] = 8;
				else if (c == '9')map[i][j] = 9;
			}
		}
		for (int i = 1; i < H - 1; i++) {
			for (int j = 1; j < W - 1; j++) {
				for (int k = 0; k < 8; k++) {
					if (map[i + by[k]][j + bx[k]] == 0)
						visited[i][j]++;
				}
				if (map[i][j] != 0 && visited[i][j] >= map[i][j]) enQ(i, j);
			}
		}
		bfs();
		printf("#%d %d\n", test + 1, ans);
		init();
	}
	return 0;
}