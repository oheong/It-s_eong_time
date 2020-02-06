#include<stdio.h>
int T, N, min = 2123456789;
int home_y, home_x, work_y, work_x;
typedef struct {
	int y; int x;
}MAP;
MAP map[10];
int visited[10];
int abs(int a) {
	if (a < 0)return -1 * a;
	else return a;
}
void dfs(int d, int y, int x, int distance) {
	if (d == N) {
		y = abs(y - home_y);
		x = abs(x - home_x);
		distance += (y + x);
		if (distance < min)min = distance;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (visited[i] == 0) {
			visited[i] = d + 1;
			dfs(d + 1, map[i].y, map[i].x, distance + abs(y - map[i].y) + abs(x - map[i].x));
			visited[i] = 0;
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d", &N);
		scanf("%d %d", &work_x, &work_y);
		scanf("%d %d", &home_x, &home_y);
		for (int i = 0; i < N; i++) {
			scanf("%d %d", &map[i].x, &map[i].y);
		}
		dfs(0, work_y, work_x, 0);
		//dfs(0);
		printf("#%d %d\n", test + 1, min);
		min = 2123456789;
	}
	return 0;
}