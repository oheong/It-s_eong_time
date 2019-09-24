#include <stdio.h>
int N, M, min = 2123456789;
char map[51][51];
char arr1[8][8] = {
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W'
}, arr2[8][8] = {
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B'
};
int counting(int y, int x) {
	int num1 = 0, num2 = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (map[i + y][j + x] != arr1[i][j]) num1++;
			if (map[i + y][j + x] != arr2[i][j]) num2++;
		}
	}
	if (num1 > num2)return num2;
	else return num1;
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d\n", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= M; j++) {
			scanf("%c", &map[i][j]);
		}
	}
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			int t = counting(i, j);
			if (min > t)min = t;
		}
	}
	printf("%d\n", min);
	return 0;
}