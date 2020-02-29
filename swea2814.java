import java.util.Scanner;

public class swea2814 {
	static int N, M, max;
	static int[][] map;
	static int[] visited;

	static void dfs(int d, int n) {
		if (visited[n] == 1) return;
		if (max < d) max = d;
		visited[n] = d;
		for (int i = 0; i < N; i++) {
			if (map[n][i] == 1 && visited[i] == 0) {
				dfs(d + 1, i);
			}
		}
		visited[n] = 0;
	}

	static void init() {
		for (int i = 0; i < N; i++) {
			visited[i] = 0;
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int test = 0; test < T; test++) {
			N = sc.nextInt();
			M = sc.nextInt();
			map = new int[N][N];
			visited = new int[N];
			for (int m = 0; m < M; m++) {
				int a = sc.nextInt();
				int b = sc.nextInt();
				map[a - 1][b - 1] = 1;
				map[b - 1][a - 1] = 1;
			}

			for (int i = 0; i < N; i++) {
				dfs(1, i);
				init();
			}
			System.out.printf("#%d %d\n", test + 1, max);
			max = 0;
		}
	}
}
