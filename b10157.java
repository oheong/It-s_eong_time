import java.util.Scanner;

public class b10157 {
	static int C, R, ans;
	static int[][] map;

	static void print() {
		for (int i = 0; i < C; i++) {
			for (int j = 0; j < R; j++) {
				System.out.printf("%d ", map[i][j]);
			}
			System.out.println();
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		R = sc.nextInt();
		C = sc.nextInt();
		ans = sc.nextInt();

		if (C * R < ans) System.out.println(0);
		else {
			map = new int[C][R];
			int dir = -1, count = 1;
			int garo = R, sero = C;
			int y = C, x = 0;
			while (count <= C * R) {
				for (int i = 0; i < sero; i++) {
					y += dir;
					map[y][x] = count++;
				}
				garo--;
				dir *= -1;
				for (int j = 0; j < garo; j++) {
					x += dir;
					map[y][x] = count++;
				}
				sero--;
			}
			print();
			int flag = 0;
			for (int i = 0; i < C; i++) {
				for (int j = 0; j < R; j++) {
					if (map[i][j] == ans) {
						flag = 1;
						System.out.printf("%d %d\n", j + 1, C - i);
						break;
					}
				}
				if (flag == 1)
					break;
			}
		}
	}
}
// 38퍼 tq 왜자꾸 틀림?
