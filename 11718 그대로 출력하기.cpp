#include <stdio.h>
char arr[105];
int i = -1;
char c;
int main() {
	freopen("Text.txt", "r", stdin);
	while (scanf("%c", &c) != EOF) {
		// scanf�� ���������� �о���� ������ ������ �����Ѵ�.
		// �б⵵ ���� ������ �߻��ϸ� EOF�� ���ϵȴ�.

		printf("%c", c);
	}
	return 0;
}
