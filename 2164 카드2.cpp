#include <stdio.h>
#define SIZE 500000
int N, f = SIZE * 3, r = SIZE * 3, count;
int q[SIZE * 4];
void rear_enQ(int n) { q[++r] = n; }
void front_enQ(int n) { q[f--] = n; }
void front_deQ() { f++; }
void rear_deQ() { r--; }
int peek() { return q[r]; }
int empty() {
	if (r == f)return 1;
	else return 0;
}
void gogo() {
	while (1) {
		rear_deQ();
		count--;
		int t = peek();
		if (count == 1) {
			printf("%d\n", t);
			return;
		}
		rear_deQ();
		front_enQ(t);
	}
}
int main() {
	scanf("%d", &N);
	for (int i = N; 0 < i; i--) rear_enQ(i);
	count = N;
	if (N == 1) printf("%d\n", 1);
	else gogo();
	return 0;
}