#include <stdio.h>
int N;
int visited[8];
int get_num(int d) {
	int sum = visited[0];
	for (int i = 1; i <= d; i++) {
		sum *= 10;
		sum += visited[i];
	}
	return sum;
}
int is_sosu(int num) {
	if (num == 1) return -1;
	if (num == 2) return 1;
	for (int i = 2; i < num; i++) {
		if (num%i == 0) return -1;
	}
	return 1;
}
void dfs(int d) {
	if (d == N) {
		// 마지막 숫자가 소수이면 프린트하고 return;
		int temp = get_num(d - 1);
		if (is_sosu(temp))printf("%d\n", temp);
		return;
	}
	for (int i = 1; i < 10; i++) {
		visited[d] = i;
		if (is_sosu(get_num(d)) == 1) {
			dfs(d + 1);
		}
	}
}
int main() {
	scanf("%d", &N);
	dfs(0);
	return 0;
}