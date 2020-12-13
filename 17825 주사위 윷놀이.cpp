#include <stdio.h>
int max;
int dice[10], visited[10], map_visited[33];
int score[33] = { 0,
				2,4,6,8,10,
				12,14,16,18,20,
				22,24,26,28,30,
				32,34,36,38,40,
				13,16,19,25,26,
				27,28,22,24,30,
				35,0 };
int map[33][5] = {
	{1,2,3,4,5},
	{2,3,4,5,6},
	{3,4,5,6,7},
	{4,5,6,7,8},
	{5,6,7,8,9},
	{21,22,23,24,30},
	{7,8,9,10,11},
	{8,9,10,11,12},
	{9,10,11,12,13},
	{10,11,12,13,14},
	{28,29,24,30,31},
	{12,13,14,15,16},
	{13,14,15,16,17},
	{14,15,16,17,18},
	{15,16,17,18,19},
	{27,26,25,24,30},
	{17,18,19,20,32},
	{18,19,20,32,32},
	{19,20,32,32,32},
	{20,32,32,32,32},
	{32,32,32,32,32},
	{22,23,24,30,31},
	{23,24,30,31,20},
	{24,30,31,20,32},
	{30,31,20,32,32},
	{24,30,31,20,32},
	{25,24,30,31,20},
	{26,25,24,30,31},
	{29,24,30,31,20},
	{24,30,31,20,32},
	{31,20,32,32,32},
	{20,32,32,32,32},
	{32,32,32,32,32}
}; // map은 지금 내가 있는 칸에서 주사위가 나왔을때 다음으로 가야할 칸
void dfs(int d, int sum, int mal1, int mal2, int mal3, int mal4) {
	if ((0 < mal1  && mal1 < 32) && (0 < mal2 && mal2 < 32) && mal1 == mal2) return;
	else if ((0 < mal1 && mal1 < 32) && (0 < mal3 && mal3 < 32) && mal1 == mal3) return;
	else if ((0 < mal1 && mal1 < 32) && (0 < mal4 && mal4 < 32) && mal1 == mal4) return;
	else if ((0 < mal2 && mal2 < 32) && (0 < mal3 && mal3 < 32) && mal2 == mal3) return;
	else if ((0 < mal2 && mal2 < 32) && (0 < mal4 && mal4 < 32) && mal2 == mal4) return;
	else if ((0 < mal3 && mal3 < 32) && (0 < mal4 && mal4 < 32) && mal3 == mal4) return;


	if (d == 10) {
		if (max < sum)
			max = sum;
		return;
	}

	visited[d] = 1;
	dfs(d + 1, sum + score[map[mal1][dice[d] - 1]], map[mal1][dice[d] - 1], mal2, mal3, mal4);
	visited[d] = 2;
	dfs(d + 1, sum + score[map[mal2][dice[d] - 1]], mal1, map[mal2][dice[d] - 1], mal3, mal4);
	visited[d] = 3;
	dfs(d + 1, sum + score[map[mal3][dice[d] - 1]], mal1, mal2, map[mal3][dice[d] - 1], mal4);
	visited[d] = 4;
	dfs(d + 1, sum + score[map[mal4][dice[d] - 1]], mal1, mal2, mal3, map[mal4][dice[d] - 1]);
}
int main() {
	freopen("Text.txt", "r", stdin);
	for (int i = 0; i < 10; i++) {
		scanf("%d", &dice[i]);
	}
	dfs(0, 0, 0, 0, 0, 0);
	printf("%d\n", max);
	return 0;
}