#include <stdio.h>
#define SIZE 100
int C, R, M, r, c, s, d, z, move = 1, ans;
int by[5] = { 0,-1,1,0,0 }, bx[5] = { 0,0,0,1, -1 };
typedef struct { bool ym; int y; int x; int speed; int direction; int size; int ny; int nx; }SHARK;
SHARK shark[SIZE*SIZE];
int tempshark[SIZE][SIZE], map[SIZE][SIZE];
void init(int m) {
	shark[m].ym = false;
	shark[m].speed = 0;
	shark[m].direction = 0;
	shark[m].size = 0;

	shark[m].y = shark[m].ny;
	shark[m].x = shark[m].nx;
	shark[m].ny = -1;
	shark[m].nx = -1;
}
int changeDirec(int w) {//���� ��ȯ
	return (w + 2) % 4;
}
void getshark(int man) {//�� ��ƹ��� m�� ����� ��
	for (int i = 0; i < M; i++) {
		if (shark[i].x == man && shark[i].ym == true)
			map[shark[i].y][man] = shark[i].size;
	}
	for (int i = 0; i < R; i++) {
		if (map[i][man] != 0) {
			ans += shark[i].size;
			init(i);
			return;
		}
		else if (map[man-1-i][man] != 0) {
			ans += shark[man].size;
			init(man - 1 - i);
			return;
		}
	}
}
void moveshark(int m) {
	int ty = shark[m].y;
	int tx = shark[m].x;
	int count = shark[m].speed;//��ŭ �����ϰ�����?
	int dir = shark[m].direction;//����
	while (0 <= count) {
		if (dir == 1 || dir == 2) {
			ty += by[dir];
		}
		else if (dir == 3 || dir == 4) {
			tx += bx[dir];
		}

		if (tx == 0 || tx == C - 1 || ty == 0 || ty == R - 1) {
			changeDirec(dir);
		}
		count--;
	}// ����̵�

	shark[m].ny = ty;
	shark[m].nx = tx;
	tempshark[ty][tx]++;
}
void tempinit() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			tempshark[i][j] = 0;
			map[i][j] = 0;
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d %d", &C, &R, &M);
	for (int m = 0; m < M; m++) {
		scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
		shark[m].ym = true;
		shark[m].y = r;
		shark[m].x = c;
		shark[m].speed = s;
		shark[m].direction = d;
		shark[m].size = z;
	}
	while (move <= R) {
		getshark(move); //����� �������

		for (int m = 0; m < M; m++) {
			if (shark[m].ym == true)
				moveshark(m); //��� ������.
		}

		//���� ��Ƹ���
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (tempshark[i][j] > 1) {
					int max = 0;
					for (int m = 0; m < M; m++) {//���� ��ġ�� ���� ���� �� ���� ū�� ���
						if (shark[m].ny == i && shark[m].x == j && shark[m].ym == true) {
							if (shark[m].size > max)max = shark[m].size;
						}
					}
					///////////////////////////////////////////////////////
					for (int m = 0; m < M; m++) {//ū�� ���ܳ��� ���� ����.
						if (shark[m].ny == i && shark[m].x == j && shark[m].size < max) {
							init(m);//false�� ���������ϱ� �� �׾����
						}
					}
				}
			}
		}
		tempinit();
		move++;
	}
	printf("%d\n", ans);
	return 0;
}