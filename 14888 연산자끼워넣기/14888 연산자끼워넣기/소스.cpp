#include <stdio.h>
int N, min = 2123456789, max = -2123456789, count;//와 미친 max범위도 생각해줘야함;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;도르신
int num[11], temp[4], calc[10], visited[10];

void dfs(int d) {
	if (d == N - 1) {
		//계산하기
		int value = num[0];
		for (int i = 0; i < N - 1; i++) {
			int c = calc[visited[i] - 1];
			if (c == 1) {
				value += num[i + 1];
			}
			else if (c == 2) {
				value -= num[i + 1];
			}
			else if (c == 3) {
				value *= num[i + 1];
			}
			else {
				value /= num[i + 1];
			}
		}
		if (value < min)min = value;
		if (value > max)max = value;
		return;
	}
	for (int i = 0; i < N - 1; i++) {
		if (visited[i] == 0) {
			visited[i] = d + 1;
			dfs(d + 1);
			visited[i] = 0;
		}
	}
}
int main() {
	//freopen("Text.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &num[i]);
	for (int i = 0; i < 4; i++) scanf("%d", &temp[i]);// + - * /

	for (int i = 0; i < 4; i++) {
		if (temp[i] == 0)continue;
		else if (1 < temp[i]) {
			for (int j = 0; j < temp[i]; j++) {
				calc[count++] = i + 1;
			}
		}
		else
			calc[count++] = i + 1;
	}
	for (int i = 0; i < N - 1; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			dfs(1);
			visited[i] = 0;
		}
	}
	printf("%d\n%d\n", max, min);
	return 0;
}