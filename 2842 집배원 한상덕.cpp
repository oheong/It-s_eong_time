/*
inchworm 알고리즘
2차 배열의 값들을 일차배열로 재정렬한 뒤, 1차 배열을 오름차순으로 sort 한다.
sort 한 배열의 f와 r을 잡고, f, r의 가중치를 다르게 주면서 그 값에 맞는 bfs를 구현.
시발 존나어렵내ㅠ
*/
#include <stdio.h>
#define SIZE 51
int N, min = 2e9, f = -1, r = -1, count, s, e;
int map[SIZE][SIZE], visited[SIZE][SIZE], h_temp[SIZE*SIZE], height[SIZE*SIZE], bx[8] = { 0,1,1,1,0,-1,-1,-1 }, by[8] = { -1,-1,0,1,1,1,0,-1 };
char c_map[SIZE][SIZE];
typedef struct { int y; int x; }Queue;
Queue q[SIZE*SIZE*SIZE];
void enQ(int y, int x) {
	r++;
	q[r].x = x;
	q[r].y = y;
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
			if (h_temp[j] > h_temp[j + 1]) {
				temp = h_temp[j];
				h_temp[j] = h_temp[j + 1];
				h_temp[j + 1] = temp;
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
int bfs(int y, int x, int s, int e) {
	int k_count = 0;
	enQ(y, x);
	visited[y][x] = 1;
	while (empty() == 0) {
		int temp = 0;
		int tx = peek().x;
		int ty = peek().y;
		deQ();
		for (int i = 0; i < 8; i++) {
			int nx = tx + bx[i];
			int ny = ty + by[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < N&&visited[ny][nx] == 0 && s <= map[ny][nx] && map[ny][nx] <= e) {
				enQ(ny, nx);
				visited[ny][nx] = 1;
				if (c_map[ny][nx] == 'K') k_count++;
			}
		}
	}
	return k_count;
}
int main() {
	freopen("Text.txt", "r", stdin);
	int a, b;
	scanf("%d\n", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= N; j++) {
			scanf("%c", &c_map[i][j]);
			if (c_map[i][j] == 'P') a = i, b = j;
			else if (c_map[i][j] == 'K') count++;
		}
	}
	int n = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			h_temp[n++] = map[i][j];
		}
	}
	sort();
	height[0] = h_temp[0];
	n = 1;
	for (int i = 1; i < N*N; i++) {
		if (h_temp[i - 1] != h_temp[i])
			height[n++] = h_temp[i];
	}
	while (e < n&&s <= e) {
		if (bfs(a, b, height[s], height[e]) == count) {//배달할곳 다 찾았음!
			if (min > height[e] - height[s])
				min = height[e] - height[s];
			else s++;
		}
		else e++;
		init();
	}
	printf("%d\n", min);
	return 0;
}

//아 뭐가틀린지 모르겠네 시벌ㅡㅡ