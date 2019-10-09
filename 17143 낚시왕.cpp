#include <stdio.h>
#define SIZE 101
int R, C, M, r, c, s, d, z, ans;
int state[SIZE][SIZE][2], by[4] = { -1,0,1,0 }, bx[4] = { 0,1,0,-1 };
typedef struct { int life; int y; int x; int s; int d; int z; }SHARK;
//life==1 ��� �������. life==0 ��� ��ݤ�
SHARK shark[SIZE*SIZE];
void get_shark(int man) {//�������
	for (int i = 0; i < R; i++) {
		if (state[i][man][man % 2] != 0) {
			shark[state[i][man][man % 2]].life = 0;
			ans += shark[state[i][man][man % 2]].z;
			state[i][man][man % 2] = 0;
			return;
		}
	}
}
int make_dir(int dir) { return (dir + 2) % 4; }
void move(int man) {
	for (int i = 1; i <= M; i++) {
		if (shark[i].life == 0)continue; //��� �׾����� �� �Ѿ�󤻤�

		state[shark[i].y][shark[i].x][man % 2] = 0;
		if (shark[i].d % 2 == 0) {//���Ʒ�
			int temp_size = shark[i].s % ((R - 1) * 2);
			int y = shark[i].y;
			for (int t = 0; t < temp_size; t++) {
				y += by[shark[i].d];
				if (y == 0 || y == R - 1)shark[i].d = make_dir(shark[i].d);
			}
			shark[i].y = y;
			if (state[y][shark[i].x][(man + 1) % 2] != 0) {//ū ���� �Ծ ����ġ����
				int temp = state[y][shark[i].x][(man + 1) % 2];//�ӽ� �ε���
				//temp�� ���� �ִ� �� i�� �������� ��
				if (shark[temp].z < shark[i].z) {//���࿡ �������� ���� �� ũ��?
					shark[temp].life = 0;
					state[y][shark[i].x][(man + 1) % 2] = i;
				}
				else shark[i].life = 0;
			}
			else state[y][shark[i].x][(man + 1) % 2] = i;
		}
		else {
			int temp_size = shark[i].s % ((C - 1) * 2);
			int x = shark[i].x;

			for (int t = 0; t < temp_size; t++) {
				x += bx[shark[i].d];
				if (x == 0 || x == C - 1) shark[i].d = make_dir(shark[i].d);
			}
			shark[i].x = x;
			if (state[shark[i].y][x][(man + 1) % 2] != 0) {//ū ���� �Ծ ����ġ����
				int temp = state[shark[i].y][x][(man + 1) % 2];//�ӽ� �ε���
				//temp�� ���� �ִ� �� i�� �������� ��
				if (shark[temp].z < shark[i].z) {//���࿡ �������� ���� �� ũ��?
					shark[temp].life = 0;
					state[shark[i].y][x][(man + 1) % 2] = i;
				}
				else shark[i].life = 0;
			}
			else state[shark[i].y][x][(man + 1) % 2] = i;
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d %d", &R, &C, &M);
	for (int i = 1; i <= M; i++) {
		scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
		shark[i].life = 1;
		shark[i].y = r - 1;
		shark[i].x = c - 1;
		shark[i].s = s;//speed
		if (d == 1)d = 0;
		else if (d == 2)d = 2;
		else if (d == 3)d = 1;
		else if (d == 4)d = 3;
		if ((d == 0 && shark[i].y == 0) || (d == 2 && shark[i].y == R - 1) || (d == 3 && shark[i].x == 0) || (d == 1 && shark[i].x == C - 1))
			shark[i].d = make_dir(d);
		else shark[i].d = d;//����
		shark[i].z = z;//ũ��
		state[shark[i].y][shark[i].x][0] = i;
	}
	int man = 0;
	while (man < C) {
		get_shark(man);
		move(man);
		man++;
	}
	printf("%d\n", ans);
	return 0;
}
//674166