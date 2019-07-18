#include<stdio.h>
#define SIZE 50
int N, M, c, h, t, sum, min = 2123456789;
int visited[13];
typedef struct { int y; int x; }SPOT;
SPOT chicken[13], house[2 * SIZE];
int abs(int a) {
	if (a < 0)return -1 * a;
	else return a;
}
void dfs(int d, int n) {
	if (d > M) return;
	sum = 0;
	for (int i = 0; i < h; i++) {
		int tempmin = 2123456789;
		for (int j = 0; j < c; j++) {
			if (visited[j] == 1) {
				int a = abs(chicken[j].y - house[i].y) + abs(chicken[j].x - house[i].x);
				if (a < tempmin)tempmin = a;
			}
		}
		sum += tempmin;
	}
	if (min > sum)min = sum;
	for (int i = n + 1; i < c; i++) {
		visited[i] = 1;
		dfs(d + 1, i);
		visited[i] = 0;
	}
}
int main() {
	//freopen("Text.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &t);
			if (t == 2) {
				chicken[c].y = i;
				chicken[c++].x = j;
			}
			else if (t == 1) {
				house[h].y = i;
				house[h++].x = j;
			}
		}
	}

	for (int i = 0; i < c; i++) {
		visited[i] = 1;
		dfs(1, i);
		visited[i] = 0;
	}
	printf("%d\n", min);
	return 0;
}