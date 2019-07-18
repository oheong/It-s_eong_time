#include <stdio.h>
#define SIZE 20
int N, M, D, max, r = -1, f = -1;
int map[SIZE][SIZE], copymap[SIZE][SIZE], visited[SIZE][SIZE];
int by[3] = { 0,-1,0 }, bx[3] = { -1,0,1 };
typedef struct { int y; int x; }Queue;
Queue q[SIZE*SIZE];
void enQ(int y, int x) {
	r++;
	q[r].x = x;
	q[r].y = y;
}
void deQ() { f++; }
int Empty() {
	if (f == r)return 1;
	else return 0;
}
Queue peek() { return q[f + 1]; }
int abs(int a) {
	if (a < 0) return -1 * a;
	else return a;
}
int empty() {
	for (int i = N - 1; 0 <= i; i--) {
		for (int j = 0; j < M; j++) {
			if (copymap[i][j] == 1)return 0;//안비었다
		}
	}
	return 1;//비었다
}
void copy() {
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			copymap[i][j] = map[i][j];
		}
	}
}
void down() {// 적 내려오는 함수
	for (int i = 0; i < M; i++) {
		copymap[N - 1][i] = 0;
		visited[N - 1][i] = 0;
	}
	for (int i = N - 2; 0 <= i; i--) {
		for (int j = 0; j < M; j++) {
			copymap[i + 1][j] = copymap[i][j];
			copymap[i][j] = 0;
			visited[i][j] = 0;
		}
	}
}
void attack(int y, int x) {//공격할 놈 찾기
	//y, x는 궁수의 좌표
	/*
	여기를 고쳐야될것같은데, 가장 가까운놈을 공격한다.
	가까운놈이 여럿일경우, 가장 왼쪽에 있는 적을 공격한다.
	*/
	//for (int i = N - 1; 0 <= i; i--) {
	//	for (int j = 0; j < M; j++) {
	//		if (copymap[i][j] != 0 && (abs(y - i) + abs(x - j)) <= D) {
	//			copymap[i][j] = 8;
	//			return;
	//		}
	//	}
	//}

	enQ(y, x);
	visited[y][x] = 1;
	while (Empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		deQ();
		for (int i = 0; i < 3; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < M&&visited[ny][nx] == 0 && (abs(ny - y) + abs(nx - x)) <= D) {
				if (copymap[ny][nx] == 1 || copymap[ny][nx] == 8) {
					copymap[ny][nx] = 8;
					return;
				}
				else {
					enQ(ny, nx);
					visited[ny][nx] = 1;
				}
			}
		}
	}

}
int kill() {//공격 당한놈 죽어라
	int temp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (copymap[i][j] == 8) {
				temp++;
				copymap[i][j] = 0;
			}
		}
	}
	return temp;
}
void init() {
	f = r = -1;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = 0;
		}
	}
}
void dfs(int d, int n) {
	//조합
	if (d == 3) {//궁수들이 고정됐음.
		copy();
		int sum = 0;
		while (empty() == 0) {
			for (int j = 0; j < M; j++) {
				if (copymap[N][j] == 9) {
					attack(N, j);
					init();
				}
			}
			sum += kill();
			down();
		}
		if (max < sum)max = sum;
		return;
	}
	for (int i = n; i < M; i++) {
		if (map[N][i] == 0) {
			map[N][i] = 9;//궁수 위치
			dfs(d + 1, i);
			map[N][i] = 0;
		}
	}
}
int main() {
	//freopen("Text.txt", "r", stdin);
	scanf("%d %d %d", &N, &M, &D);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	dfs(0, 0);
	printf("%d\n", max);
	return 0;
}