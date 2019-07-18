/*
Dynamic Programming : 이전의 결과값을 저장해 놓고 다음 계산식에 사용
중복된 계산을 막기위해 저장된 결과를 배열에 저장한 뒤, 다음에 계산이 필요할때는 저정된 값을 불러옴.
*/
#include <stdio.h>
int T, s, t, a, b, day;
int arr[];
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d %d %d %d", &s, &t, &a, &b);
		arr[0] = s + a;
		arr[1] = s * b;
		int i = 1;
		int j = 0;
		while (1) {
			arr[i * 2] = arr[j] + a;
			arr[i * 2 + 1] = arr[j] * b;
			if (arr[i * 2 + 1] > t || arr[i * 2] > t) {
				printf("#%d %d\n", test + 1, -1);
				break;
			}
			if (arr[i * 2] == t || arr[i * 2 + 1] == t) {
				printf("#%d %d\n", test + 1, i);
				break;
			}
			i++; j++;
		}
	}
	return 0;
}

//시발 도르신,,,,,ㅇㅅㅇ?