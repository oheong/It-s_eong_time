/*
Dynamic Programming : ������ ������� ������ ���� ���� ���Ŀ� ���
�ߺ��� ����� �������� ����� ����� �迭�� ������ ��, ������ ����� �ʿ��Ҷ��� ������ ���� �ҷ���.
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

//�ù� ������,,,,,������?