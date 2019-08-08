#include <stdio.h>
#define SIZE 20
char map[SIZE], temp_calc[SIZE], last_calc[SIZE];
int visited[SIZE], temp_num[SIZE], last_num[SIZE];
int N, max = -2147483648;
int get_sum(int num_arr[], char calc_arr[], int calc) {
	int sum = num_arr[0];
	for (int i = 0; i < calc; i++) {
		if (calc_arr[i] == '+')
			sum += num_arr[i + 1];
		else if (calc_arr[i] == '-')
			sum -= num_arr[i + 1];
		else if (calc_arr[i] == '*')
			sum *= num_arr[i + 1];
	}
	return sum;
}
//int last_sum(int temp) {
//	int sum = temp_map[0] - '0';
//	char calc;
//	for (int i = 1; i < temp; i++) {
//		if (temp_map[i] == '+' || temp_map[i] == '-' || temp_map[i] == '*') {
//			calc = temp_map[i];
//		}
//		else {
//			int t = temp_map[i] - '0';
//			if (calc == '+') sum += t;
//			else if (calc == '-') sum -= t;
//			else if (calc == '*') sum *= t;
//		}
//	}
//	return sum;
//}
void dfs(int d, int n) {
	if (d > N / 2)return;
	else if (d % 2 == 0) {
		int flag = 0, l_num = 0, l_calc = 0, t_num = 0, t_calc = 0;
		for (int i = 0; i < N; i++) {
			if (flag == 0 && visited[i] == 0) {
				if ('0' <= map[i] && map[i] <= '9')
					last_num[l_num++] = map[i] - '0';
				else
					last_calc[l_calc++] = map[i];
			}
			else if (flag == 0 && visited[i] == 1) {
				flag = 1;
				t_num = t_calc = 0;
				temp_num[t_num++] = map[i] - '0';
			}
			else if (flag == 1 && visited[i] == 0) {//괄호사이
				if ('0' <= map[i] && map[i] <= '9') {
					temp_num[t_num++] = map[i] - '0';
				}
				else
					temp_calc[t_calc++] = map[i];
			}
			else if (flag == 1 && visited[i] == 1) {
				flag = 0;
				temp_num[t_num++] = map[i] - '0';
				last_num[l_num++] = get_sum(temp_num, temp_calc, t_calc);
			}
			if (t_calc >= 2)return;
		}
		//temp_map 결과내야함
		int t = get_sum(last_num, last_calc, l_calc);
		if (max < t)max = t;
		//printf("%d ,", t);
		////if (t > 66) 
		//	for (int i = 0; i < N; i++)printf("%d ", visited[i]);
		//
		//printf("\n");
	}
	for (int i = n; i < N; i++) {
		if ('0' <= map[i] && map[i] <= '9'&&visited[i] == 0) {
			visited[i] = 1;
			dfs(d + 1, i + 1);
			visited[i] = 0;
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d\n", &N);
	for (int i = 0; i < N; i++) {
		scanf("%c", &map[i]);
	}
	dfs(0, 0);
	printf("%d\n", max);
	return 0;
}
// ㅅㅂ 단, 괄호 안에는 하나의 연산자만 들어 있어야 한다 ㅅㅂ 아 존나 시팔