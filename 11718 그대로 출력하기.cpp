#include <stdio.h>
char arr[105];
int i = -1;
char c;
int main() {
	freopen("Text.txt", "r", stdin);
	while (scanf("%c", &c) != EOF) {
		// scanf는 성공적으로 읽어들인 인자의 개수를 리턴한다.
		// 읽기도 전에 오류가 발생하면 EOF가 리턴된다.

		printf("%c", c);
	}
	return 0;
}
