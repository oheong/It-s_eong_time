#include <stdio.h>
char arr[105];
int i = -1;
int main() {
	//freopen("Text.txt", "r", stdin);
	do {
		i++;
		scanf("%c", &arr[i]);
	} while (arr[i] != '\0' || i < 101);

	printf("%s\n", arr);
}
