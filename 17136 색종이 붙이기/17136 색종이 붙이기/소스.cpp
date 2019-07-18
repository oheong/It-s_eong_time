/*
중복 조합으로 될 수 있는 색종이의 가짓수를 다 체크 한 다음 그 색종이들을 다 쓸 수 있는지 검사
*/
#include <stdio.h>
int map[10][10], mapvisited[10][10], paper[5];
int min = 2123456789, count;
void init() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			mapvisited[i][j] = 0;
	}
}
bool check(int y, int x, int size) {
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (map[i][j] == 1 && mapvisited[i][j] == 0) continue;
			return false;
		}
	}

	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			mapvisited[i][j] = 1;
		}
	}
	return true;
}
bool find(int size) {
	for (int i = 0; i <= 10 - size; i++) {
		for (int j = 0; j <= 10 - size; j++) {
			if (mapvisited[i][j] == 0 && map[i][j] == 1 && map[i][j + size - 1] == 1 && map[i + size - 1][j] == 1 && map[i + size - 1][j + size - 1] == 1) {
				if (check(i, j, size) == true)
					return true;
			}
		}
	}
	return false;
}
void allcheck(int t) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (map[i][j] != mapvisited[i][j])
				return;
		}
	}
	if (min > t) min = t;
}
void dfs(int d) {
	if (d == -1) {
		init();
		int tempAns = 0;
		for (int i = 0; i < 5; i++) tempAns += paper[i];
		if (tempAns == 0) return;
		for (int i = 4; 0 <= i; i--) {//5*5부터 조지기
			if (paper[i] == 0) continue;
			int temp = paper[i];
			while (0 < temp) {
				if (find(i + 1) == true) temp--;
				else return;
			}
		}
		allcheck(tempAns);
		return;
	}
	for (int i = 5; 0 <= i; i--) {
		paper[d] = i;
		dfs(d - 1);
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) count++;
		}
	}
	if (count == 0) {
		printf("%d\n", 0);
		return 0;
	}
	dfs(4);
	if (min > 25) min = -1;
	printf("%d\n", min);
	return 0;
}