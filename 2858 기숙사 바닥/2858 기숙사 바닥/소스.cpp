#include <stdio.h>
int R, B, L, W;
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d", &R, &B);
	L = 1;
	while (L < R + B) {
		W = (R + B - L) / 2;
		if (R + B == L * W && ((L - 2)*(W - 2) == B) && W * 2 + (L - 2) * 2 == R) {
			if (L > W)
				printf("%d %d\n", L, W);
			else
				printf("%d %d\n", W, L);
			break;
		}
		else L++;
	}
	return 0;
}