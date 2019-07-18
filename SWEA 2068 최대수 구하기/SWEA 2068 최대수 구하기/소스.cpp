#include <stdio.h>
int T, max;
int arr[10];
int main() {
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		max = 0;
		for (int i = 0; i < 10; i++) {
			scanf("%d", &arr[i]);
			if (arr[i] > max)max = arr[i];
		}
		printf("#%d %d\n", test + 1, max);
	}
	return 0;
}