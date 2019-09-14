#include <stdio.h>
#define SIZE 100
int T, N, wormhole_count, f, r, max;
int map[SIZE][SIZE], by[4] = { -1,0,1,0 }, bx[4] = { 0,1,0,-1 };
typedef struct { int dir; int y; int x; int score; }Queue;
Queue q[SIZE*SIZE*SIZE], wormhole[5][2];
void enQ(int dir, int y, int x, int score) {
	r++;
	q[r].dir = dir;
	q[r].y = y;
	q[r].x = x;
	q[r].score = score;
}
void deQ() { f++; }
Queue peek() { return q[f + 1]; }
int empty() {
	if (r == f)return 1;
	else return 0;
}
int bounce(int dir, int ny, int nx) { //�������� ����
	if (ny == -1 || ny == N || nx == -1 || nx == N || map[ny][nx] == 5) return (dir + 2) % 4;
	else if (map[ny][nx] == 1) {
		if (dir == 0 || dir == 1) return (dir + 2) % 4;
		else {
			if (dir == 3)return 0;
			else if (dir == 2)return 1;
		}
	}
	else if (map[ny][nx] == 2) {
		if (dir == 2 || dir == 1) return (dir + 2) % 4;
		else {
			if (dir == 3)return 2;
			else if (dir == 0)return 1;
		}
	}
	else if (map[ny][nx] == 3) {
		if (dir == 2 || dir == 3) return (dir + 2) % 4;
		else {
			if (dir == 0)return 3;
			else if (dir == 1)return 2;
		}
	}
	else if (map[ny][nx] == 4) {
		if (dir == 0 || dir == 3) return (dir + 2) % 4;
		else {
			if (dir == 1)return 0;
			else if (dir == 2)return 3;
		}
	}
}
void bfs(int y, int x) {
	//y,x�� ������ ��ġ!!!����� �ٽ� ���ƿ��� ����!
	while (empty() == 0) {
		int ty = peek().y; int tx = peek().x;
		int tdir = peek().dir; int tscore = peek().score;
		if (tscore > max)max = tscore;
		deQ();
		int ny = ty; int nx = tx;
		while (1) {
			//���� �������� �� ���������� ��� ���°���
			ny += by[tdir];
			nx += bx[tdir];
			//���� ���¸� ������
			if ((1 <= map[ny][nx] && map[ny][nx] <= 5) || ny == -1 || ny == N || nx == -1 || nx == N) {
				//���� ƨ��� ��!
				//���⼭ ����++ �������
				int ndir = bounce(tdir, ny, nx);//���� ���� ������
				if (map[ny][nx] == -1 || (ny + by[ndir] == y && nx + bx[ndir] == x)) {//���⼭ ��Ȧ�� �ʿ��Ѱ�?
					//���� ƨ��µ� �� �ڽ��̰ų� ��Ȧ��
					if (max < tscore + 1)max = tscore + 1;
					break;
				}
				else {
					enQ(ndir, ny, nx, tscore + 1);
					break;
				}
			}
			else if (6 <= map[ny][nx] && map[ny][nx] <= 10) {
				//��Ȧ
				if (wormhole[map[ny][nx] - 6][0].y == ny && wormhole[map[ny][nx] - 6][0].x == nx) {
					enQ(tdir, wormhole[map[ny][nx] - 6][1].y, wormhole[map[ny][nx] - 6][1].x, tscore);
				}
				else {
					enQ(tdir, wormhole[map[ny][nx] - 6][0].y, wormhole[map[ny][nx] - 6][0].x, tscore);
				}
				break;
			}
			else if (map[ny][nx] == -1 || (ny == y && nx == x)) {
				//if (max < tscore + 1)max = tscore + 1;
				break;
			}
		}
	}
}
void init() {
	f = r = -1;
	max = 0;
	for (int i = 0; i < wormhole_count; i++) {
		for (int j = 0; j < 2; j++) {
			wormhole[i][j].dir = 0;
			wormhole[i][j].y = 0;
			wormhole[i][j].x = 0;
		}
	}
	wormhole_count = 0;
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
				if (6 <= map[i][j] && map[i][j] <= 10) {
					if (wormhole[map[i][j] - 6][0].dir == 0) {
						//�ش� ��Ȧ�� ���� �������� ����
						wormhole_count++;
						wormhole[map[i][j] - 6][0].dir = 1;
						wormhole[map[i][j] - 6][0].y = i;
						wormhole[map[i][j] - 6][0].x = j;
					}
					else {
						wormhole[map[i][j] - 6][1].y = i;
						wormhole[map[i][j] - 6][1].x = j;
					}
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 0) {
					f = r = -1;
					enQ(0, i, j, 0);
					enQ(1, i, j, 0);
					enQ(2, i, j, 0);
					enQ(3, i, j, 0);
					bfs(i, j);
				}
			}
		}
		printf("#%d %d\n", test + 1, max);
		init();
	}
	return 0;
}