import java.util.Scanner;

public class swea7699수지의수지맞는여행 {
	static int R, C, max;
	static char[][] map;
	static int[][] visited;
	static int[] alph;
	static int[] by = { 0, 0, 1, -1 }, bx = { 1, -1, 0, 0 };

	static int is_ok(int y, int x) {
		if (0 <= y && y < R && 0 <= x && x < C)
			return 1;
		return 0;
	}

	static void dfs(int d, int y, int x) {
		if (d > R * C)
			return;
		if (visited[y][x] == 1 || alph[map[y][x] - 'A'] == 1)
			return;
		if (max < d)
			max = d;

		visited[y][x] = 1;
		alph[map[y][x] - 'A'] = 1;
		for (int i = 0; i < 4; i++) {
			int ny = y + by[i];
			int nx = x + bx[i];
			if (is_ok(ny, nx) == 1) {
				dfs(d + 1, ny, nx);
			}
		}
		visited[y][x] = 0;
		alph[map[y][x] - 'A'] = 0;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int test = 0; test < T; test++) {
			R = sc.nextInt();
			C = sc.nextInt();
			map = new char[R][C];
			alph = new int[26];
			visited = new int[R][C];

			for (int i = 0; i < R; i++) {
				String str = sc.next();
				for (int j = 0; j < C; j++) {
					map[i][j] = str.charAt(j);
				}
			}

			max = 0;
			dfs(1, 0, 0);

			System.out.printf("#%d %d\n", test + 1, max);

		}
	}
}
