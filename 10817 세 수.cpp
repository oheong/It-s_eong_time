#include <stdio.h>
int map[3];
int main() {
	for (int i = 0; i < 3; i++) {
		scanf("%d", &map[i]);
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3 - i - 1; j++) {
			if (map[j] > map[j + 1]) {
				int temp = map[j];
				map[j] = map[j + 1];
				map[j + 1] = temp;
			}
		}
	}
	printf("%d\n", map[1]);
	return 0;
}