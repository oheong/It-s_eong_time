#include <stdio.h>
#define SUIT 4
#define RANK 13
int T;
char get_char[5][2], sibal[50];
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
//int how_many(int num) {
//	int count = 0;
//	for (int i = 0; i < RANK; i++) {
//		if (rank[i] == num) count++;
//	}
//	return count;
//}
int how_many() {
	int pair = 0;
	int triple = 0;
	int four = 0;
	for (int i = 0; i < RANK; i++) {
		if (rank[i] == 2)pair++;
		if (rank[i] == 3)triple++;
		if (rank[i] == 4)four++;
	}
	if (four == 1)return 8;
	if (pair == 1 && triple == 1) return 7;
	if (triple == 1)return 4;
	if (pair == 2)return 3;
	if (pair == 1)return 2;
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
	freopen("Text.txt", "r", stdin);
	scanf("%d\n", &T);
	for (int test = 0; test < T; test++) {
		for (int i = 0; i < 5; i++) {
			scanf("%s", &sibal);
			get_char[i][0] = sibal[0];
			get_char[i][1] = sibal[1];
			//printf("%s", sibal);
			//for (int j = 0; j < 2; j++) {
			//	scanf("%1c", &get_char[i][j]);
			//}
			//char c;
			//scanf("%1c", &c);
		}
		printf("#%d ", test + 1);
		set_map();
		// 1. High card : 1~8번에 해당하지 않는다.
		int priority = 1;

		//9. Straight Flush : 모두 동일한 슈트에 랭크(값)가 모두 연속적이다. (여기서는 로얄 플러쉬를 포함한다. 로얄 플러쉬는 모두 동일한 슈트에 T, J, Q, K, A를 갖는다).
		if (is_same_suit() == 1 && is_continue() == 1) priority = 9; // 5개 => 1개맞음

		// 8. Four of a Kind : 5장 중 4개의 랭크(값)가 모두 같다.
		//else if (how_many(4) == 1) priority = 8; // 5개

		// 6. Flush : 5장이 모두 동일한 슈트다.
		else if (is_same_suit() == 1) priority = 6; // 5개 => 1개맞음

		// 5. Straight : 다른 슈트가 섞여있으며 랭크(값)가 모두 연속적이다.
		else if (is_same_suit() != 1 && is_continue() == 1) priority = 5; // 5개

		// 7. Full House : 3장의 동일한 랭크(값)와 다른 랭크(값)의 동일한 2장으로 구성된다.
		//else if (how_many(3) == 1 && how_many(2) != 0) priority = 7; // 이새끼가 문제네

		// 4. Three of a kind : 동일한 랭크(값)가 3장이다(1, 2, 3, 3, 3).
		//else if (how_many(3) == 1) priority = 4;

		// 3. Two pair : 동일한 랭크(값) 2장씩 두개의 랭크다(2, 6, 6, 3, 3).
		//else if (how_many(2) == 2) priority = 3;

		// 2. One pair : 동일한 랭크가 2장이다(2, 4, 5, 5, 7).
		//else if (how_many(2) == 1) priority = 2;
		else priority = how_many();

		choice(priority);

		init();
	}
	return 0;
}
// 5/40 tq왜?

/*
36
ST SJ SQ SK SA
DA D2 D3 D4 D5
H5 H9 H6 H7 H8
CQ CJ CT C9 C8
ST DT HQ HT CT
D5 C5 H5 HA S5
HA S2 CA SA DA
CK HK DK DJ SK
S9 H9 D9 CK SK
HK CK DK HT ST
S2 C2 DA HA SA
S7 D7 D5 H5 C5
C5 C9 CA CJ C4
H4 HJ HK HA H2
SA S3 S4 S5 S6
DK DJ DQ DA D9
ST DJ HK CQ SA
DA H2 C3 S4 D5
H2 C3 S4 D5 H6
CQ SJ DT H9 CK
ST HT CT HJ CQ
D8 S9 C8 S7 H8
DA CA HA SK H2
S2 D5 C5 C6 H5
SA DA SK DK S5
D5 D2 D3 S3 C2
SJ SQ DJ DK DQ
D7 H8 S6 C8 S7
S5 D7 D5 S2 S4
SA ST HA SK S3
HK DK C5 H2 SJ
C9 C8 CA S4 D4
ST SJ SQ SK D2
DJ HQ CK DA D3
C6 C9 CQ S4 S2
HA D2 H3 DJ CQ



#1 Straight Flush
#2 Straight Flush
#3 Straight Flush
#4 Straight Flush
#5 Four of a Kind
#6 Four of a Kind
#7 Four of a Kind
#8 Four of a Kind
#9 Full House
#10 Full House
#11 Full House
#12 Full House
#13 Flush
#14 Flush
#15 Flush
#16 Flush
#17 Straight
#18 Straight
#19 Straight
#20 Straight
#21 Three of a kind
#22 Three of a kind
#23 Three of a kind
#24 Three of a kind
#25 Two pair
#26 Two pair
#27 Two pair
#28 Two pair
#29 One pair
#30 One pair
#31 One pair
#32 One pair
#33 High card
#34 High card
#35 High card
#36 High card

*/