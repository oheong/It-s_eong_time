#include <stdio.h>
#define SIZE 100001
int N, K, f, r;
int visited[SIZE], bx[2] = { -1,1 };
int q[SIZE * 2];
void enQ(int x) { q[++r] = x; }
void deQ() { f++; }
int peek() { return q[f + 1]; }
int empty() {
	if (f == r)return 1;
	else return 0;
}
int bfs() {
	f = r = -1;
	enQ(N);
	visited[N] = 0;
	while (empty() == 0) {
		int tx = peek();
		deQ();
		if (tx == K)return visited[tx];

		int temp = tx * 2;
		while (temp < SIZE&&visited[temp] == -1) {
			visited[temp] = visited[tx];
			enQ(temp);
			temp *= 2;
		}

		for (int i = 0; i < 2; i++) {
			int nx = tx + bx[i];
			if (0 <= nx && nx < SIZE&&visited[nx] == -1) {
				enQ(nx);
				visited[nx] = visited[tx] + 1;
			}
		}
	}
	return 0;
}
int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < SIZE; i++)visited[i] = -1;
	printf("%d\n", bfs());
	return 0;
}