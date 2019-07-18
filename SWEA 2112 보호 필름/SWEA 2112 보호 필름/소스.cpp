#include <stdio.h>
int T, D, W, K, min;
int map[13][20], copymap[13][20], visited[13], count;
void copy() {
	for (int i = 0; i < W; i++) {
		for (int j = 0; j < D; j++) {
			copymap[i][j] = map[i][j];
		}
	}
}
void input(int a) {

}
int search() {//위에서 아래로 search
	for (int i = 0; i < W; i++) {
		for (int j = 0; j < D - K; j++) {
			for (int k = i; k < K; k++) {
				if (copymap[i][k] != copymap[i][k + 1])
					return 0;
			}
		}
	}
	return 1;
}
void dfs(int depth, int n) {
	if (depth > W)return;
	copy();




	
	for (int i = n; i < D; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			dfs(depth + 1, i);
			visited[i] = 0;
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 1; test <= T; test++) {
		scanf("%d %d %d", &D, &W, &K);//K 통과기준
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				scanf("%d", &map[i][j]);
			}
		}

		//search하기

		dfs(0, 0);

	}
	return 0;
}