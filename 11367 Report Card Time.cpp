#include <stdio.h>
int N;
char map[15];
void score(int num) {
	if (97 <= num && num <= 100) printf("A+\n");
	else if (90 <= num && num <= 96) printf("A\n");
	else if (87 <= num && num <= 89) printf("B+\n");
	else if (80 <= num && num <= 86) printf("B\n");
	else if (77 <= num && num <= 79) printf("C+\n");
	else if (70 <= num && num <= 76) printf("C\n");
	else if (67 <= num && num <= 69) printf("D+\n");
	else if (60 <= num && num <= 66) printf("D\n");
	else printf("F\n");
}
int main() {
	scanf("%d\n", &N);
	for (int i = 0; i < N; i++) {
		int count = 0;
		int num = 0;
		while (1) {
			char c;
			scanf("%c", &c);
			if (c == '\n')
				break;
			else if ('0' <= c && c <= '9') {
				// 점수
				if (count == 0) {
					num = c - '0';
					count++;
				}
				else {
					num *= 10;
					num += c - '0';
				}
			}
			else {
				// 이름
				printf("%c", c);
			}
		}
		score(num);
	}
	return 0;
}