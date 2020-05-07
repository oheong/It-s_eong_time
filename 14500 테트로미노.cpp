#include <stdio.h>
#define SIZE 500
int N, M, max;
int map[SIZE][SIZE], arr[8];
void searchMax() {
	for (int i = 0; i < 8; i++) {
		if (max < arr[i])
			max = arr[i];
	}
}
void s1() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M - 3; j++) {//가로로 긴거
			int sum = 0;
			sum += map[i][j];
			sum += map[i][j + 1];
			sum += map[i][j + 2];
			sum += map[i][j + 3];
			if (max < sum)max = sum;
		}
	}
	for (int i = 0; i < N - 3; i++) {
		for (int j = 0; j < M; j++) {//세로로긴거
			int sum = 0;
			sum += map[i][j];
			sum += map[i + 1][j];
			sum += map[i + 2][j];
			sum += map[i + 3][j];
			if (max < sum)max = sum;
		}
	}
}
void s2() {
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M - 1; j++) {
			int sum = 0;
			sum += map[i][j];
			sum += map[i + 1][j];
			sum += map[i][j + 1];
			sum += map[i + 1][j + 1];
			if (max < sum)max = sum;
		}
	}
}
void s3() {
	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M - 1; j++) {//3*2
			arr[0] = map[i][j];
			arr[0] += map[i + 1][j];
			arr[0] += map[i + 2][j];
			arr[0] += map[i + 2][j + 1];

			arr[1] = map[i][j];
			arr[1] += map[i][j + 1];
			arr[1] += map[i + 1][j + 1];
			arr[1] += map[i + 2][j + 1];

			arr[2] = map[i][j + 1];
			arr[2] += map[i + 1][j + 1];
			arr[2] += map[i + 2][j + 1];
			arr[2] += map[i + 2][j];

			arr[3] = map[i][j];
			arr[3] += map[i][j + 1];
			arr[3] += map[i + 1][j];
			arr[3] += map[i + 2][j];
			//////////////////////////////
			arr[4] = map[i][j];
			arr[4] += map[i + 1][j];
			arr[4] += map[i + 1][j + 1];
			arr[4] += map[i + 2][j + 1];

			arr[5] = map[i][j + 1];
			arr[5] += map[i + 1][j + 1];
			arr[5] += map[i + 1][j];
			arr[5] += map[i + 2][j];
			//////////////////////////////
			arr[6] = map[i][j];
			arr[6] += map[i + 1][j];
			arr[6] += map[i + 1][j + 1];
			arr[6] += map[i + 2][j];

			arr[7] = map[i][j + 1];
			arr[7] += map[i + 1][j + 1];
			arr[7] += map[i + 1][j];
			arr[7] += map[i + 2][j + 1];
			searchMax();
		}
	}
	for (int i = 0; i < N - 1; i++) {//2*3
		for (int j = 0; j < M - 2; j++) {
			arr[0] = map[i][j];
			arr[0] += map[i][j + 1];
			arr[0] += map[i][j + 2];
			arr[0] += map[i + 1][j + 2];

			arr[1] = map[i][j];
			arr[1] += map[i][j + 1];
			arr[1] += map[i][j + 2];
			arr[1] += map[i + 1][j];

			arr[2] = map[i + 1][j];
			arr[2] += map[i + 1][j + 1];
			arr[2] += map[i + 1][j + 2];
			arr[2] += map[i][j + 2];

			arr[3] = map[i][j];
			arr[3] += map[i + 1][j];
			arr[3] += map[i + 1][j + 1];
			arr[3] += map[i + 1][j + 2];
			//////////////////////////////
			arr[4] = map[i + 1][j];
			arr[4] += map[i + 1][j + 1];
			arr[4] += map[i][j + 1];
			arr[4] += map[i][j + 2];

			arr[5] = map[i][j];
			arr[5] += map[i][j + 1];
			arr[5] += map[i + 1][j + 1];
			arr[5] += map[i + 1][j + 2];
			//////////////////////////////
			arr[6] = map[i + 1][j];
			arr[6] += map[i + 1][j + 1];
			arr[6] += map[i][j + 1];
			arr[6] += map[i + 1][j + 2];

			arr[7] = map[i][j];
			arr[7] += map[i][j + 1];
			arr[7] += map[i + 1][j + 1];
			arr[7] += map[i][j + 2];
			searchMax();
		}
	}
}
int main() {
	//freopen("Text.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	s1();
	s2();
	s3();
	printf("%d\n", max);
	return 0;
}