#include <stdio.h>
#define SIZE 100
int N, count, start, end, f = -1, r = -1, min = 2123456789;
int sort_arr[SIZE*SIZE], arr[SIZE*SIZE], map[SIZE][SIZE], visited[SIZE][SIZE], bx[4] = { 1,-1,0,0 }, by[4] = { 0,0,1,-1 };
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
	if (f == r) return 1;
	else return 0;
}
void sort() {
	int temp;
	for (int i = 0; i < N*N; i++) {
		for (int j = 0; j < N*N - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
void init() {
	f = r = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 0;
		}
	}
}
bool bfs(int y, int x, int s, int e) {
	enQ(y, x);
	visited[y][x] = 1;
	int tx = peek().x;
	int ty = peek().y;
	if (map[ty][tx]<s || map[ty][tx]>e) return false;
	while (empty() == 0) {
		tx = peek().x;
		ty = peek().y;
		if (ty == N - 1 && tx == N - 1) return true;
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < N&&s <= map[ny][nx] && map[ny][nx] <= e && visited[ny][nx] == 0) {
				visited[ny][nx] = 1;
				enQ(ny, nx);
			}
		}
	}
	return false;
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[i*N + j] = map[i][j];
		}
	}
	sort();
	sort_arr[0] = arr[0];
	for (int i = 1; i < N*N; i++) {
		if (sort_arr[count] != arr[i])
			sort_arr[++count] = arr[i];
	}

	while (end <= count && start <= end) {//와나시발 범위뭐야 ㅅㅂ
		if (bfs(0, 0, sort_arr[start], sort_arr[end]) == true) {
			if (min > sort_arr[end] - sort_arr[start]) {
				min = sort_arr[end] - sort_arr[start];
			}
			else start++;
		}
		else end++;
		init();
	}
	printf("%d\n", min);
	return 0;
}