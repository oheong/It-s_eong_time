#include <stdio.h>
int N, n;
int map[2][100];
int abs(int a) {
	if (a < 0)return -1 * a;
	else return a;
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &n);
		if (n < 0)
			map[0][abs(n)]++; // 음수
		else map[1][n]++;
	}
	scanf("%d", &n);
	if (n < 0)
		printf("%d\n", map[0][abs(n)]); // 음수
	else printf("%d\n", map[1][n]);

}