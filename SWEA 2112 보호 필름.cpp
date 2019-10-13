#include <stdio.h>
int T, D, W, K, min, count;
int map[13][20], copy_map[13][20], visited[13];// , AorB[13];
typedef struct { int what; int ab; }AORB;
AORB AorB[13];
void copy() {
	for (int i = 0; i < D; i++) {
		for (int j = 0; j < W; j++) {
			copy_map[i][j] = map[i][j];
		}
	}
}
void input(int a, int cou) {
	for (int i = 0; i < W; i++) {
		copy_map[a][i] = cou;
	}
}
int search(int w) {
	for (int i = 0; i <= D - K; i++) {
		int start = copy_map[i][w];
		int flag = 0;
		for (int j = i + 1; j < i + K; j++) {
			if (start != copy_map[j][w]) {
				flag = 1;
				break;
			}
		}
		if (flag == 0)return 1;
	}
	return -1;
}
void choice(int d, int c) {
	if (d == c) {
		for (int i = 0; i < W; i++) {
			if (search(i) == -1)return;
		}
		if (min > c)min = c;
		return;
	}
	AorB[d].what = 0;
	input(AorB[d].ab, 0);
	choice(d + 1, c);
	AorB[d].what = 1;
	input(AorB[d].ab, 1);
	choice(d + 1, c);
}
void dfs(int d, int c) {//depth, 갯수
	
	if (c > K)return;
	//와 시발 이거 조건 미쳤나 시발 와 시간초과 통과함 와 시발 와;;;;;;
	
	
	
	if (d == D) {//visited[]==1이면 약물 투여 해 줘야함
		copy();
		choice(0, c);
		return;
	}
	visited[d] = 0;
	dfs(d + 1, c);
	visited[d] = 1;
	AorB[c].ab = d;
	dfs(d + 1, c + 1);
	AorB[c].ab = 0;
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d %d %d", &D, &W, &K);//K 통과기준
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		min = 2123456789;
		dfs(0, 0);
		printf("#%d %d\n", test + 1, min);
	}
	return 0;
}