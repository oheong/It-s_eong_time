#include <stdio.h>
int score[5][4];
int max = 0, max_who = 0;
int main() {
	freopen("Text.txt", "r", stdin);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d", &score[i][j]);
		}
	}

	for (int i = 0; i < 5; i++) {
		int temp = 0;
		for (int j = 0; j < 4; j++) {
			temp += score[i][j];
		}
		if (max < temp) {
			max = temp;
			max_who = i;
		}
	}
	printf("%d %d\n", max_who + 1, max);
	return 0;
}