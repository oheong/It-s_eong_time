#include <stdio.h>
int N, f = -1, r = -1;
typedef struct Queue { int x; };
Queue q[1000000];
void enQ(int x) {
	q[++r].x = x;
}
void deQ() { f++; }
Queue peek() { return q[f + 1]; }
int empty() {
	if (f == r)return 1;
	else return 0;
}
int main() {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) enQ(i);

	while (empty() == 0) {
		int tx = peek().x;
		if ((f + 1) % 2 == 0) {
			printf("%d ", tx);
		}
		else {
			enQ(tx);
		}
		deQ();
	}
	printf("\n");
	return 0;
}