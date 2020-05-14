#include <stdio.h>

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	int count = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d", count++);
			if (j != M - 1)
				printf(" ");
		}printf("\n");
	}
	return 0;
}