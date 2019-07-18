#include <stdio.h>
#define SIZE 100
int R, C, M, r, c, s, d, z, ans;
int map[SIZE][SIZE], by[5] = { 0,-1,1,0,0 }, bx[5] = { 0,0,0,1,-1 };
typedef struct { int y; int x; int speed; int direction; int size; }FISH;
FISH fish[SIZE*SIZE], temp[SIZE];
void outFish(int m) {
	fish[m].y = -1;
	fish[m].x = -1;
	fish[m].speed = 0;
	fish[m].direction = 0;
	fish[m].size = 0;
}
void copyFish(int man) {//map���� ����� �̵�
	for (int m = 0; m < M; m++) {
		int y = fish[m].y;
		int x = fish[m].x;
		if (y == -1 || x == -1 || x != man) continue;
		map[y][x] = 1;//����� ����
	}
}
void init() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			map[i][j] = 0;
		}
	}
}
void getFish(int man) {//����� ���
	int y = 0;
	for (int i = 0; i < R; i++) {
		if (map[i][man] == 1) {
			y = i; break;
		}
	}
	for (int m = 0; m < M; m++) {
		if (fish[m].y == y && fish[m].x == man) {
			ans += fish[m].size;
			outFish(m);
			return;
		}
	}
}
void go(int m, int y, int x, int speed, int dir, int size) {
	int count = speed;
	while (0 < count) {
		y += by[dir];
		x += bx[dir];
		if (y == -1 || y == R || x == -1 || x == C) {//�ش����� �κб��� ������ �����.
			/*
			�̻��� �ݸ��� ��쿡�� �迭���� ���� �־� ������ �ٲ� �� �־����� �� ����������
			���� ������ �ٲ�� �κ��� ����� ���� �ʾұ⶧����, ���� �迭 ���� ����� ��Ȳ������ ������ �ٲ������!!!!!!!
			�� ���� �� ĭ �� ���ذ� ���� ���ְ�, ���� ��ȯ!!!��
			*/
			y -= by[dir];
			x -= bx[dir];
			if (dir == 1) dir = 2;
			else if (dir == 2) dir = 1;
			else if (dir == 3)dir = 4;
			else if (dir == 4) dir = 3;
			continue;
		}
		count--;
	}
	fish[m].y = y;
	fish[m].x = x;
	fish[m].direction = dir;
}
void eatFish(int y, int x) {//����� �Ա�
	int count = 0;
	int max = 0;
	for (int m = 0; m < M; m++) {
		if (fish[m].y == y && fish[m].x == x) {
			temp[count].y = m;
			temp[count++].size = fish[m].size;
			if (fish[m].size > max)max = fish[m].size;
		}
	}
	for (int i = 0; i < count; i++) {
		if (temp[i].size == max) continue;
		outFish(temp[i].y);
	}
}
void moveFish() {//����� �̵�
	for (int m = 0; m < M; m++) {
		if (fish[m].y == -1 || fish[m].x == -1)continue;
		go(m, fish[m].y, fish[m].x, fish[m].speed, fish[m].direction, fish[m].size);
	}
	//fish�� ���ŵ� ��ġ �� ���� ������
	for (int i = 0; i < M; i++) {
		if (fish[i].y == -1 || fish[i].x == -1)continue;
		int y = fish[i].y;
		int x = fish[i].x;
		eatFish(y, x);
	}
}

int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d %d", &R, &C, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
		fish[i].y = r - 1;
		fish[i].x = c - 1;
		fish[i].speed = s;
		fish[i].direction = d;
		fish[i].size = z;
	}
	int man = 0;
	while (man < C) {//��� �̵�
		copyFish(man);
		getFish(man);
		moveFish();
		init();
		man++;
	}
	printf("%d\n", ans);
	return 0;
}


/*
100 7 7
3 2 2 3 9
3 3 1 3 3
3 5 1 4 7
3 6 2 4 6
2 4 1 2 8
1 4 2 2 4
4 4 1 1 5

0


100 3 2
2 3 0 1 2
4 3 1 1 3

3
*/