import java.util.Scanner;

public class SWEA7699 {
	static int T, R, C, ans;
	static int by[] = { 1, -1, 0, 0 }, bx[] = { 0, 0, 1, -1 };
	static char map[][];
	static int alph[];

	static void dfs(int d, int y, int x) {
		if (ans < d) {
			ans = d;
		}
		// print();
		for (int i = 0; i < 4; i++) {
			int ny = y + by[i];
			int nx = x + bx[i];
			if (ny < 0 || R <= ny || nx < 0 || C <= nx)
				continue;
			if (alph[map[ny][nx] - 65] != 0)
				continue;
			alph[map[ny][nx] - 65] = d + 1;
			dfs(d + 1, ny, nx);
			alph[map[ny][nx] - 65] = 0;
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		T = sc.nextInt();
		for (int test = 0; test < T; test++) {
			R = sc.nextInt();
			C = sc.nextInt();

			map = new char[R + 1][C + 1];
			alph = new int[26];
			ans = 0;
			for (int i = 0; i < R; i++) {
				String temp = sc.next();
				for (int j = 0; j < C; j++) {
					map[i][j] = temp.charAt(j);
				}
			}
			alph[map[0][0] - 65] = 1;
			dfs(1, 0, 0);
			System.out.println(String.format("#%d %d", test + 1, ans));

		}
	}
}
