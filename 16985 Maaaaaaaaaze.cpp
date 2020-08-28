#include <stdio.h>
int real_map[5][5][5], rotation_map[5][5][5], map[5][5][5], visited[5][5][5]; // [��][y][x]
int rotation[5], floor[5], visited_dfs[5];
int bz[6] = { -1,0,0,1,0,0 }, by[6] = { 0,-1,0,0,1,0 }, bx[6] = { 0,0,1,0,0,-1 };
int min = 2123456789, f, r;
typedef struct { int y; int x; int z; int step; }Queue;
Queue q[5 * 5 * 5 * 5 * 5 * 5];
void enQ(int z, int y, int x, int step) {
	r++;
	q[r].z = z;
	q[r].y = y;
	q[r].x = x;
	q[r].step = step;
}
void deQ() { f++; }
Queue peek() { return q[f + 1]; }
int empty() {
	if (f == r) return 1;
	else return 0;
}
void init() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				visited[i][j][k] = 0;
			}
		}
	}
}
void bfs(int z, int y, int x) {
	if (map[z][y][x] == 0)return;
	f = r = -1;
	visited[z][y][x] = 1;
	enQ(z, y, x, 0);
	while (empty() == 0) {
		int tz = peek().z;
		int ty = peek().y;
		int tx = peek().x;
		int tstep = peek().step;
		deQ();
		if (tz == 4 && ty == 4 && tx == 4) {
			if (tstep < min)
				min = tstep;
			return;
		}
		for (int i = 0; i < 6; i++) {
			int nz = tz + bz[i];
			int ny = ty + by[i];
			int nx = tx + bx[i];
			if (0 <= nz && nz < 5 && 0 <= ny && ny < 5 && 0 <= nx && nx < 5 && map[nz][ny][nx] == 1 && visited[nz][ny][nx] == 0) {
				visited[nz][ny][nx] = 1;
				enQ(nz, ny, nx, tstep + 1);
			}
		}
	}
}
int abs(int a) {
	if (a < 0)return -1 * a;
	else return a;
}
void mapping(int f, int p) {
	// f���� p��° �Ƕ��⸦ �־��
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			map[f][i][j] = rotation_map[p][i][j];
		}
	}
}
void change(int f, int r) {
	// f�� �Ƕ��⸦ r��ŭ ȸ���ض�
	// ���⼭ ���� ���� ������ �����ؼ� �װ� ����
	if (r == 0) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				rotation_map[f][i][j] = real_map[f][i][j];
			}
		}
	}
	else if (r == 1) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				rotation_map[f][j][abs(4 - i)] = real_map[f][i][j];
			}
		}
	}
	else if (r == 2) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				rotation_map[f][abs(4 - i)][abs(4 - j)] = real_map[f][i][j];
			}
		}
	}
	else if (r == 3) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				rotation_map[f][abs(4 - j)][i] = real_map[f][i][j];
			}
		}
	}
}
void floor_dfs(int d) {
	if (d == 5) {
		// ���⼭ ���� �̷�ã�� �����ؾ���
		bfs(0, 0, 0);
		init();
		return;
	}
	for (int i = 0; i < 5; i++) {
		if (visited_dfs[i] == 0) {
			floor[d] = i; // d�� i������ �����Ѵ�.
			mapping(i, d);
			visited_dfs[i] = 1;
			floor_dfs(d + 1);
			visited_dfs[i] = 0;
		}
	}
}
void rotation_dfs(int d) {
	if (d == 5) {
		// ȸ�� ������� �� ®��!
		// ���� �ʿ��� �� ������ ȸ���ѰŸ� rotation_map�� �ֱ�
		for (int f = 0; f < 5; f++) {
			change(f, rotation[f]);
		}
		floor_dfs(0);
		return;
	}
	for (int i = 0; i < 4; i++) {
		rotation[d] = i;
		rotation_dfs(d + 1);
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	for (int f = 0; f < 5; f++) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				scanf("%d", &real_map[f][i][j]);
			}
		}
	}
	rotation_dfs(0);
	//floor_dfs(0);
	if (min == 2123456789)min = -1;
	printf("%d\n", min);
	return 0;
}