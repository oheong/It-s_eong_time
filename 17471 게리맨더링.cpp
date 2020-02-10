//����
#include <stdio.h>
int N, min = 2123456789;
int visited[2][11], map[11][11], people[11];
void check_connected(int num, int start) {
	visited[1][start] = num;
	for (int i = 1; i <= N; i++) {
		if (map[start][i] == 1 && visited[0][i] == num && visited[1][i] == 0) {
			visited[1][i] = num;
			check_connected(num, i);
		}
	}
}
void init() {
	for (int i = 1; i <= N; i++) {
		visited[1][i] = 0;
	}
}
int is_connected() {
	for (int i = 1; i <= N; i++) {
		if (visited[0][i] != visited[1][i]) return -1;
	}
	return 1;
}
int abs(int a) {
	if (a < 0)return -1 * a;
	else return a;
}
void bbjh(int d) {
	//�κ����� �ѹ��� �� �غ��°���
	if (d == N+1) {
		for (int i = 1; i <= N; i++) {
			if (visited[0][i] == 1) {
				check_connected(1, i);
				break;
			}
		}
		for (int i = 1; i <= N; i++) {
			if (visited[0][i] == 2) {
				check_connected(2, i);
				break;
			}
		}

		// ���� �ȵ�����
		if (is_connected() == -1) {
			init();
			return;
		}

		//�� �� 1�̰ų� �� �� 2�� �� return;
		//�� ���ϱ�
		int temp_num1 = 0, temp_num2 = 0;
		int num1 = 0, num2 = 0;
		for (int i = 1; i <= N; i++) {
			if (visited[0][i] == 1) {
				num1 += people[i];
				temp_num1++;
			}
			else {
				num2 += people[i];
				temp_num2++;
			}
		}
		init();
		if (temp_num1 == N + 1 || temp_num1 == 0 || temp_num2 == N + 1 || temp_num2 == 0) return;

		int temp = abs(num1 - num2);
		if (temp < min)min = temp;
		return;
	}
	visited[0][d] = 1;
	bbjh(d + 1);
	visited[0][d] = 2;
	bbjh(d + 1);
}
int main() {
	scanf("%d", &N); // ������ ����
	for (int i = 1; i <= N; i++) {
		scanf("%d", &people[i]); // ������ �α�
	}
	for (int i = 1; i <= N; i++) {
		int connect;
		scanf("%d", &connect);
		for (int j = 0; j < connect; j++) {
			int temp;
			scanf("%d", &temp);
			map[i][temp] = 1;
			map[temp][i] = 1;
		}
	} // ������ �κ� ǥ��

	bbjh(1);

	if (min == 2123456789)printf("-1\n");
	else printf("%d\n", min);
	return 0;
}