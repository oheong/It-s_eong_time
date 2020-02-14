#include <stdio.h>
#define SIZE 100
int M, N, H, f = -1, r = -1;
int map[SIZE][SIZE][SIZE], visited[SIZE][SIZE][SIZE];
int bz[6] = { 1,-1,0,0,0,0 }, by[6] = { 0,0,0,0,-1,1 }, bx[6] = { 0,0,-1,1,0,0 };
typedef struct { int y; int x; int z; }Queue;
Queue q[SIZE*SIZE*SIZE];
void enQ(int z, int y, int x) {
	r++;
	q[r].y = y;
	q[r].x = x;
	q[r].z = z;
}
void deQ() { f++; }
Queue peek() { return q[f + 1]; }
int empty() {
	if (r == f)return 1;
	else return 0;
}
void bfs() {
	int count = 0;
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		int tz = peek().z;
		deQ();
		for (int i = 0; i < 6; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			int nz = tz + bz[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < M && 0 <= nz && nz < H&&map[nz][ny][nx] == 0 && visited[nz][ny][nx] == 0) {
				enQ(nz, ny, nx);
				visited[nz][ny][nx] = visited[tz][ty][tx] + 1;
			}
		}
	}
}
int count() {
	int max = 0;
	for (int z = 0; z < H; z++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[z][i][j] == 1)continue;
				if (visited[z][i][j] > max)max = visited[z][i][j];
				if (map[z][i][j] == 0 && visited[z][i][j] == 0) return -1;
			}
		}
	}
	if (max > 0) return max - 1;
	else return max;
}
void print() {
	for (int z = 0; z < H; z++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				printf("%d ", visited[z][i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
}
int main() {
	scanf("%d %d %d", &M, &N, &H);

	for (int z = 0; z < H; z++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%d", &map[z][i][j]);
				if (map[z][i][j] == 1) {
					enQ(z, i, j);
					visited[z][i][j] = 1;
				}
			}
		}
	}

	bfs();
	printf("%d\n", count());
	print();
	return 0;
}