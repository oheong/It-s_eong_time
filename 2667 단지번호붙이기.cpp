#include <stdio.h>
int map[50][50], visited[50][50], danji[500], bx[4] = { 1,-1,0,0 }, by[4] = { 0,0,1,-1 };
int N, danjicount, c, f = -1, r = -1;
typedef struct { int y; int x; }Queue;
Queue q[2500];
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
void bfs(int y, int x) {
	danjicount = 1;
	while (empty() == 0) {
		int tx = peek().x;
		int ty = peek().y;
		deQ();
		for (int i = 0; i < 4; i++) {
			int nx = tx + bx[i];
			int ny = ty + by[i];
			if (map[ny][nx] == 1 && visited[ny][nx] == 0) {
				visited[ny][nx] = 1;
				enQ(ny, nx);
				danjicount++;
			}
		}
	}
}
void sort() {
	int temp;
	for (int i = 0; i < c-1; i++) {
		for (int j = i; j < c - i - 1; j++) {
			if (danji[j] > danji[j + 1]) {
				temp = danji[j];
				danji[j] = danji[j + 1];
				danji[j + 1] = temp;
			}
		}
	}
}
int main() {
	//freopen("Text.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == 1 && visited[i][j] == 0) {
				visited[i][j] = 1;
				enQ(i, j);
				bfs(i, j);
				danji[c++] = danjicount;
			}
		}
	}
	sort();
	printf("%d\n", c );
	for (int i = 0; i < c; i++) {
		printf("%d\n", danji[i]);
	}
	return 0;
}
//아니시발 뭐가틀렸단말임ㅡㅡ