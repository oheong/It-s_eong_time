#include <stdio.h>
#define SIZE 1000
int testcase, n,x, y;
int map[SIZE][SIZE];

//�÷��̵� �ͼ� �˰���,,,? �ֶ� ����

int main() {
	scanf("%d", &testcase);
	for (int test = 0; test < testcase; test++) {
		scanf("%d", &n);//������ ����
		for (int i = 0; i < n + 2; i++) {
			scanf("%d %d", &x, &y);
			map[y][x] = 1;
		}

	}
	return 0;
}