#include <stdio.h>
#define SIZE 10//0
int N, M, R, t = -1;
int map[SIZE][SIZE], copy_map[SIZE][SIZE], temp_line[SIZE], temp_square[SIZE / 2][SIZE / 2], line[SIZE * 10];
void copy() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			copy_map[i][j] = map[i][j];
		}
	}
}
void swap() {
	int temp = N;
	N = M;
	M = temp;
}
void choice1() {
	for (int j = 0; j < M; j++) {
		for (int i = 0; i < N / 2; i++) {
			int temp = map[i][j];
			map[i][j] = map[N - 1 - i][j];
			map[N - 1 - i][j] = temp;
		}
	}
}
void choice2() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M / 2; j++) {
			int temp = map[i][j];
			map[i][j] = map[i][M - 1 - j];
			map[i][M - 1 - j] = temp;
		}
	}
}
void choice3() {
	copy();
	for (int j = 0; j < M; j++) {
		for (int i = 0; i < N; i++) {
			temp_line[N - 1 - i] = copy_map[i][j];
		}
		for (int i = 0; i < N; i++) {
			map[j][i] = temp_line[i];
		}
	}
	swap();
}
void choice4() {
	copy();
	for (int j = 0; j < M; j++) {
		for (int i = 0; i < N; i++) {
			temp_line[i] = copy_map[i][M - 1 - j];
		}
		for (int i = 0; i < N; i++) {
			map[j][i] = temp_line[i];
		}
	}
	swap();
}
void choice5() {
	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < M / 2; j++) {
			temp_square[i][j] = map[i][j];
		}
	}

	for (int i = N / 2; i < N; i++) {
		for (int j = 0; j < M / 2; j++) {
			map[i - N / 2][j] = map[i][j];
		}
	}

	for (int i = N / 2; i < N; i++) {
		for (int j = M / 2; j < M; j++) {
			map[i][j - M / 2] = map[i][j];
		}
	}

	for (int i = 0; i < N / 2; i++) {
		for (int j = M / 2; j < M; j++) {
			map[i + N / 2][j] = map[i][j];
		}
	}

	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < M / 2; j++) {
			map[i][j + M / 2] = temp_square[i][j];
		}
	}
}
void choice6() {
	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < M / 2; j++) {
			temp_square[i][j] = map[i][j];
		}
	}

	for (int i = 0; i < N / 2; i++) {
		for (int j = M / 2; j < M; j++) {
			map[i][j - M / 2] = map[i][j];
		}
	}
	for (int i = N / 2; i < N; i++) {
		for (int j = M / 2; j < M; j++) {
			map[i - N / 2][j] = map[i][j];
		}
	}
	for (int i = N / 2; i < N; i++) {
		for (int j = 0; j < M / 2; j++) {
			map[i][j + M / 2] = map[i][j];
		}
	}
	for (int i = N / 2; i < N; i++) {
		for (int j = 0; j < M / 2; j++) {
			map[i][j] = temp_square[i - N / 2][j];
		}
	}
}
void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", map[i][j]);
		}printf("\n");
	}
}
void choice(int n) {
	if (n == 1) choice1();
	else if (n == 2) choice2();
	else if (n == 3) choice3();
	else if (n == 4) choice4();
	else if (n == 5) choice5();
	else choice6();
}
void push(int num) { line[++t] = num; }
void pop() { t--; }
int peek() { return line[t]; }
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d %d", &N, &M, &R);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	int c;
	scanf("%d", &c);
	push(c);
	for (int i = 1; i < R; i++) {
		scanf("%d", &c);
		int top = peek();
		if (c == 1 && top == 1) pop();
		else if (c == 2 && top == 2)pop();
		else if ((c == 3 && top == 4) || (c == 4 && top == 3))pop();
		else if ((c == 5 && top == 6) || (c == 6 && top == 5))pop();
		else push(c);
	}
	for (int i = 0; i <= t; i++) {
		choice(line[i]);
	}
	print();
	return 0;
}