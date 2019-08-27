#include <stdio.h>
int flag;
int arr[9], visited[9], sort_arr[7];
void sort() {
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 6 - i; j++) {
			if (sort_arr[j] > sort_arr[j + 1]) {
				int t = sort_arr[j];
				sort_arr[j] = sort_arr[j + 1];
				sort_arr[j + 1] = t;
			}
		}
	}
}
void dfs(int d, int n) {
	if (d == 7) {
		int sum = 0;
		int a = 0;
		for (int i = 0; i < 9; i++) {
			if (visited[i] == 1) {
				sum += arr[i];
				sort_arr[a++] = arr[i];
			}
		}
		if (sum == 100 && flag == 0) {
			flag = 1;
			sort();
			for (int i = 0; i < 7; i++) {
				printf("%d\n", sort_arr[i]);
			}
			return;
		}
		return;
	}
	for (int i = n; i < 9; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			dfs(d + 1, i);
			visited[i] = 0;
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	for (int i = 0; i < 9; i++) {
		scanf("%d", &arr[i]);
	}
	dfs(0, 0);

	return 0;
}