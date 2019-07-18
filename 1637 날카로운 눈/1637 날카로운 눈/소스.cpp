#include <stdio.h>
int N, A, B, C, count, max, search_count;
typedef struct { int a; int b; int c; }NUMBER;
NUMBER num[2000];
bool fx(int x) {
	count = 0;
	for (int i = 0; i < N; i++) {
		if (num[i].a <= x) {
			search_count = 0;
			for (int k = 0; num[i].a + k * num[i].b <= x; k++) {
				count++;
				search_count++;
			}
		}
	}
	if (count % 2 == 1) return true;
	else return false;
}
int search(int n) {
	//여기서 홀수개있는 숫자가 뭔지, 몇개있는지 색출
	int how_many = 0;
	for (int i = 0; i < N; i++) {//ㅇㅇ무조건있어야댬.
		if (num[i].a <= n) {
			for (int k = 0; num[i].a + k * num[i].b <= n; k++) {
				if (num[i].a + k * num[i].b == n) {
					how_many++;
					break;
				}
			}
		}
	}
	return how_many;
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &A, &C, &B);
		num[i].a = A;
		num[i].b = B;
		num[i].c = C;
		if (max < num[i].c) max = num[i].c;
	}
	for (int x = 0; x <= max; x++) {
		if (fx(x) == true) {// 홀수개 있음
			//printf("%d %d\n", x, search(x));
			printf("%d %d\n", x, --search_count);
			return 0;
		}
	}
	printf("NOTHING\n");
	return 0;
}

//2147483647

//2% 3초 에서 졸라멈추네 시벌