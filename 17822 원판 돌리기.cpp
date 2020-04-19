#include <stdio.h>
#define SIZE 50
#define dead -1
int N, M, T, f, r;
int map[SIZE + 1][SIZE], visited[SIZE + 1][SIZE];
int temp[SIZE], by[4] = { 0,0,1,-1 }, bx[4] = { 1,-1,0,0 };
typedef struct { int y; int x; }Queue;
Queue q[SIZE*SIZE];
void enQ(int y, int x) {
	r++;
	q[r].y = y;
	q[r].x = x;
}
void deQ() { f++; }
int empty() {
	if (f == r)return 1;
	else return 0;
}
Queue peek() { return q[f + 1]; }
int get_ans() {
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == dead)continue;
			sum += map[i][j];
		}
	}
	return sum;
}
double get_avg() {
	double sum = 0;
	double count = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == dead) continue;
			sum += map[i][j];
			count++;
		}
	}
	return sum / count;
}
void copy(int n) {
	for (int i = 0; i < M; i++) {
		temp[i] = map[n][i]; // n��° ���� ��ȣ�� �״�� ī���ؿ�
	}
}
int bfs(int y, int x, int num) {
	f = r = -1;
	enQ(y, x);
	visited[y][x] = 1;
	int count = 1;
	while (empty() == 0) {
		int ty = peek().y;
		int tx = peek().x;
		deQ();
		for (int i = 0; i < 4; i++) {
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (nx == -1) nx = M - 1;
			else if (nx == M) nx = 0;
			if (0 < ny&&ny <= N && visited[ny][nx] == 0 && map[ny][nx] == num) {
				enQ(ny, nx);
				map[ny][nx] = dead;
				visited[ny][nx] = 1;
				count++;
			}
		}
	}
	if (count > 1)map[y][x] = dead;
	return count;
}
int is_same() {
	int flag = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			// �����ϰ� ���� ���� ������ �ٷιٷ� �����ϱ�
			if (map[i][j] == dead) continue;
			if (bfs(i, j, map[i][j]) > 1) flag = 1;
		}
	}
	return flag;
}
void change(double avg) {
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == dead) continue;
			if (map[i][j] > avg) map[i][j]--;
			else if (map[i][j] < avg) map[i][j]++;
		}
	}
}
void turn(int n, int d, int k) { // ���� �����̴� ���� ��ȣ, ����, ��ĭ ��������?
	copy(n); // ī���ؿ�
	if (d == 1) k = M - k;
	for (int i = 0; i < M; i++) {
		map[n][(i + k) % M] = temp[i];
	}
}
void game_start(int x, int d, int k) {
	for (int n = 1; n <= N; n++) {
		if (n%x == 0) { // ��ȣ�� x�� ����� ������
			turn(n, d, k);
		}
		for (int j = 0; j < M; j++)visited[n][j] = 0;
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d %d", &N, &M, &T);
	for (int i = 1; i <= N; i++) { // 1������ N�� ȸ����
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 0; i < T; i++) {
		int x, d, k;
		scanf("%d %d %d", &x, &d, &k);
		game_start(x, d, k);
		// ������ ���� ����
		if (is_same() == 0) { // ���� ���� ��� ���� ������
			change(get_avg());
		}
	}

	printf("%d\n", get_ans());

	return 0;
}