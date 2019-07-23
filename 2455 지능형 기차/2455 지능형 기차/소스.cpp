#include <stdio.h>
int a, b, max;
int main() {
	int temp = 0, count = 0;
	do {
		scanf("%d %d", &a, &b);
		if (count == 0) {
			temp = a + b;
			count++;
		}
		else {
			temp -= a;
			temp += b;
			if (max < temp)max = temp;
		}
	} while (b != 0);
	printf("%d\n", max);
	return 0;
}