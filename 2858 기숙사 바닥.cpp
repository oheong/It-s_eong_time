#include <stdio.h>
int R, B, L, W;
//답은 세로가 긴거
int is_right(int garo, int sero) {
	int sum = garo * 2 + sero * 2;
	if (R == sum + 4)return 1;
	else return 0;
}
void sibal() {
	for (int i = 1; i <= B; i++) {
		if (B%i == 0) {
			if (1 == is_right(B / i, i)) {
				printf("%d %d\n", B / i + 2, i + 2);
				return;
			}
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d", &R, &B);
	if (B == 0)printf("%d %d\n", R, 1);
	else sibal();
	return 0;
}