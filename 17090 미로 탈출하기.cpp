#include <stdio.h>
#define SIZE 502
int N, M, ans;
char map[SIZE][SIZE], temp[SIZE * 2];
int visited[SIZE][SIZE], by[4] = { -1,0,1,0 }, bx[4] = { 0,1,0,-1 };
int dir(char c) {
	if (c == 'U') return 0;
	if (c == 'R') return 1;
	if (c == 'D') return 2;
	return 3; // L
}
int dfs(int y, int x) {
	// visited == 0 ���� �Ȱ��� ���̴�.
	// vistied == 1 �ⱸ�� �ִ� ���̴�.
	// visited == 2 �ⱸ�� ���� ���̴�.
	if (y == 0 || y == N + 1 || x == 0 || x == M + 1)
		return 1;
	if (visited[y][x] != 0)return visited[y][x];

	visited[y][x] = 2;
	int i = dir(map[y][x]);
	int ny = y + by[i];
	int nx = x + bx[i];
	return visited[y][x] = dfs(ny, nx);

}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d\n", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%s", &temp);
		for (int j = 1; j <= M; j++) {
			map[i][j] = temp[j - 1];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			// �� �ڸ��� �ͺ�����
			if (visited[i][j] == 0)
				visited[i][j] = dfs(i, j);
			if (visited[i][j] == 1)ans++;
		}
	}

	printf("%d\n", ans);
	return 0;
}
// 87% �ð��ʰ� *4
// �ƴϹ̯h �ð� �쿡����?
// ���޳�,,,,?