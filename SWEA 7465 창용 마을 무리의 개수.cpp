// 유니온파인드
#include <stdio.h>
int T, N, M;
int map[101];
void setting() {
	for (int i = 1; i <= N; i++) {
		map[i] = i;
	}
}
int findSet(int x) { // x의 최고대장이 누군지?
	if (x == map[x]) return x;
	else return map[x] = findSet(map[x]);
}
void unionFind(int daejang, int jjol) {
	daejang = findSet(daejang);
	jjol = findSet(jjol);
	if (daejang == jjol) return;
	map[jjol] = daejang;
}
int ans() {
	int count = 0;
	for (int i = 1; i <= N; i++) {
		if (map[i] == i)count++;
	}
	return count;
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d %d", &N, &M);
		setting();
		for (int i = 0; i < M; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			unionFind(a, b);
		}
		printf("#%d %d\n", test + 1, ans());
	}
	return 0;
}