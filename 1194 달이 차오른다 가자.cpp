#include <stdio.h>
#define SIZE 55
int N, M, f, r, min = 2123456789;
char map[SIZE][SIZE], temp[SIZE];
int visited[SIZE][SIZE][1 << 6], by[4] = { 0,0,1,-1 }, bx[4] = { 1,-1,0,0 };
typedef struct {
	int y; int x; int step; int key;
}Queue;
Queue q[SIZE*SIZE * SIZE];
void enQ(int y, int x, int step, int key) {
	r++;
	q[r].y = y;
	q[r].x = x;
	q[r].step = step;
	q[r].key = key;
}
void deQ() { f++; }
Queue peek() { return q[f + 1]; }
int empty() {
	if (f == r)return 1;
	else return 0;
}
void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}
void bfs() {
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		int tstep = peek().step;
		int key = peek().key;
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < M&&map[ny][nx] != '#'&&visited[ny][nx][key] == 0) {
				if (map[ny][nx] == '1') {
					if (min > tstep + 1)min = tstep + 1;
				}
				else if ('a' <= map[ny][nx] && map[ny][nx] <= 'f') { // key
					int temp_key = key | (1 << (map[ny][nx] - 'a'));

					visited[ny][nx][temp_key] = 1;
					enQ(ny, nx, tstep + 1, temp_key);
					continue;
				}
				else if ('A' <= map[ny][nx] && map[ny][nx] <= 'F') { // ¹®
					if ((key & (1 << (map[ny][nx] - 'A'))) == 0) {
						continue;
					}
				}
				visited[ny][nx][key] = 1;
				enQ(ny, nx, tstep + 1, key);
			}
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d/n", &N, &M);
	f = r = -1;
	for (int i = 0; i < N; i++) {
		scanf("%s", &temp);
		for (int j = 0; j < M; j++) {
			map[i][j] = temp[j];
			if (map[i][j] == '0') {
				enQ(i, j, 0, 0);
				visited[i][j][0] = 1;
				map[i][j] = '.';
			}
		}
	}

	bfs();
	printf("%d\n", min == 2123456789 ? -1 : min);
	return 0;
}