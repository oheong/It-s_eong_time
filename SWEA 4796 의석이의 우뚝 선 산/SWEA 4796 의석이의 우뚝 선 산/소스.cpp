#include <stdio.h>
#define SIZE 50000
int T, N, sp, ep, max, mp, count, up, down;
int mountain[SIZE], visited[SIZE];
int flag = 0;
//int getmountain(int s, int e) {
//	max = 0;
//	for (int i = s + 1; i < e; i++) {
//		if (mountain[i] > max) {
//			max = mountain[i];
//			mp = i;
//		}
//	}
//	for (int i = mp; s < i; i--) {
//		//갈수록 작아져야함. 중간에 큰거하나라도있으면 reutrn false
//		if (mountain[i - 1] > mountain[i]) return 0;
//	}
//	for (int i = mp; i < e; i++) {
//		//갈수록 작아져야함ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅇㅇ
//		if (mountain[i] < mountain[i + 1]) return 0;
//	}
//	return 1;
//}
//void dfs(int d, int n) {
//	if (d == 2) {
//		if (getmountain(sp, ep) == 1) {
//			//printf("%d %d\n", sp + 1, ep + 1);
//			count++;
//		}
//		return;
//	}
//	for (int i = n + 2; i < N; i++) {
//		if (visited[i] == 0) {
//			visited[i] = 1;
//			ep = i;
//			dfs(d + 1, i);
//			visited[i] = 0;
//		}
//	}
//}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) scanf("%d", &mountain[i]);
		//for (int i = 0; i < N - 2; i++) {
		//	visited[i] = 1;
		//	sp = i;
		//	dfs(1, i);
		//	visited[i] = 0;
		//}
		up = down = 0;
		for (int i = 0; i < N - 1; i++) {
			if (mountain[i] < mountain[i + 1]) {
				if (flag == 1 || i == N - 1) {
					count += up * down;
					up = 1;
					down = 0;
					flag = 0;
				}
				else if (flag == 0) {
					up++;
				}
			}
			else if (mountain[i] > mountain[i + 1]) {
				down++;
				flag = 1;
				if (i + 1 == N - 1) {
					count += up * down;
				}
			}
		}
		printf("#%d %d\n", test + 1, count);
		count = 0;
	}
	return 0;
}