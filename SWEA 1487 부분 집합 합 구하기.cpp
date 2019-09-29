#include <stdio.h>
#define SIZE 65
int T, N, W, count;
int map[SIZE], visited[SIZE];
void dfs(int d, int sum) {
	if (sum == W) {
		count++;
		return;
	}
	else if (sum > W || d == N)return;
	visited[d] = 1;
	dfs(d + 1, sum + map[d]);
	visited[d] = 0;
	dfs(d + 1, sum);
}
int partition(int arr[], int left, int right) {
	int pivot = arr[left];
	int l = left, r = right;
	while (l < r) {
		while (pivot < arr[r])r--;
		while (arr[l] <= pivot && l < r)l++;
		int temp = arr[r];
		arr[r] = arr[l];
		arr[l] = temp;
	}
	//left = l;
	arr[left] = arr[l];//기억
	arr[l] = pivot;//기억
	return l;//기억 ㅅㅂ
}
void Qsort(int arr[], int left, int right) {
	if (left >= right)return;
	int pivot = partition(arr, left, right);
	Qsort(arr, left, pivot - 1);
	Qsort(arr, pivot + 1, right);
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d %d", &N, &W);
		for (int i = 0; i < N; i++) {
			scanf("%d", &map[i]);
		}
		count = 0;
		//정렬 함 해주고 dfs 돌리기

		Qsort(map, 0, N - 1);

		dfs(0, 0);

		printf("%d\n", count);
	}
	return 0;
}