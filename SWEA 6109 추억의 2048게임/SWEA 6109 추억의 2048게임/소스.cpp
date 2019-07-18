#include <stdio.h>
#define SIZE 20
int T, N, count;
char c[5];
int map[SIZE][SIZE], temp[SIZE];
int flag;
void push(int i, int cnt) {
	int t;
	for (int j = i; 0 <= j; j--) {
		t = temp[j];
		temp[j + cnt] = t;
		temp[j] = 0;
	}
}
int geti() {
	for (int i = 0; i < N; i++) {
		if (temp[i] != 0) {
			return i;
		}
	}
}
void moving() {
	count = 0;
	flag = 0;
	for (int i = N - 1; 0 < i; i--) {
		if (temp[i] == 0) {//0이면 다 위로 끌고오기
			for (int k = i; 0 <= k; k--) {
				if (temp[k] != 0) {
					push(k, count);
					i++;
					break;
				}
				else count++;
			}
		}
		else {//temp[i]!=0
			count = 0;
			for (int j = i - 1; 0 <= j; j--) {
				if (temp[j] == 0) {
					count++;
					flag = 1;
					continue;
				}
				else if (temp[j] != 0 && flag == 1) {
					push(j, count);
					count = 0;
					flag = 0;
					j++;
				}

				if (temp[i] == temp[j]) {
					count = 0;
					temp[i] *= 2;
					temp[j] = 0;
					break;
				}
				else
					break;
			}
		}
	}
	count = 0;
}
void down() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			temp[j] = map[j][i];
		moving();
		for (int j = N - 1; 0 <= j; j--)
			map[j][i] = temp[j];
	}
}
void up() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			temp[N - 1 - j] = map[j][i];
		moving();
		int t = geti();//2
		for (int j = 0; j < N; j++) {
			map[j][i] = temp[N - 1 - j];
		}
	}
}
void right() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			temp[j] = map[i][j];
		moving();
		for (int j = 0; j < N; j++)
			map[i][j] = temp[j];
	}
}
void left() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			temp[j] = map[i][j];
		moving();
		int t = geti();
		for (int j = 0; j < N; j++) {
			map[i][j] = temp[(j + t) % N];
		}
	}
}
int main() {
	//freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d %s", &N, c);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
			}
		}

		if (c[0] == 'u') up();
		else if (c[0] == 'd') down();
		else if (c[0] == 'r') right();
		else if (c[0] == 'l') left();

		printf("#%d\n", test + 1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				printf("%d ", map[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}




/*
15/100 ㅅㅂㅋㅋ
*/