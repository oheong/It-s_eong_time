#include <stdio.h>
#define SIZE 100001
int T, N, num, flag, f, r;
int map[SIZE], visited[SIZE];
int q[SIZE];
void enQ(int n) {
	q[++r] = n;
}
void deQ() { f++; }
int empty() {
	if (f == r)return 0;
	return 1;
}
int peek() { return q[f + 1]; }
int init() {
	int count = 0;
	for (int i = 1; i <= N; i++) {
		if (visited[i] <= 0) count++;
		visited[i] = 0;
	}
	return count;
}
void dfs(int num, int count) {
	visited[num] = count;
	enQ(num);

	if (visited[map[num]] != 0) {
		enQ(map[num]);

		return;
	}

	dfs(map[num], count);

}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &num);
			map[i] = num;
		}
		int count = 1;
		f = r = -1;
		for (int i = 1; i <= N; i++) {
			if (visited[i] != 0) continue;
			dfs(i, count++);

			while (empty() != 0) {
				if (peek() == q[r]) { // 싸이클 만들어짐
					f = r = -1;
				}
				else {
					visited[peek()] = -1;
					deQ();
				}
			}
		}
		printf("%d\n", init());
	}
	return 0;
}

// 82% 시간초과