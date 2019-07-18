/*
드디어 씨발ㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠ기다려라 삼성전자ㅠㅠㅠㅠㅠㅠㅠㅠ
*/
#include <stdio.h>
#define SIZE 25
int map[SIZE][SIZE], visited[SIZE][SIZE], c[SIZE][SIZE], bx[4] = { 1,-1,0,0 }, by[4] = { 0,0,1,-1 };
int N, f = -1, r = -1, count, max, select_x, select_y, now;
typedef struct { int y; int x; int size; int dis; }Queue;
Queue q[SIZE*SIZE];
bool flag = false;
void enQ(int y, int x, int size, int dis) {
	r++;
	q[r].y = y;
	q[r].x = x;
	q[r].size = size;
	q[r].dis = dis;
}
void deQ() { f++; }
Queue peek() { return q[f + 1]; }
int empty() {
	if (f == r)return 1;
	else return 0;
}
void init() {
	f = r = -1;
	flag = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			c[i][j] = 0;
			visited[i][j] = 0;
		}
	}
}
void select() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (c[i][j] == 1) {
				select_y = i;
				select_x = j;
				return;
			}
		}
	}

}
void bfs() {
	while (empty() == 0) {
		int tx = peek().x;
		int ty = peek().y;
		int tsize = peek().size;
		int tdis = peek().dis;
		if (flag == true && now != tdis) {//여기서 이제 어느걸 먹을지 골라야댬
			select();
			init();
			count++;
			if (count == tsize) {
				tsize++;
				count = 0;
			}
			if (max < tdis)max = tdis;
			map[select_y][select_x] = 0;
			visited[select_y][select_x] = now + 1;
			enQ(select_y, select_x, tsize, now + 1);
			continue;
		}
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < N&&visited[ny][nx] == 0 && map[ny][nx] <= tsize) {
				if (map[ny][nx] < tsize && map[ny][nx] != 0) {//만약 여기 들어온게있다! 그럼 최초의 들어온것을 확인해서 choice에 넣기
					flag = true;
					c[ny][nx] = 1;
					visited[ny][nx] = 1;
					now = tdis;
					enQ(ny, nx, tsize, tdis + 1);
				}
				else if (map[ny][nx] == tsize || map[ny][nx] == 0) {
					//지나침
					enQ(ny, nx, tsize, tdis + 1);
					visited[ny][nx] = 1;
				}
			}
		}
	}
	printf("%d\n", max);
}
int main() {
	//freopen("Text.txt", "r", stdin);
	int a, b;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9) {
				a = i;
				b = j;
				visited[i][j] = 1;
				map[i][j] = 0;
			}
		}
	}
	enQ(a, b, 2, 0);
	bfs();
	return 0;
}