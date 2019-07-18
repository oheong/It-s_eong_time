#include <stdio.h>
#define SIZE 101
int T, N, K, M, X, Y, count;
int map[SIZE][SIZE], visited[SIZE];
void init() {
	count = 0;
	for (int i = 1; i <= N; i++) {
		visited[i] = 0;
		for (int j = 1; j <= N; j++) {
			map[i][j] = 0;
		}
	}
}
void search(int d, int s) {
	if (d >= N) {
		return;
	}
	for (int e = 2; e <= N; e++) {
		if (map[s][e] == 1 && visited[e] == 0) {
			if (e == 2) {
				count++;
				if (count >= K) return;
				return;
			}
			visited[e] = 1;
			search(d + 1, e);
		}
	}
}
int main() {
	//freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d %d %d", &K, &N, &M);
		for (int i = 0; i < M; i++) {
			scanf("%d %d", &X, &Y);
			map[X][Y] = 1;
		}
		visited[1] = 1;
		for (int e = 2; e <= N; e++) {
			if (map[1][e] == 1 && visited[e] == 0) {
				if (e == 2) {
					count++;
					continue;
				}
				visited[e] = 1;
				search(1, e);
			}
		}
		if (count >= K)printf("#%d YES\n", test + 1);
		else printf("#%d NO\n", test + 1);
		init();
	}
	return 0;
}


/*
뭔 런타임에러임 ㅅㅂ;;;;돌았니
*/