import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class swea5644 {
	static int M, A, C, P;
	static int[][] map, user;
	static int[] by = { 0, -1, 0, 1, 0 }, bx = { 0, 0, 1, 0, -1 };
	static List<BC> list;

	static class BC {
		int y;
		int x;
		int c;
		int p;

		public BC(int y, int x, int c, int p) {
			this.y = y;
			this.x = x;
			this.c = c;
			this.p = p;
		}
	}

	static int abs(int a) {
		if (a < 0)
			return -1 * a;
		else
			return a;
	}

	static int dist(int p_x, int p_y, int bc_x, int bc_y) {
		return abs(p_x - bc_x) + abs(p_y - bc_y);
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int T = scanner.nextInt();
		for (int test = 0; test < T; test++) {
			map = new int[10][10];
			M = scanner.nextInt(); // 사용자 이동 정보 갯수
			A = scanner.nextInt(); // 배터리 갯수
			user = new int[2][M];
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < M; j++) {
					user[i][j] = scanner.nextInt();
				}
			}
			list = new ArrayList<BC>();
			for (int i = 0; i < A; i++) {
				int x = scanner.nextInt();
				int y = scanner.nextInt();
				int c = scanner.nextInt();
				int p = scanner.nextInt();
				list.add(new BC(y - 1, x - 1, c, p));
			}
			int y1 = 0, x1 = 0;
			int y2 = 9, x2 = 9;
			int sum = 0;
			int[][] get_bc = new int[2][A];
			for (int m = 0; m <= M; m++) {

				for (int bc = 0; bc < A; bc++) {
					if (dist(x1, y1, list.get(bc).x, list.get(bc).y) <= list.get(bc).c)
						get_bc[0][bc] = bc;
					else
						get_bc[0][bc] = -1;

					if (dist(x2, y2, list.get(bc).x, list.get(bc).y) <= list.get(bc).c)
						get_bc[1][bc] = bc;
					else
						get_bc[1][bc] = -1;

				}
				int tempMax = 0;
				for (int i = 0; i < A; i++) {
					for (int j = 0; j < A; j++) {
						int p1 = get_bc[0][i];
						int p2 = get_bc[1][j];
						if (p1 != -1 && p2 != -1) {
							if (p1 == p2) {
								if (tempMax < list.get(p1).p)
									tempMax = list.get(p1).p;
							} else {
								if (tempMax < list.get(p1).p + list.get(p2).p)
									tempMax = list.get(p1).p + list.get(p2).p;
							}
						} else if (p1 == -1 && p2 != -1) {
							if (tempMax < list.get(p2).p)
								tempMax = list.get(p2).p;
						} else if (p1 != -1 && p2 == -1) {
							if (tempMax < list.get(p1).p)
								tempMax = list.get(p1).p;
						}
					}
				}
				sum += tempMax;
				if (m == M)
					break;
				y1 += by[user[0][m]];
				x1 += bx[user[0][m]];
				y2 += by[user[1][m]];
				x2 += bx[user[1][m]];
			}

			System.out.printf("#%d %d\n", test + 1, sum);
		}
	}
}
