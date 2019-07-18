#include <stdio.h>
typedef struct { int t[8]; } TOPNI;
TOPNI T[4];
int tempT[8], visited[4];
int testcase, whatT, clock;
bool arr[3];
void change(int w, int c) {
	//회전
	for (int i = 0; i < 8; i++) tempT[i] = T[w].t[i];
	if (c == 1) {//시계 방향으로 회전
		for (int i = 0; i < 8; i++)
			T[w].t[(i + 1) % 8] = tempT[i];
	}
	else {//반시계 방향으로 회전
		for (int i = 0; i < 8; i++)
			T[w].t[(i + 7) % 8] = tempT[i];
	}
}
bool check(int center, int centerdir, int what, int whardir) {
	if (T[center].t[centerdir] == T[what].t[whardir])
		return false;//같은 극임. 회전 안해도됨
	else return true;//다른 극임 회전해야함.
}
int zegop(int n) {
	int num = 1;
	for (int i = 0; i < n; i++) num *= 2;
	return num;
}
int main() {
	//freopen("Text.txt", "r", stdin);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &T[i].t[j]);
		}
	}
	scanf("%d", &testcase);
	for (int test = 0; test < testcase; test++) {
		scanf("%d %d", &whatT, &clock);

		for (int i = 0; i < 3; i++)arr[i] = false;

		arr[0] = check(0, 2, 1, 6);
		arr[1] = check(1, 2, 2, 6);
		arr[2] = check(2, 2, 3, 6);

		if (whatT == 1) {
			if (arr[0] == true) {
				if (arr[1] == true) {
					if (arr[2] == true) {
						change(0, clock);
						change(1, clock*-1);
						change(2, clock);
						change(3, clock*-1);
					}
					else {
						change(0, clock);
						change(1, clock*-1);
						change(2, clock);
					}
				}
				else {
					change(0, clock);
					change(1, clock*-1);
				}
			}
			else change(0, clock);
		}
		else if (whatT == 2) {
			if (arr[0] == true) {
				change(0, clock*-1);
			}
			change(1, clock);
			if (arr[1] == true) {
				change(2, clock*-1);
				if (arr[2] == true) {
					change(3, clock);
				}
			}
		}
		else if (whatT == 3) {
			if (arr[1] == true) {
				change(1, clock*-1);
				if (arr[0] == true) {
					change(0, clock);
				}
			}
			change(2, clock);
			if (arr[2] == true) {
				change(3, clock*-1);
			}
		}
		else {
			if (arr[2] == true) {
				if (arr[1] == true) {
					if (arr[0] == true) {
						change(3, clock);
						change(2, clock*-1);
						change(1, clock);
						change(0, clock*-1);
					}
					else {
						change(3, clock);
						change(2, clock*-1);
						change(1, clock);
					}
				}
				else {
					change(3, clock);
					change(2, clock*-1);
				}
			}
			else change(3, clock);
		}
	}
	int finalvalue = 0;
	for (int i = 0; i < 4; i++) {
		if (T[i].t[0] == 1) finalvalue += zegop(i);
	}
	printf("%d\n", finalvalue);
	return 0;
}