#include <stdio.h>
int N;
char arr[21];
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d\n", &N);
	for (int n = 0; n < N * 3; n++) {
		if (n % 3 == 0)printf("#%d ", (n / 3) + 1);
		scanf("%s", arr);
		printf("%c", arr[0] - 32);
		if (n % 3 == 2)printf("\n");
	}
	return 0;
}