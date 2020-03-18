#include <stdio.h>
int T;
int arr1[20], arr2[20];
long long A, B;
long long pow(int num) {
	if (num == 0)return 1;
	else if (num == 1)return 10;
	else if (num == 2)return 100;
	else if (num == 3)return 1000;
	else if (num == 4)return 10000;
	else if (num == 5)return 100000;
	else if (num == 6)return 1000000;
	else if (num == 7)return 10000000;
	else if (num == 8)return 100000000;
	else if (num == 9)return 1000000000;
	else if (num == 10)return 10000000000;
	else if (num == 11)return 100000000000;
	else if (num == 12)return 1000000000000;
	else if (num == 13)return 10000000000000;
	else if (num == 14)return 100000000000000;
	else if (num == 15)return 1000000000000000;
}
void init() {
	for (int i = 0; i < 20; i++) {
		arr1[i] = 0;
		arr2[i] = 0;
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%lld %lld", &A, &B);
		if (0 < A)A--;
		int index1 = 0, index2 = 0;
		while (A > 0) {
			arr1[index1++] = A % 10;
			A /= 10;
		}
		while (B > 0) {
			arr2[index2++] = B % 10;
			B /= 10;
		}

		int count1 = 0, count2 = 0;
		int cur_num = 0; // 계산중인 자리수(일의자리 제외)
		long long result1 = 0, result2 = 0;

		for (int i = index1 - 1; 0 < i; i--) {
			cur_num = arr1[i];
			result1 += 45 * i*pow(i - 1)*cur_num;
			result1 += ((cur_num*(cur_num - 1)) / 2)*pow(i);
			result1 += count1 * cur_num*pow(i);
			count1 += cur_num;
		}
		cur_num = arr1[0];
		result1 += count1 * (cur_num + 1);
		result1 += (cur_num)*(cur_num + 1) / 2;


		for (int i = index2 - 1; 0 < i; i--) {
			cur_num = arr2[i];
			result2 += 45 * i*pow(i - 1)*cur_num;
			result2 += ((cur_num*(cur_num - 1)) / 2)*pow(i);
			result2 += count2 * cur_num*pow(i);
			count2 += cur_num;
		}
		cur_num = arr2[0];
		result2 += count2 * (cur_num + 1);
		result2 += (cur_num)*(cur_num + 1) / 2;

		printf("#%d %lld\n", test + 1, result2 - result1);
		init();
	}
	return 0;
}