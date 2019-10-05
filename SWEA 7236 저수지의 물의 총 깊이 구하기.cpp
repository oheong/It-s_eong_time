#include <stdio.h>
#define SIZE 101
int T, N;
char map[SIZE][SIZE];
int by[8] = { -1,-1,0,1,1,1,0,-1 }, bx[8] = { 0,1,1,1,0,-1,-1,-1 };
int count(int y, int x) {
	int sum = 1;
	for (int i = 0; i < 8; i++) {
		if (map[y + by[i]][x + bx[i]] == 'W')sum++;
	}
	if (sum == 1)return 1;
	else return sum - 1;
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d\n", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d\n", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%c ", &map[i][j]);
			}
		}
		int max = 0;
		for (int i = 1; i < N - 1; i++) {
			for (int j = 1; j < N - 1; j++) {
				if (map[i][j] == 'W') {
					int temp = count(i, j);
					//printf("%d %d %d\n", i, j, temp);
					if (temp > max)max = temp;
				}
			}
		}
		printf("#%d %d\n", test + 1, max);
	}
	return 0;
}