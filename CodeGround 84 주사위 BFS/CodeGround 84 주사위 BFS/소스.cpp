#include <stdio.h>
int min = 2123456789, T, f = -1, r = -1, fx, fy, topy, topx;
int A, B, C, D, E, F, N, M, aa, bb, cc, dd;
int getnum[3][4], arr[6], visited[2][100][7][7], by[4] = { 0,1,0,-1 }, bx[4] = { 1,0,-1,0 };
typedef struct { int y; int x; int front; int top; int back; int down; int left; int right; int step; }Queue;
int nfront, ntop, nback, ndown, nleft, nright;
Queue q[100000];
void enQ(int y, int x, int front, int top, int back, int down, int left, int right, int step) {
	r++; q[r].y = y;
	q[r].x = x;
	q[r].front = front;
	q[r].top = top;
	q[r].back = back;
	q[r].down = down;
	q[r].left = left;
	q[r].right = right;
	q[r].step = step;
}
void deQ() { f++; }
Queue peek() { return q[f + 1]; }
void init() {
	for (int i = 0; i < 6; i++)arr[i] = 0;
	min = 2123456789;
	f = r = -1;
	for (int i = 0; i < M; i++) {
		for (int j = 1; j < 7; j++) {
			for (int n = 1; n < 7; n++) {
				visited[0][i][j][n] = 0;
				visited[1][i][j][n] = 0;
			}
		}
	}
}
int empty() {
	if (r == f)return 1;
	else return 0;
}
void make_square(int a, int b, int c, int d, int e, int f, int in_f, int in_t) {
	//front, top, right, back, down, left
	if (in_f == a) {
		if (in_t == b) {
			arr[0] = a; arr[1] = b; arr[2] = f; arr[3] = c; arr[4] = e; arr[5] = d;
		}
		else if (in_t == d) {
			arr[0] = a; arr[1] = d; arr[2] = b; arr[3] = c; arr[4] = f; arr[5] = e;
		}
		else if (in_t == e) {
			arr[0] = a; arr[1] = e; arr[2] = d; arr[3] = c; arr[4] = b; arr[5] = f;
		}
		else if (in_t == f) {
			arr[0] = a; arr[1] = f; arr[2] = e; arr[3] = c; arr[4] = d; arr[5] = b;
		}
	}
	else if (in_f == b) {
		if (in_t == a) {
			arr[0] = b; arr[1] = a; arr[2] = d; arr[3] = e; arr[4] = c; arr[5] = f;
		}
		else if (in_t == c) {
			arr[0] = b; arr[1] = c; arr[2] = f; arr[3] = e; arr[4] = a; arr[5] = d;
		}
		else if (in_t == d) {
			arr[0] = b; arr[1] = d; arr[2] = c; arr[3] = e; arr[4] = f; arr[5] = a;
		}
		else if (in_t == f) {
			arr[0] = b; arr[1] = f; arr[2] = a; arr[3] = e; arr[4] = d; arr[5] = c;
		}
	}
	else if (in_f == c) {
		if (in_t == b) {
			arr[0] = c; arr[1] = b; arr[2] = d; arr[3] = a; arr[4] = e; arr[5] = f;
		}
		else if (in_t == d) {
			arr[0] = c; arr[1] = d; arr[2] = e; arr[3] = a; arr[4] = f; arr[5] = b;
		}
		else if (in_t == e) {
			arr[0] = c; arr[1] = e; arr[2] = f; arr[3] = a; arr[4] = b; arr[5] = d;
		}
		else if (in_t == f) {
			arr[0] = c; arr[1] = f; arr[2] = b; arr[3] = a; arr[4] = d; arr[5] = e;
		}
	}
	else if (in_f == d) {
		if (in_t == a) {
			arr[0] = d; arr[1] = a; arr[2] = e; arr[3] = f; arr[4] = c; arr[5] = b;
		}
		else if (in_t == b) {
			arr[0] = d; arr[1] = b; arr[2] = a; arr[3] = f; arr[4] = e; arr[5] = c;
		}
		else if (in_t == c) {
			arr[0] = d; arr[1] = c; arr[2] = b; arr[3] = f; arr[4] = a; arr[5] = e;
		}
		else if (in_t == e) {
			arr[0] = d; arr[1] = e; arr[2] = c; arr[3] = f; arr[4] = b; arr[5] = a;
		}
	}
	else if (in_f == e) {
		if (in_t == a) {
			arr[0] = e; arr[1] = a; arr[2] = f; arr[3] = b; arr[4] = c; arr[5] = d;
		}
		else if (in_t == c) {
			arr[0] = e; arr[1] = c; arr[2] = d; arr[3] = b; arr[4] = a; arr[5] = f;
		}
		else if (in_t == d) {
			arr[0] = e; arr[1] = d; arr[2] = a; arr[3] = b; arr[4] = f; arr[5] = c;
		}
		else if (in_t == f) {
			arr[0] = e; arr[1] = f; arr[2] = c; arr[3] = b; arr[4] = d; arr[5] = a;
		}
	}
	else if (in_f == f) {
		if (in_t == a) {
			arr[0] = f; arr[1] = a; arr[2] = b; arr[3] = d; arr[4] = c; arr[5] = e;
		}
		else if (in_t == b) {
			arr[0] = f; arr[1] = b; arr[2] = c; arr[3] = d; arr[4] = e; arr[5] = a;
		}
		else if (in_t == c) {
			arr[0] = f; arr[1] = c; arr[2] = e; arr[3] = d; arr[4] = a; arr[5] = b;
		}
		else if (in_t == e) {
			arr[0] = f; arr[1] = e; arr[2] = a; arr[3] = d; arr[4] = b; arr[5] = c;
		}
	}
}
void RIGHT(int front, int top, int back, int down, int left, int right) {
	nfront = front;
	nback = back;
	nright = top;
	ntop = left;
	nleft = down;
	ndown = right;
}
void DOWN(int front, int top, int back, int down, int left, int right) {
	nright = right;
	nleft = left;
	ndown = front;
	nfront = top;
	ntop = back;
	nback = down;
}
void LEFT(int front, int top, int back, int down, int left, int right) {
	nfront = front;
	nback = back;
	nleft = top;
	ntop = right;
	nright = down;
	ndown = left;
}
void UP(int front, int top, int back, int down, int left, int right) {
	nright = right;
	nleft = left;
	ntop = front;
	nfront = down;
	ndown = back;
	nback = top;
}
void bfs(int y, int x, int front, int top, int back, int down, int left, int right, int step) {
	visited[y][x][front][top] = 1;
	enQ(y, x, front, top, back, down, left, right, step);
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		int tfront = peek().front;
		int ttop = peek().top;
		int tback = peek().back;
		int tdown = peek().down;
		int tleft = peek().left;
		int tright = peek().right;
		int tstep = peek().step;
		if (ty == N - 1 && tx == M - 1 && tfront == cc && ttop == dd) {
			if (min > tstep)min = tstep;
		}
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (ny < 0 || N <= ny || nx < 0 || M <= nx) continue;
			if (i == 0) RIGHT(tfront, ttop, tback, tdown, tleft, tright);
			else if (i == 1) DOWN(tfront, ttop, tback, tdown, tleft, tright);
			else if (i == 2) LEFT(tfront, ttop, tback, tdown, tleft, tright);
			else if (i == 3) UP(tfront, ttop, tback, tdown, tleft, tright);
			if (visited[ny][nx][nfront][ntop] == 0) {
				enQ(ny, nx, nfront, ntop, nback, ndown, nleft, nright, tstep + 1);
				visited[ny][nx][nfront][ntop] = 1;
			}
		}
	}
}
int main(void) {
	freopen("Text1.txt", "r", stdin);
	scanf("%d", &T);
	for (int test_case = 0; test_case < T; test_case++)
	{
		scanf("%d %d %d %d %d %d %d %d %d %d %d %d", &A, &B, &C, &D, &E, &F, &N, &M, &aa, &bb, &cc, &dd);

		make_square(A, B, C, D, E, F, aa, bb);
		bfs(0, 0, arr[0], arr[1], arr[3], arr[4], arr[5], arr[2], 0);


		printf("Case #%d\n", test_case + 1);
		if (min == 2123456789)printf("%d\n", -1);
		else printf("%d\n", min);
		init();
	}
	return 0;
}