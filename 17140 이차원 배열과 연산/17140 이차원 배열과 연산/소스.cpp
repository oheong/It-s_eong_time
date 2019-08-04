#include<stdio.h>
#define SIZE 100
int r, c, k, n, m, ans;
int map[SIZE][SIZE];
typedef struct { int num; int count; }T;
T temp_arr[SIZE + 1];
int is_here(int mm, int num) {
	for (int i = 0; i < mm; i++) {
		if (temp_arr[i].num == num) return i;//있다
	}
	return -1;//없다
}
void sort(int cnt) {
	//count정렬
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt - i - 1; j++) {
			if (temp_arr[j].count > temp_arr[j + 1].count) {
				int temp_num = temp_arr[j].num;
				int temp_count = temp_arr[j].count;

				temp_arr[j].num = temp_arr[j + 1].num;
				temp_arr[j].count = temp_arr[j + 1].count;

				temp_arr[j + 1].num = temp_num;
				temp_arr[j + 1].count = temp_count;
			}
			else if (temp_arr[j].count == temp_arr[j + 1].count) {
				if (temp_arr[j].num > temp_arr[j + 1].num) {
					int temp_num = temp_arr[j].num;
					int temp_count = temp_arr[j].count;

					temp_arr[j].num = temp_arr[j + 1].num;
					temp_arr[j].count = temp_arr[j + 1].count;

					temp_arr[j + 1].num = temp_num;
					temp_arr[j + 1].count = temp_count;
				}
			}
		}
	}
}
int R(int n) {
	int mm = 0;//temp_arr에 들어가있는 숫자 갯수.
	for (int j = 0; j < m; j++) {
		if (map[n][j] == 0)continue;
		int w = is_here(mm, map[n][j]);
		if (w == -1) {
			temp_arr[mm].num = map[n][j];
			temp_arr[mm++].count = 1;
		}
		else
			temp_arr[w].count++;
		map[n][j] = 0;
	}
	sort(mm);
	for (int i = 0; i < mm; i++) {
		map[n][i * 2] = temp_arr[i].num;
		map[n][(i * 2) + 1] = temp_arr[i].count;
		temp_arr[i].num = 0;
		temp_arr[i].count = 0;
	}
	return mm * 2;
}
int C(int m) {
	int nn = 0;
	for (int i = 0; i < n; i++) {
		if (map[i][m] == 0)continue;
		int w = is_here(nn, map[i][m]);
		if (w == -1) {
			temp_arr[nn].num = map[i][m];
			temp_arr[nn++].count = 1;
		}
		else temp_arr[w].count++;
		map[i][m] = 0;
	}
	sort(nn);
	for (int i = 0; i < nn; i++) {
		map[i * 2][m] = temp_arr[i].num;
		map[(i * 2) + 1][m] = temp_arr[i].count;
		temp_arr[i].num = 0;
		temp_arr[i].count = 0;
	}
	return nn * 2;
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d %d", &r, &c, &k);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	n = m = 3;
	while (map[r - 1][c - 1] != k) {
		if (n >= m) {
			int temp_m = 0;
			for (int i = 0; i < n; i++) {
				int t = R(i);
				if (temp_m < t)temp_m = t;
			}
			if (m < temp_m&&temp_m < 100)m = temp_m;
		}
		else {
			int temp_n = 0;
			for (int j = 0; j < m; j++) {
				int t = C(j);
				if (temp_n < t)temp_n = t;
			}
			if (n < temp_n&&temp_n < 100)n = temp_n;
		}
		ans++;
		if (100 < ans) {
			ans = -1;
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}