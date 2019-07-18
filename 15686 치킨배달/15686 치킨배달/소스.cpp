#include <stdio.h>
#define SIZE 50
int N, M, howManyChic, howManyHouse, min = 2123456789, temp;
int map[SIZE][SIZE];
typedef struct { int check; int y; int x; } CHICKEN;
CHICKEN chic[13], house[2 * SIZE];
int abs(int a) {
	if (a < 0)return -1 * a;
	else return a;
}
void dfs(int d, int n) {
	if (d == M) {
		for (int i = 0; i < howManyChic; i++) {
			if (chic[i].check == 1) {
				for (int j = 0; j < howManyHouse; j++) {
					temp = abs(chic[i].y - house[j].y) + abs(chic[i].x - house[j].x);//치킨집이랑 비교 ㄴㄴ 집이랑 비교
					if (temp < house[j].check)house[j].check = temp;
				}
			}
		}
		temp = 0;
		for (int i = 0; i < howManyHouse; i++) {
			temp += house[i].check;
			house[i].check = 2123456789;
		}
		if (temp < min)min = temp;
		return;
	}
	for (int i = n + 1; i < howManyChic; i++) {
		if (chic[i].check == 0) {
			chic[i].check = 1;
			dfs(d + 1, i);
			chic[i].check = 0;
		}
	}
}
int main() {
	//freopen("Text.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) {
				chic[howManyChic].y = i;
				chic[howManyChic++].x = j;
			}
			else if (map[i][j] == 1) {
				house[howManyHouse].check = 2123456789;
				house[howManyHouse].y = i;
				house[howManyHouse++].x = j;
			}
		}
	}
	for (int i = 0; i < howManyChic; i++) {
		chic[i].check = 1;
		dfs(1, i);
		chic[i].check = 0;
	}
	printf("%d\n", min);
	return 0;
}