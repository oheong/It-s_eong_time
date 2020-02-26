#include<stdio.h>
#define SIZE 110
int N, S;
int map[SIZE];
void change(int who, int start) {
	if (who == 1) {
		//배수만 찾아서 바꾼다
		for (int i = start; i < N; i++) {
			if (i%start == 0) {
				map[i] = (map[i] + 1) % 2;
			}
		}
	}
	else {
		map[start] = (map[start] + 1) % 2;
		int left = start - 1, right = start + 1;
		while (1) {
			if (map[left] == map[right] && 1 <= left && right <= N) {
				map[left] = (map[left] + 1) % 2;
				map[right] = (map[right] + 1) % 2;
				left--;
				right++;
			}
			else break;
		}
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &map[i]);

	scanf("%d", &S);
	for (int i = 0; i < S; i++) {
		int gender, start;
		scanf("%d %d", &gender, &start);
		change(gender, start);
	}

	for (int i = 1; i <= N; i++) {
		if (i % 20 == 0)printf("%d\n",map[i]);
		else printf("%d ", map[i]);
	}
	return 0;
}
//19퍼