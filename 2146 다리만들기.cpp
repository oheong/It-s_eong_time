#include <stdio.h>
#define SIZE 100
int N, count_island, f = -1, r = -1, value, min = 2123456789;
int map[SIZE][SIZE], visited[SIZE][SIZE], bx[4] = { 1,-1,0,0 }, by[4] = { 0,0,1,-1 };
typedef struct Queue { int y; int x; int bridge; };
Queue q[10000];
void enQ(int y, int x, int b) {
	r++;
	q[r].x = x;
	q[r].y = y;
	q[r].bridge = b;
}
void deQ() { f++; }
Queue peek() { return q[f + 1]; }
int empty() {
	if (f == r)return 1;
	else return 0;
}
void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 0;
		}
	}
	f = r = -1;
}
void change() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 2)map[i][j] = 1;
		}
	}
}
bool go(int y, int x) {//바다로 나갈 길이 있느냐
	for (int i = 0; i < 4; i++) {
		int yy = y + by[i];
		int xx = x + bx[i];
		if (xx < 0 || N <= xx || yy < 0 || N <= yy) continue;
		if (map[yy][xx] == 0) return true;//ㅇㅇ 있음
	}
	return false;//ㄴㄴ없음
}
void bfs(bool ver, int now_state, int y, int x) {
	//if ver==0 라벨링
	//   ver==1 다리 만들기
	visited[y][x] = 1;
	enQ(y, x, 1);
	while (empty() == 0) {
		int tx = peek().x;
		int ty = peek().y;
		int tb = peek().bridge;
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < N) {
				if (ver == true) {
					if (map[ny][nx] == 0 && visited[ny][nx] == 0) {
						visited[ny][nx] = tb;
						enQ(ny, nx, tb + 1);
					}
					else if (map[ny][nx] != now_state && map[ny][nx] != 0 && visited[ny][nx] == 0) {
						if (min > tb)
							min = tb;
					}
				}
				else {
					if (map[ny][nx] == 1 && visited[ny][nx] == 0) {
						map[ny][nx] += (value + 10000);
						enQ(ny, nx, tb);
					}
				}
			}
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	//섬 라벨링
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1 && visited[i][j] == 0) {
				map[i][j] += (value + 10000);
				bfs(false, 0, i, j);
				value++;
			}
		}
	}
	init();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] != 0 && go(i, j) == true) {//바다쪽으로 진출할 자리가 있다.
				bfs(true, map[i][j], i, j);
				init();
			}
			else {
				visited[i][j] = 1;
			}
		}
	}
	printf("%d\n", min - 1);
	return 0;
}

/*
5
1 0 0 0 0
1 0 0 0 1
1 1 1 0 1
0 0 0 0 0
0 0 0 1 0

답 : 1
*/
/*
5
1 0 0 0 1
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
1 1 0 0 1

답 : 2
*/