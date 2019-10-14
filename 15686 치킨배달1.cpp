#include <stdio.h>
#define MAX_M 13
#define SIZE 50
int N, M, house_count, chicken_count, ans_min = 2123456789;
int map[SIZE][SIZE];
typedef struct { int y; int x; int visited; }ARR;
ARR house[2 * MAX_M], chicken[MAX_M];
int abs(int a) {
	if (a < 0)return -1 * a;
	else return a;
}
void dfs(int d, int n) {
	if (d == M) {
		int sum = 0;
		for (int h = 0; h < house_count; h++) {
			int h_y = house[h].y;
			int h_x = house[h].x;
			int min = 2123456789;
			for (int c = 0; c < chicken_count; c++) {
				if (chicken[c].visited == 0)continue;
				int temp = abs(h_y - chicken[c].y) + abs(h_x - chicken[c].x);
				if (min > temp) min = temp;
			}
			sum += min;
		}
		if (ans_min > sum)ans_min = sum;
		return;
	}
	for (int i = n; i < chicken_count; i++) {
		if (chicken[i].visited == 0) {
			chicken[i].visited = 1;
			dfs(d + 1, i);
			chicken[i].visited = 0;
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) {
				house[house_count].y = i;
				house[house_count++].x = j;
			}
			else if (map[i][j] == 2) {
				chicken[chicken_count].y = i;
				chicken[chicken_count++].x = j;
			}
		}
	}
	dfs(0, 0);
	printf("%d\n", ans_min);
	return 0;
}