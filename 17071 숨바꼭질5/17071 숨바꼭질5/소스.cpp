#include <stdio.h>
/*
¸øÇÏ°Ù¼­ ¾ÈÇÒ·¡ µfµf
*/
#define SIZE 500000
int N, K, sb, t, sis, temp, q;
int subin[SIZE * 3], visited[SIZE], nx[3] = { 1,-1,2 };
int main() {
	scanf("%d %d", &N, &K);
	visited[N] = 1;
	subin[sb++] = N;
	while (1) {
		sis = K + (t*t + t) / 2;
		for (int j = t; j < sb; j++) {
			for (int i = 0; i < 3; i++) {
				if (i == 2) {
					temp = subin[j] * nx[2];
				}
				else {
					temp = subin[j] + nx[i];
					if (temp < 0) continue;
				}
				if (temp > 500000) {
					printf("%d\n", -1);
					return 0;
				}
				if (visited[temp] == 0) {
					visited[temp] = 1;
					subin[sb++] = temp;
				}
			}
			for (int i = t; i < sb; i++) {
				if (subin[i] == sis) {
					printf("%d\n", t);
					return 0;
				}
			}
			t++;
		}/*
		t++;
		q = sb;*/

	}
	return 0;
}