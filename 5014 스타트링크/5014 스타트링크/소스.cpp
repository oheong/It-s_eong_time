#include <stdio.h>
#define SIZE 1000005
int F, S, G, f = -1, r = -1, count, min = 1e10;
int visited[SIZE], bx[2], minimum[SIZE * 2];
typedef struct { int x1; int step; }Queue;
Queue q[SIZE * 2];
void enQ(int x1, int step) {
	r++;
	q[r].x1 = x1;
	q[r].step = step;
}
void deQ() { f++; }
Queue peek() { return q[f + 1]; }
int empty() {
	if (f == r)return 1;
	else return 0;
}
void bfs(int x) {
	enQ(x, 0);
	visited[x] = 1;
	while (empty() == 0) {
		int tx = peek().x1;
		int tstep = peek().step;
		if (tx == G) {
			//minimum[count++] = tstep + 1;
			printf("%d\n", tstep + 1);
			return;
		}
		deQ();
		for (int i = 0; i < 2; i++) {
			int nx = tx + bx[i];
			if (0 < nx && nx <= F && visited[nx] == 0) {
				enQ(nx, tstep + 1);
				visited[nx] = 1;
			}
		}
	}
	printf("use the stairs\n");
}
int main() {
	//freopen("Text.txt", "r", stdin);
	scanf("%d %d %d %d %d", &F, &S, &G, &bx[0], &bx[1]);
	if (S == G) printf("%d\n", 0);//같은층으로 이동할때는 0 출력해야함.
	else {
		bfs(S);
		//if (count == 0)printf("use the stairs\n");
		//else {
		//	for (int i = 0; i < count; i++) {
		//		if (minimum[i] < min)min = minimum[i];
		//	}
		//	printf("%d\n", min);
		//}
	}
	return 0;
}

//시발 뭐가틀림??????????????????????ㅆㅂ

//시팔 뭐가틀렸단말임