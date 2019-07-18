#include <stdio.h>
int N, W, H;
int map[100];
int main() {
	scanf("%d %d %d", &N, &W, &H);//던진 성냥 갯수, 박스의 크기
	for (int i = 0; i < N; i++) {
		scanf("%d", &map[i]);
	}
	int a, b;
	if (W < H) {
		a = W; b = H;
	}
	else {
		a = H; b = W;
	}
	for (int i = 0; i < N; i++) {
		if (0 <= map[i] && map[i] * map[i] <= a * a + b * b)printf("DA\n");
		else printf("NE\n");
	}
	return 0;
}