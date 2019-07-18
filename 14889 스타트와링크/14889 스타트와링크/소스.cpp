#include<stdio.h>
int N, min = 212345689, start, link;
int arr[20][20], visited[20];
int abs(int a) {
	if (a < 0)return -1 * a;
	else return a;
}
void dfs(int d, int n) {
	if (d == N / 2) {
		start = link = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i] == 1 && visited[j] == 1) {
					start += arr[i][j];
				}
				else if (visited[i] == 0 && visited[j] == 0) {
					link += arr[i][j];
				}
			}
		}
		int temp = abs(link - start);
		if (temp < min) min = temp;
		return;
	}
	for (int i = n + 1; i < N; i++) {
		visited[i] = 1;
		dfs(d + 1, i);
		visited[i] = 0;
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	//Á¶ÇÕ
	for (int i = 0; i < N; i++) {
		visited[i] = 1;
		dfs(1, i);
		visited[i] = 0;
	}
	printf("%d\n", min);
	return 0;
}