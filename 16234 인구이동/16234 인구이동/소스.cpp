#include <stdio.h>
int testcase, N, L, R, f = -1, r = -1, count = 0, sum = 0;
int map[50][50], visited[50][50];
int by[4] = { 0,-1,0,1 }, bx[4] = { -1,0,1,0 };
typedef struct { int x; int y; } Queue;
Queue q[2500];
bool flag = false;
void enQ(int y, int x) {
	r++;
	q[r].y = y;
	q[r].x = x;
}
void deQ() { f++; }
Queue peek() { return q[f + 1]; }
int isEmpty() {
	if (f == r) return 1;
	else return 0;
}
int abs(int a) {
	if (a < 0) return -1 * a;
	else return a;
}
void getAvg(int s, int c) {
	int t = s / c;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == 1) {
				map[i][j] = t;
				visited[i][j] = 2;
			}
		}
	}
	sum = 0; count = 0;
}
void dividePeople(int y, int x) {
	enQ(y, x);
	visited[y][x] = 1;
	sum = 0;
	count = 0;
	while (isEmpty() == 0) {
		int tx = peek().x;
		int ty = peek().y;
		sum += map[ty][tx];
		deQ();
		for (int i = 0; i < 4; i++) {
			int nx = tx + bx[i];
			int ny = ty + by[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < N&&visited[ny][nx] == 0) {
				int chaE = abs(map[ty][tx] - map[ny][nx]);
				if (L <= chaE && chaE <= R) {
					flag = true;
					count++;
					visited[ny][nx] = 1;
					enQ(ny, nx);
				}
			}
		}
	}
	if (count > 0) getAvg(sum, count + 1);
}
void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 0;
		}
	}
	flag = false;
	r = -1; f = -1;
}
void dfs(int d) {
	if (d > 2000) return;
	//return 해야되는거는 무조건 제일위에
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == 0) {
				dividePeople(i, j);
				//if (flag == false)//false면 들어갔다 나온적이 없음
					visited[i][j] = 2;
			}
		}
	}
	if (flag == false) {
		printf("%d\n", d);
		return;
	}
	else {
		init();
		dfs(d + 1);
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d %d", &N, &L, &R);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	dfs(0);
	return 0;
}
//아니ㅅㅂ 뭐가문제란말임ㅅㅂ