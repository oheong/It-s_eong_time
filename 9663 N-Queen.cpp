#include <stdio.h>
int N;
int map[15][15];
int count = 0;
int is_ok(int d, int line) {
	// ���� ���� ���ο� 1�� �ִ���?
	for (int i = d - 1; 0 <= i; i--) {
		if (map[i][line] == 1)return 0;
	}
	//�¿�� ���� ���� �ִ���?
	//for (int j = 0; j < N; j++) {
	//	if (map[d][j] == 1)return 0;
	//}
	// ���� ���� 1�� �ִ���?
	for (int i = d, j = line; 0 <= i && 0 <= j; i--, j--) {
		if (map[i][j] == 1)return 0;
	}
	// ������ ���� 1�� �ִ���?
	for (int i = d, j = line; 0 <= i && j < N; i--, j++) {
		if (map[i][j] == 1)return 0;
	}
	return 1;
}
void dfs(int d) {
	if (d == N) {
		count++;
		printf("%d\n", count);
		return;
	}
	for (int i = 0; i < N; i++) {
		if (is_ok(d, i) == 1) {
			map[d][i] = 1;
			dfs(d + 1);
			map[d][i] = 0;
		}
	}
}
int main() {
	scanf("%d", &N);
	dfs(0);
	printf("%d\n", count);
	return 0;
}