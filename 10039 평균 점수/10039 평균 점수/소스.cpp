#include <stdio.h>
int map[5], sum;
int main() {
	for (int i = 0; i < 5; i++) {
		scanf("%d", &map[i]);
		if (map[i] < 40) sum += 40;
		else sum += map[i];
	}
	printf("%d\n", sum / 5);
	return 0;
}