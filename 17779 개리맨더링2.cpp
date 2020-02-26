#include<stdio.h>
#define SIZE 20
int N, count, ans = 2123456789;

// 범위 범위,,,

int map[SIZE][SIZE], select[SIZE], visited[SIZE][SIZE];
int by[4] = { 1,1,-1 - 1 };
int bx[4] = { -1,1,1,-1 };
int is_ok(int y, int x, int left, int right) {
	if (x - left + 1 <= 0) return 1;//좌	
	if (N <= x + right - 1) return 1;//우
	if (N <= y + left + right - 2) return 1;//하
	return 0;
}
int get_dia(int y, int x, int cnt, int left, int right) {
	int sum = 0;
	for (int i = 0; i < right * 2 - 1; i++) {
		if (i % 2 == 0) { //left
			int ny = y;
			int nx = x;
			for (int j = 0; j < left; j++) {
				sum += map[ny][nx];
				visited[ny][nx] = cnt;
				ny += by[0];
				nx += bx[0];
			}
			y++;
		}

		else {//left-1
			int ny = y;
			int nx = x;
			for (int j = 0; j < left - 1; j++) {
				sum += map[ny][nx];
				visited[ny][nx] = cnt;
				ny += by[0];
				nx += bx[0];
			}
			x++;
		}
	}
	return sum;
}
int get_sec1(int y, int x, int cnt) { // y 문제
	int sum = 0;
	for (int i = 0; i < y; i++) {
		for (int j = 0; j <= x; j++) {
			if (visited[i][j] == cnt) break;
			sum += map[i][j];
			visited[i][j] = cnt;
		}
	}
	return sum;
}
int get_sec2(int y, int x, int cnt) {
	int sum = 0;
	for (int i = 0; i <= y; i++) {
		for (int j = x; j < N; j++) {
			if (visited[i][j] == cnt) continue;
			sum += map[i][j];
			visited[i][j] = cnt;
		}
	}
	return sum;
}
int get_sec3(int y, int x, int cnt) {
	int sum = 0;
	for (int i = y; i < N; i++) {
		for (int j = 0; j < x; j++) { // 쉬익,,
			if (visited[i][j] == cnt)break;
			sum += map[i][j];
			visited[i][j] = cnt;
		}
	}
	return sum;
}
int get_sec4(int cnt) {
	int sum = 0;
	for (int i = N - 1; 0 <= i; i--) {
		for (int j = N - 1; 0 <= j; j--) {
			if (visited[i][j] != cnt) {
				sum += map[i][j];
				visited[i][j] = cnt;
			}
			else break;
		}
	}
	return sum;
}
void dfs(int d) {
	if (d == 2) {
		if (N + 1 < select[0] + select[1]) return;

		//printf("%d %d\n", select[0], select[1]);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (is_ok(i, j, select[0], select[1]) == 1) continue;
				count++;
				int max = -2123456789;
				int min = 2123456789;
				int dia = get_dia(i, j, count, select[0], select[1]); // 다이아 모양 넓이 구함
				if (dia < min)min = dia;
				if (dia > max)max = dia;

				int sec1 = get_sec1(i + select[0] - 1, j, count);
				if (sec1 < min)min = sec1;
				if (sec1 > max)max = sec1;

				int sec2 = get_sec2(i + select[1] - 1, j + 1, count);
				if (sec2 < min)min = sec2;
				if (sec2 > max)max = sec2;

				int sec3 = get_sec3(i + select[0] - 1, j - select[0] + select[1], count);
				if (sec3 < min)min = sec3;
				if (sec3 > max)max = sec3;

				int sec4 = get_sec4(count);
				if (sec4 < min)min = sec4;
				if (sec4 > max)max = sec4;

				int temp = max - min;
				if (temp < ans) ans = temp;
			}
		}
		return;
	}
	for (int i = 2; i < N; i++) {
		select[d] = i;
		dfs(d + 1);
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	dfs(0);
	printf("%d\n", ans);
	return 0;
}