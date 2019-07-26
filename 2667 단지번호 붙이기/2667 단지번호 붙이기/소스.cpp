#include <stdio.h>
#define SIZE 30
int map[SIZE][SIZE], visited[SIZE][SIZE], by[4] = { 0,0,1,-1 }, bx[4] = { 1,-1,0,0 }, h[SIZE*SIZE*SIZE];
int N, f = -1, r = -1, count = 1;
typedef struct { int y; int x; }Queue;
Queue q[SIZE*SIZE];
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
void bfs(int y, int x) {
	int house = 1;
	visited[y][x] = count;
	enQ(y, x);
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < N&&visited[ny][nx] == 0 && map[ny][nx] == 1) {
				enQ(ny, nx);
				visited[ny][nx] = count;
				house++;
			}
		}
	}
	h[count - 1] = house;
}
int partition(int arr[], int left, int right) {
	int pivot = arr[left];
	int le = left, ri = right;
	while (le < ri) {
		while (pivot < arr[ri])ri--;
		while (le < ri&&arr[le] <= pivot)le++;
		int t = arr[le];
		arr[le] = arr[ri];
		arr[ri] = t;
	}
	arr[left] = arr[le];
	arr[le] = pivot;
	return le;
}
void Qsort(int arr[], int left, int right) {
	if (right < left)return;
	int pivot = partition(arr, left, right);
	Qsort(arr, left, pivot - 1);
	Qsort(arr, pivot + 1, right);
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == 0 && map[i][j] == 1) {
				bfs(i, j);
				count++;
			}
		}
	}
	Qsort(h, 0, count - 1);
	printf("%d\n", count - 1);
	for (int i = 1; i < count; i++)printf("%d\n", h[i]);
	return 0;
}