#include <stdio.h>
#define SIZE 200
int T, N, K, M;
double max;
int map[SIZE], visited[SIZE];
void print() {
	for (int i = 0; i < N; i++) {
		printf("%d ", visited[i]);
	}
	printf("\n");
}
void dfs(int d, double level) {
	if (d == K) {
		//print();
		if (max < level)
			max = level;

		return;
	}
	for (int i = 0; i < N; i++) {
		if (visited[i] == 0 && level <= map[i]) {
			visited[i] = d + 1;
			dfs(d + 1, (level + map[i]) / 2);
			visited[i] = 0;
		}
	}
}
void sort() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1 - i; j++) {
			if (map[j] > map[j + 1]) {
				int temp = map[j];
				map[j] = map[j + 1];
				map[j + 1] = temp;
			}
		}
	}
}
double get_ans() {
	double ans = 0;
	for (int i = N - K; i < N; i++) {
		ans = (ans + map[i]) / 2;
	}
	return ans;
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d %d", &N, &K);
		for (int i = 0; i < N; i++) {
			scanf("%d", &map[i]);
		}
		//dfs(0, 0);
		sort();

		printf("#%d %f\n", test + 1, get_ans());

	}
	return 0;
}