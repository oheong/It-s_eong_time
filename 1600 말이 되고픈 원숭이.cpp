#include <stdio.h>
#define SIZE 200 
int W, H, K, f = -1, r = -1;
int map[SIZE][SIZE];
bool visited[SIZE][SIZE][40];
int by[4] = { 0,0,1,-1 }, bx[4] = { 1,-1,0,0 }, hy[8] = { -2,-1,1,2,2,1,-1,-2 }, hx[8] = { 1,2,2,1,-1,-2,-2,-1 };
typedef struct { int y; int x; int k; int step; }Queue;
Queue q[SIZE*SIZE*SIZE];
void enQ(int y, int x, int k, int step) {
	r++;
	q[r].y = y;
	q[r].x = x;
	q[r].k = k;
	q[r].step = step;
}
void deQ() { f++; }
Queue peek() { return q[f + 1]; }
int empty() {
	if (r == f)return 1;
	else return 0;
}
int bfs() {
	enQ(0, 0, K, 0);
	visited[0][0][K] = 1;
	visited[0][0][0] = 1;
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		int tk = peek().k;
		int tstep = peek().step;
		if (ty == H - 1 && tx == W - 1) {
			return tstep;
		}
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < H && 0 <= nx && nx < W&&map[ny][nx] == 0 && visited[ny][nx][tk] == 0) {
				enQ(ny, nx, tk, tstep + 1);
				//여기는 다음상황이 tk니까
				visited[ny][nx][tk] = 1;
				//그냥 tk에 넣어줌
			}
		}
		if (0 < tk) {
			for (int i = 0; i < 8; i++) {
				int ny = ty + hy[i];
				int nx = tx + hx[i];
				/*
				왜 여기는 tk-1을 넣냐?
				다음 상황을 봐야되니까!
				말에서 다음상황이란 tk-1에서의 상황임
				*/
				if (0 <= ny && ny < H && 0 <= nx && nx < W&&map[ny][nx] == 0 && visited[ny][nx][tk - 1] == 0) {
					enQ(ny, nx, tk - 1, tstep + 1);
					//여기는 다음에 들어갈 상황이 tk-1.
					visited[ny][nx][tk - 1] = 1;
					//그래서 tk-1에 true해주는거임 와 시발세상아;
				}
			}
		}

	}
	return -1;
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d %d", &K, &W, &H);//가로, 세로
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	printf("%d\n", bfs());

	return 0;
}