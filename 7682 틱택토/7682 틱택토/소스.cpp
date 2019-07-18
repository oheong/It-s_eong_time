#include <stdio.h>
char map[5][5], gets[10];
int count, visited[9];
typedef struct { int y; int x; }Queue;
Queue q[9];
bool check() {
	if ((map[0][0] == map[1][0] && map[1][0] == map[2][0]) || (map[0][2] == map[1][2] && map[1][2] == map[2][2])) {
		if ((map[0][0] == map[0][1] && map[0][1] == map[0][2]) || (map[2][0] == map[2][1] && map[2][1] == map[2][2])) {
			if (map[1][1] == map[0][0])
				return true;
			else if (map[2][0] == map[1][1] && map[1][1] == map[0][2])
				return true;
		}
	}
	return false;
}
void dfs(int d) {
	if (d > count)return;
	if (check() == true) {
		printf("valid\n");
		return;
	}
	else {
		printf("invalid\n");
		return;
	}
	for (int i = 0; i < count; i++) {
		if (visited[i] % 2 == 0)
			map[q[i].y][q[i].x] = 'O';
		else
			map[q[i].y][q[i].x] = 'X';
	}
	for (int i = 0; i < count; i++) {
		visited[d] = i;
		dfs(d + 1);
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	while (1) {
		scanf("%s", gets);
		count = 0;
		if (gets[0] == 'e') return 0;
		for (int i = 0; i < 9; i++) {
			int y = i / 3;
			int x = i % 3;
			map[y][x] = gets[i];
			if (gets[i] == '.') {
				q[count].y = y;
				q[count++].x = x;
			}
		}
		for (int i = 0; i < count; i++) {
			visited[0] = i;
			dfs(1);
		}
	}
	return 0;
}