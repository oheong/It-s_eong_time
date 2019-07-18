#include <stdio.h>
int N, max = 0;
typedef struct { int v; int c; }V;
V visited[101];
int arr[101], lastarr[101];
void dfs(int d, int sp, int n) {
	if (d == n) {
		int count = 0;
		for (int i = 1; i <= N; i++) {
			if (visited[i].v == 1 && visited[arr[i]].c == 0) {
				visited[arr[i]].c = 1;
			}
		}
		for (int i = 1; i <= N; i++) {
			if (visited[i].v == 1 && visited[i].c == 1) {
				count++;
			}
			else if (visited[i].v == 1 && visited[i].c == 0) {
				count = 0;
				break;
			}
		}
		if (max < count) {
			for (int i = 1; i <= N; i++) {
				lastarr[i] = 0;
				if (visited[i].c == 1)
					lastarr[i] = 1;
			}
			max = count;
		}
		for (int i = 1; i <= N; i++) visited[i].c = 0;
		return;
	}
	for (int i = sp + 1; i <= N; i++) {
		if (visited[i].v == 0) {
			visited[i].v = 1;
			dfs(d + 1, i, n);
			visited[i].v = 0;
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}
	for (int j = 1; j <= N; j++) {//골라야하는 숫자의 갯수
		for (int i = 1; i <= N; i++) {//시작 포인터
			if (visited[i].v == 0) {
				visited[i].v = 1;
				dfs(1, i, j);
				visited[i].v = 0;
			}
		}
	}

	printf("%d\n", max);
	for (int i = 1; i <= N; i++) {
		if (lastarr[i] == 1)printf("%d\n", i);
	}
	return 0;
}