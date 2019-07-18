/* 순열 */
#include <stdio.h>
int N, max = -2123456789, min = 2123456789, count;
int arr[100], math[4], calc[100], visited[100];
void dfs(int d) {
	if (d == N - 1) {
		//계산하기
		int temp = arr[0];
		for (int i = 0; i < N - 1; i++) {
			int t = visited[i] - 1;
			if (calc[t] == 1) {
				//더하기
				temp += arr[i + 1];
			}
			else if (calc[t] == 2) {
				//빼기
				temp -= arr[i + 1];
			}
			else if (calc[t] == 3) {
				//곱하기
				temp *= arr[i + 1];
			}
			else if (calc[t] == 4) {
				//나누기
				temp /= arr[i + 1];
			}
		}
		if (temp < min)min = temp;
		if (temp > max)max = temp;
		return;
	}
	for (int i = 0; i < count; i++) {
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
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d %d %d %d", &math[0], &math[1], &math[2], &math[3]);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < math[i]; j++) {
			calc[count++] = i + 1;
		}
	}
	dfs(0);
	printf("%d\n%d\n", max, min);
	return 0;
}