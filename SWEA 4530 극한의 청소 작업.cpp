#include <stdio.h>
#include <math.h>
#define SIZE 12
int T;
long long four[SIZE], A, B, ans;
int a_int[SIZE], b_int[SIZE];
long long abs(long long a) {
	if (a < 0) return -1 * a;
	else return a;
}
int get_len(long long num) {
	int count = 0;
	while (0 < num) {
		count++;
		num /= 10;
	}
	return count;
}
void to_arr(int arr[], int len, long long num) {
	for (int i = len - 1; 0 <= i; i--) {
		arr[i] = num % 10;
		num /= 10;
	}
}
long long step(int arr[], int len) {
	long long sum = 0;
	for (int i = 0; i < len; i++) {
		int temp_num = arr[len - i - 1];
		if (4 < temp_num)temp_num--;
		sum += four[i] * temp_num;
	}
	return sum;
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);

	four[0] = 1;
	for (int i = 1; i < SIZE; i++) {
		four[i] = four[i - 1] * 9;
	}

	for (int test = 0; test < T; test++) {
		scanf("%lld %lld", &A, &B);

		int a_len = get_len(abs(A));
		int b_len = get_len(abs(B));
		//	printf("%d %d\n", a_len, b_len);

		to_arr(a_int, a_len, abs(A));
		to_arr(b_int, b_len, abs(B));

		long long start = step(a_int, a_len);
		long long end = step(b_int, b_len);

		if (A < 0 && 0 < B) ans = start + end - 1;
		else ans = abs(end - start);


		printf("#%d %lld\n", test + 1, ans);
	}
	return 0;
}