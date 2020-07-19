#include <stdio.h>
#define SIZE 1000001
int N;
long long map[SIZE];
int main() {
	scanf("%d", &N);

	map[0] = 0;
	map[1] = 1;

	for (int i = 2; i <= N; i++) {
		map[i] = map[i - 1] % 1000000007 + map[i - 2] % 1000000007;
	}

	printf("%ld\n", map[N] % 1000000007);

	return 0;
}