#include <stdio.h>
int N;
long A, B;
int main() {
	freopen("Text.txt", "r", stdin);

	scanf("%ld %ld", &A, &B);
	printf("%ld\n", A + B);

	/*scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &A, &B);
		printf("Case #%d: %d + %d = %d\n", i + 1, A, B, A + B);
	}*/

	/*while (1) {
		scanf("%d %d", &A, &B);
		if (A == 0 && B == 0)return 0;
		printf("%d\n", A + B);
		A = 0; B = 0;
	}*/
	return 0;
}