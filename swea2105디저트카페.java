import java.util.Scanner;

public class swea2105디저트카페 {
	static int N, max;
	static int[][] map;
	static int[] visited = new int[2];
	static int[] dessert = new int[101];
	static int[] by = { 1, 1, -1, -1 }, bx = { -1, 1, 1, -1 };

	static int is_ok(int y, int x) {
		if (x - visited[0] < 0 || x + visited[1] >= N)
			return 0;
		if (y + visited[0] + visited[1] >= N)
			return 0;
		return 1;
	}

	static int get_dessert(int y, int x) {
		for (int i = 0; i < visited[0]; i++) {
			if (dessert[map[y][x]] != 0)
				return -1;
			dessert[map[y][x]] = 1;
			y += by[0];
			x += bx[0];
		}
		for (int i = 0; i < visited[1]; i++) {
			if (dessert[map[y][x]] != 0)
				return -1;
			dessert[map[y][x]] = 1;
			y += by[1];
			x += bx[1];
		}
		for (int i = 0; i < visited[0]; i++) {
			if (dessert[map[y][x]] != 0)
				return -1;
			dessert[map[y][x]] = 1;
			y += by[2];
			x += bx[2];
		}
		for (int i = 0; i < visited[1] ; i++) {
			if (dessert[map[y][x]] != 0)
				return -1;
			dessert[map[y][x]] = 1;
			y += by[3];
			x += bx[3];
		}
		return 1;
	}

	static void init() {
		for (int i = 0; i < 101; i++) {
			dessert[i] = 0;
		}
	}

	static void dfs(int d) {
		if (d == 2) {
			if (visited[0] + visited[1] >= N)
				return;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (is_ok(i, j) == 1) {
						// 디저트를 먹을 수 있는 상태
						init();
						if (get_dessert(i, j) == 1) {
							int temp = 2 * (visited[0] + visited[1]);
							if (max < temp)
								max = temp;
						}
					}
				}
			}
			return;
		}
		for (int i = 1; i < N; i++) {
			visited[d] = i;
			dfs(d + 1);
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int test = 0; test < T; test++) {
			N = sc.nextInt();
			map = new int[N][N];
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					map[i][j] = sc.nextInt();
				}
			}
			max = -1;
			dfs(0);
			System.out.printf("#%d %d\n", test + 1, max);
		}
	}
}
