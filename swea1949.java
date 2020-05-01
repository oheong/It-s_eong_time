import java.util.Scanner;

public class swea1949 {
	static int T, N, K, top, max;
	static int[][] map;
	static int[] by = { 0, 0, 1, -1 }, bx = { 1, -1, 0, 0 };

	static void dfs(int d, int y, int x) {
		if (d > N * N)
			return;
		if (d > max)
			max = d;
		for (int i = 0; i < 4; i++) {
			int ny = y + by[i];
			int nx = x + bx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < N && map[ny][nx] < map[y][x])
				dfs(d + 1, ny, nx);
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		T = sc.nextInt();
		for (int test = 0; test < T; test++) {
			N = sc.nextInt();
			K = sc.nextInt();
			map = new int[N][N];
			top = 0;
			max = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					map[i][j] = sc.nextInt();
					if (map[i][j] > top)
						top = map[i][j];
				}
			}

			for (int y = 0; y < N; y++) {
				for (int x = 0; x < N; x++) {
					if (map[y][x] == top) {
						for (int i = 0; i < N; i++) {
							for (int j = 0; j < N; j++) {
								for (int k = 0; k <= K; k++) { // 이 미친ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ
									int minus = 0;
									if (map[i][j] < k) {
										minus = map[i][j];
										map[i][j] = 0;
									} else
										map[i][j] -= k;
									dfs(0, y, x);
									if (minus != 0)
										map[i][j] = minus;
									else
										map[i][j] += k;
								}
							}
						}
					}
				}
			}

			System.out.printf("#%d %d\n", test + 1, max + 1);
		}
	}
}
// 48/50
