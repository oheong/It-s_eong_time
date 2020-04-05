#include <stdio.h>
#define SUIT 4
#define RANK 13
int T;
char get_char[5][2],sibal[50];
int map[SUIT][RANK], suit[SUIT], rank[RANK];
void init() {
	for (int i = 0; i < SUIT; i++) {
		suit[i] = 0;
		for (int j = 0; j < RANK; j++) {
			map[i][j] = 0;
			rank[j] = 0;
		}
	}
}
void set_map() {
	int y, x;
	for (int i = 0; i < 5; i++) {
		if (get_char[i][0] == 'S') y = 0;
		else if (get_char[i][0] == 'D') y = 1;
		else if (get_char[i][0] == 'H') y = 2;
		else if (get_char[i][0] == 'C') y = 3;

		if (get_char[i][1] == 'A') x = 0;
		else if (get_char[i][1] == '2') x = 1;
		else if (get_char[i][1] == '3') x = 2;
		else if (get_char[i][1] == '4') x = 3;
		else if (get_char[i][1] == '5') x = 4;
		else if (get_char[i][1] == '6') x = 5;
		else if (get_char[i][1] == '7') x = 6;
		else if (get_char[i][1] == '8') x = 7;
		else if (get_char[i][1] == '9') x = 8;
		else if (get_char[i][1] == 'T') x = 9;
		else if (get_char[i][1] == 'J') x = 10;
		else if (get_char[i][1] == 'Q') x = 11;
		else if (get_char[i][1] == 'K') x = 12;

		map[y][x] = 1;
	}
	for (int i = 0; i < SUIT; i++) {
		int count = 0;
		for (int j = 0; j < RANK; j++) {
			if (map[i][j] == 1) count++;
		}
		suit[i] = count;
	}
	for (int j = 0; j < RANK; j++) {
		int count = 0;
		for (int i = 0; i < SUIT; i++) {
			if (map[i][j] == 1) count++;
		}
		rank[j] = count;
	}
}
int how_many(int num) {
	int count = 0;
	for (int i = 0; i < RANK; i++) {
		if (rank[i] == num) count++;
	}
	return count;
}
int is_same_suit() {
	for (int i = 0; i < SUIT; i++) {
		if (suit[i] == 5) return 1;
	}
	return 0;
}
int is_continue() {
	for (int i = 0; i <= RANK - 4; i++) {
		int flag = 0;
		for (int j = 0; j < 5; j++) {
			//printf("%d ", (i + j)%RANK);
			if (rank[(i + j) % RANK] == 1) flag = 1;
			else {
				flag = 0;
				break;
			}
		}
		//printf("\n");
		if (flag == 1)return 1;
	}
	return 0;
}
void choice(int p) {
	if (p == 2)printf("One pair");
	else if (p == 3)printf("Two pair");
	else if (p == 4)printf("Three of a kind");
	else if (p == 5)printf("Straight");
	else if (p == 6)printf("Flush");
	else if (p == 7)printf("Full House");
	else if (p == 8)printf("Four of a Kind");
	else if (p == 9)printf("Straight Flush");
	else printf("High card");
	printf("\n");
}
int main() {
//	freopen("Text.txt", "r", stdin);
	scanf("%d\n", &T);
	for (int test = 0; test < T; test++) {
		for (int i = 0; i < 5; i++) {
			scanf("%s", &sibal);
			get_char[i][0] = sibal[0];
			get_char[i][1] = sibal[1];
		}
		printf("#%d ", test + 1);
		set_map();
		// 1. High card : 1~8번에 해당하지 않는다.
		int priority = 1;

		//9. Straight Flush : 모두 동일한 슈트에 랭크(값)가 모두 연속적이다. (여기서는 로얄 플러쉬를 포함한다. 로얄 플러쉬는 모두 동일한 슈트에 T, J, Q, K, A를 갖는다).
		if (is_same_suit() == 1 && is_continue() == 1) priority = 9;

		// 8. Four of a Kind : 5장 중 4개의 랭크(값)가 모두 같다.
		else if (how_many(4) == 1) priority = 8;

		// 6. Flush : 5장이 모두 동일한 슈트다.
		else if (is_same_suit() == 1) priority = 6;

		// 5. Straight : 다른 슈트가 섞여있으며 랭크(값)가 모두 연속적이다.
		else if (is_same_suit() != 1 && is_continue() == 1) priority = 5;

		// 7. Full House : 3장의 동일한 랭크(값)와 다른 랭크(값)의 동일한 2장으로 구성된다.
		else if (how_many(3) == 1 && how_many(2) == 1) priority = 7;

		// 4. Three of a kind : 동일한 랭크(값)가 3장이다(1, 2, 3, 3, 3).
		else if (how_many(3) == 1) priority = 4;

		// 2. One pair : 동일한 랭크가 2장이다(2, 4, 5, 5, 7).
		else if (how_many(2) == 1) priority = 2;

		// 3. Two pair : 동일한 랭크(값) 2장씩 두개의 랭크다(2, 6, 6, 3, 3).
		else if (how_many(2) == 2) priority = 3;

		choice(priority);

		init();
	}
	return 0;
}
