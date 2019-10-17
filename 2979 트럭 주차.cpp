#include <stdio.h>
int A, B, C, max, ans;
int map[3][101];
int main() {
	int a, b;
	freopen("Text.txt", "r", stdin);
	scanf("%d %d %d", &A, &B, &C);
	for (int i = 0; i < 3; i++) {
		scanf("%d %d", &a, &b);
		b--;
		if (max < a)max = a;
		if (max < b)max = b;
		for (int j = a; j <= b; j++) map[i][j] = 1;
	}
	for (int j = 1; j <= max; j++) {
		int count = 0;
		for (int i = 0; i < 3; i++) if (map[i][j] == 1)count++;
		if (count == 0)continue;
		else if (count == 1) ans += A;
		else if (count == 2) ans += count * B;
		else if (count == 3) ans += count * C;
	}
	printf("%d\n", ans);
	return 0;
}