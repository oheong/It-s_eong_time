#include <stdio.h>
#define SIZE 20
int T, N, X, ans;
int map[SIZE][SIZE], line[SIZE];
void putLine(int w, int c) {
	if (w == 1)
		for (int i = 0; i < N; i++) line[i] = map[c][i];
	else
		for (int i = 0; i < N; i++) line[i] = map[i][c];
	//line에 검사해야 할 활주로가 들어가있음.
}
void check() {
	int flag = 0;
	int i = 0, temp = 1;
	for (i = 0; i < N - 1; i++) {
		if (line[i] != line[i + 1]) {
			flag = 1;
			break;
		}
		else {
			if (temp < X)temp++;
		}
	}
	if (flag == 0) {
		ans++;
		return;
	}
	//무조건 높이 다른놈들임
	for (i; i < N - 1; i++) {
		if (line[i] == line[i + 1]) {
			if (temp < X)temp++;
		}
		else if (line[i] == line[i + 1] - 1) {
			if (temp == X) {
				temp = 1;
			}
			else return;
		}
		else if (line[i] == line[i + 1] + 1) {
			if (i + X < N) {
				int tempnum = line[i + 1];
				for (int j = i + 1; j <= i + X; j++) {
					if (tempnum == line[j]) continue;
					else return;
				}
				temp = 0;//이자식,,,,,
				i = i + X - 1;
			}
			else return;
		}
		else if (line[i] >= line[i + 1] + 2 || line[i] + 2 <= line[i + 1])return;
	}
	ans++;
}
int main() {
	//freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d %d", &N, &X);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		ans = 0;
		for (int i = 0; i < N; i++) {
			putLine(1, i);
			check();
			putLine(0, i);
			check();
		}
		printf("#%d %d\n", test + 1, ans);
	}
	return 0;
}