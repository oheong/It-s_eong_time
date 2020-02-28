import java.util.Scanner;

public class sweaSwimmingPool {
	static int day, month1, month3, year, min, total;
	static int[] schedule, map;
	static int[] set = { 0, 1, 3 };

	static void dfs(int d) {
		if (d == 13) {
			// map�� ���ġ ����� �������� ����Ǿ��ְ� schedule�� ��¥ ����
			int sum = 0;
			for (int i = 1; i < 12; i++) {
				if (schedule[i] == 0)
					continue;
				if (map[i] == 0) {
					if (schedule[i] != 0) {
						int temp = day * schedule[i];
						sum += temp;
					}
				}

				else if (map[i] == 1) { // 1���� ¥��
					if (schedule[i] != 0)
						sum += month1;
				}

				else { // 3���� ¥��
					for (int j = 0; j < 3; j++) {
						if (schedule[i + j] != 0) {
							sum += month3;
							i += 2;
							break;
						}
					}
				}
			}
			if (sum < min) {
//				for (int i = 1; i <= 12; i++) {
//					System.out.printf("%d ", map[i]);
//				}
//				System.out.println("\t" + sum);
				min = sum;
			}
			return;
		}
		for (int i = 0; i < 3; i++) {
			map[d] = set[i];
			dfs(d + 1);
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int test = 0; test < T; test++) {
			day = sc.nextInt();
			month1 = sc.nextInt();
			month3 = sc.nextInt();
			year = sc.nextInt();
			min = year;
			// ��� �� �޾ƿ�
			schedule = new int[15];
			map = new int[13];
			total = 0;
			for (int i = 1; i <= 12; i++) {
				schedule[i] = sc.nextInt();
				total += schedule[i];
			}
			// �ϳ� ��ȹ �� �޾ƿ�
			dfs(1);
			System.out.printf("#%d %d\n", test + 1, min);
		}
	}
}
