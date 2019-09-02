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
				//����� ������Ȳ�� tk�ϱ�
				visited[ny][nx][tk] = 1;
				//�׳� tk�� �־���
			}
		}
		if (0 < tk) {
			for (int i = 0; i < 8; i++) {
				int ny = ty + hy[i];
				int nx = tx + hx[i];
				/*
				�� ����� tk-1�� �ֳ�?
				���� ��Ȳ�� ���ߵǴϱ�!
				������ ������Ȳ�̶� tk-1������ ��Ȳ��
				*/
				if (0 <= ny && ny < H && 0 <= nx && nx < W&&map[ny][nx] == 0 && visited[ny][nx][tk - 1] == 0) {
					enQ(ny, nx, tk - 1, tstep + 1);
					//����� ������ �� ��Ȳ�� tk-1.
					visited[ny][nx][tk - 1] = 1;
					//�׷��� tk-1�� true���ִ°��� �� �ù߼����;
				}
			}
		}

	}
	return -1;
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d %d", &K, &W, &H);//����, ����
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	printf("%d\n", bfs());

	return 0;
}