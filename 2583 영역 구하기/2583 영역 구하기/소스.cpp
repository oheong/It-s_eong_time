#include <stdio.h>
#define SIZE 150
int N, M, K, f = -1, r = -1, cnt;
int map[SIZE][SIZE], visited[SIZE][SIZE], arr[SIZE], by[4] = { 1,-1,0,0 }, bx[4] = { 0,0,1,-1 };
typedef struct { int y; int x; }Queue;
Queue q[SIZE*SIZE*SIZE];
void enQ(int y, int x) {
	r++;
	q[r].y = y;
	q[r].x = x;
}
void deQ() { f++; }
Queue peek() { return q[f + 1]; }
int empty() {
	if (r == f)return 1;
	else return 0;
}
void sort() {
	int temp;
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
void bfs(int y, int x) {
	int count = 1;
	visited[y][x] = 2;
	enQ(y, x);
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < M && 0 <= nx && nx < N&&visited[ny][nx] == 0) {
				enQ(ny, nx);
				visited[ny][nx] = 2;
				count++;
			}
		}
	}
	arr[cnt++] = count;
}
//ㅁㅊ 개 멍청,,,,, 위아래 뒤집으나 안뒤집으나 논리는 똑같음,,,세상,,,
int main() {
	//freopen("Text.txt", "r", stdin);
	int a, b, c, d;
	scanf("%d %d %d", &M, &N, &K);
	for (int k = 0; k < K; k++) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		for (int i = b; i < d; i++) {
			for (int j = a; j < c; j++) {
				visited[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 0 && visited[i][j] == 0) {
				bfs(i, j);
			}
		}
	}
	sort();
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}