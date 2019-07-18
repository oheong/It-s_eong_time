#include<stdio.h>
#define SIZE 20
int N, f = -1, r = -1, count, yy, xx, ans;
int map[SIZE][SIZE], visited[SIZE][SIZE], by[4] = { 0,0,1,-1 }, bx[4] = { 1,-1,0,0 };
typedef struct { int y; int x; int step; int size; }Queue;
Queue q[SIZE*SIZE*SIZE*SIZE];
bool flag;
void enQ(int y, int x, int step, int size) {
	r++;
	q[r].y = y;
	q[r].x = x;
	q[r].step = step;
	q[r].size = size;
}
void deQ() { f++; }
Queue peek() { return q[f + 1]; }
int empty() {
	if (f == r)return 1;
	else return 0;
}
void init() {
	f = r = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 0;
		}
	}
	flag = false;
}
void search() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == 2) {
				yy = i; xx = j;
				return;
			}
		}
	}
}
void bfs() {
	int tempstep = 0;
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		int tstep = peek().step;
		int tsize = peek().size;
		deQ();
		if (flag == true && tstep != tempstep) {
			search();//�ĺ� �߿��� ���� ���ǿ� �����ϴ³� ã��.
			init();
			count++;//�ѳ�Ա�
			if (count == tsize) {//�ѳ� �Ծ��µ� �� ������ ���� ����ġ ������� ���������� ����ġ�� ������
				tsize++;
				count = 0;
			}
			enQ(yy, xx, tstep, tsize);//���ο� ����
			visited[yy][xx] = 1;
			map[yy][xx] = 0;
			ans = tstep;
			continue;
		}
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < N&&visited[ny][nx] == 0 && map[ny][nx] <= tsize) {
				if (map[ny][nx] == 0 || map[ny][nx] == tsize) {//����
					visited[ny][nx] = 1;
				}
				else {
					tempstep = tstep;
					flag = true;//�Ծ�� �� �ĺ��� �ִ�.
					visited[ny][nx] = 2;
				}
				enQ(ny, nx, tstep + 1, tsize);
			}
		}
	}
}
int main() {
	//freopen("Text.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9) {
				enQ(i, j, 0, 2);
				visited[i][j] = 1;
				map[i][j] = 0;
			}
		}
	}
	bfs();
	printf("%d\n", ans);
	return 0;
}