#include <stdio.h>
#define SIZE 64
int N, M, Q, f, r, total, max;
int map[SIZE][SIZE], visited[SIZE][SIZE], copy_map[SIZE][SIZE], temp_map[SIZE][SIZE], by[4] = { 1,0,-1,0 }, bx[4] = { 0,1,0,-1 };
typedef struct {
	int y; int x;
}Queue;
Queue q[SIZE*SIZE];
void enQ(int y, int x) {
	r++;
	q[r].y = y;
	q[r].x = x;
}
void deQ() { f++; }
Queue peek() { return q[f + 1]; }
int empty() {
	if (f == r) return 0;
	return 1;
}
int sq(int a) {
	if (a == 1) return 2;
	else if (a == 2) return 4;
	else if (a == 3) return 8;
	else if (a == 4) return 16;
	else if (a == 5) return 32;
	return 64;
}

void change(int y, int x, int num) {
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			temp_map[j][num - 1 - i] = map[y + i][x + j];
		}
	}
	for (int j = 0; j < num; j++) {
		for (int i = 0; i < num; i++) {
			map[y + i][x + j] = temp_map[i][j];
		}
	}
}

int is_ok(int y, int x) {
	int cnt = 0; // 얼음 있는 갯수
	for (int i = 0; i < 4; i++) {
		int ny = y + by[i];
		int nx = x + bx[i];
		if (0 <= ny && ny < N && 0 <= nx && nx < N && 0 < map[ny][nx]) { // 범위 안이고 주변에 얼음이 몇개있는지?
			cnt++;
		}
	}
	return cnt;
}

void delete_ice() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (3 <= is_ok(i, j)) copy_map[i][j] = 0;
			else copy_map[i][j] = -1;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (copy_map[i][j] == -1) {
				if (map[i][j] == 0) continue;
				else map[i][j] += copy_map[i][j];
			}
		}
	}
}

int bfs(int y, int x) {
	total += map[y][x];
	int size = 1;
	f = r = -1;
	enQ(y, x);
	visited[y][x] = 1;
	while (empty() != 0) {
		int ty = peek().y;
		int tx = peek().x;
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < N && 0 < map[ny][nx] && visited[ny][nx] == 0) {
				enQ(ny, nx);
				visited[ny][nx] = 1;
				size++;
				total += map[ny][nx];
			}
		}
	}
	return size;
}
int sum(int y, int x, int num) {
	int s = 0;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			s += map[y + i][x + j];
		}
	}
	return s;
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d", &N, &Q);
	N = sq(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < Q; i++) {
		scanf("%d", &M);
		M = sq(M);

		for (int i = 0; i < N / M; i++) {
			for (int j = 0; j < N / M; j++) {
				change(i * M, j * M, M);
			}
		}

		delete_ice();
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == 0 && map[i][j] != 0) {
				int temp = bfs(i, j);
				if (max < temp)
					max = temp;
			}
		}
	}
	if (total != 0)
		printf("%d\n%d\n", total, max);
	else printf("0\n0\n");
	return 0;
}