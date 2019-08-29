#include <stdio.h>
#define SIZE 33
int N;
long long ans;
int map[SIZE][SIZE], by[3] = { 0,1,1 }, bx[3] = { 1,1,0 };
long visited[SIZE][SIZE][3];
void gogo() {
	visited[0][1][0] = 1;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			for (int h = 0; h < 3; h++) {
				if (visited[y][x][h] > 0) {
					if (h == 0 && map[y + by[0]][x + bx[0]] == 0) {
						visited[y + by[0]][x + bx[0]][0] += visited[y][x][0];

						if (map[y + by[1]][x + bx[1]] == 0 && map[y + by[2]][x + bx[2]] == 0)
							visited[y + by[1]][x + bx[1]][1] += visited[y][x][0];
					}
					else if (h == 1) {
						if (map[y + by[0]][x + bx[0]] == 0)
							visited[y + by[0]][x + bx[0]][0] += visited[y][x][1];

						if (map[y + by[0]][x + bx[0]] == 0 && map[y + by[1]][x + bx[1]] == 0 && map[y + by[2]][x + bx[2]] == 0)
							visited[y + by[1]][x + bx[1]][1] += visited[y][x][1];

						if (map[y + by[2]][x + bx[2]] == 0)
							visited[y + by[2]][x + bx[2]][2] += visited[y][x][1];
					}
					else if (h == 2 && map[y + by[2]][x + bx[2]] == 0) {
						if (map[y + by[0]][x + bx[0]] == 0 && map[y + by[1]][x + bx[1]] == 0)
							visited[y + by[1]][x + bx[1]][1] += visited[y][x][2];

						visited[y + by[2]][x + bx[2]][2] += visited[y][x][2];
					}
				}
			}
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) {
				map[i][j] = -1;
			}
		}
	}
	gogo();
	for (int i = 0; i < 3; i++) ans += visited[N - 1][N - 1][i];

	printf("%lld\n", ans);
	return 0;
}