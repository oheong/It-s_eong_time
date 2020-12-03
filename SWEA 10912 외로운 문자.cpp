#include <stdio.h>
int T, alpha[27];
char text[110];
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d\n", &T);
	for (int test = 0;test < T;test++) {
		scanf("%s", &text);
		int num = 0;
		while (1) {
			if (97 > text[num] || text[num] > 122) break;
			if (alpha[text[num] - 97] == 0)
				alpha[text[num] - 97] = 1;
			else
				alpha[text[num] - 97] = 0;
			num++;
		}
		printf("#%d ", test + 1);
		int flag = 0;
		for (int i = 0;i < 27;i++) {
			if (alpha[i] != 0) {
				flag = 1;
				printf("%c", char(i + 97));
				alpha[i] = 0;
			}
		}
		if (flag == 0)
			printf("Good");
		printf("\n");
	}
	return 0;
}