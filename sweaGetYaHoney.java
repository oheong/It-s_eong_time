import java.util.Scanner;

public class sweaGetYaHoney {
	static int N, M, C, max, temp;
	static int[][] map, visited, honey;
	static boolean[] v;

	static int zegop(int a) {
		return a * a;
	}

	static void choice(int d, int num, int sum) {
		if (C < sum)
			return;
		if (d == M) {
			int tmp = 0;
			for (int i = 0; i < M; i++) {
				if (v[i] == true) {
					tmp += zegop(honey[num][i]);
				}
			}
			if (temp < tmp)
				temp = tmp;
			return;
		}
		v[d] = true;
		choice(d + 1, num, sum + honey[num][d]);
		v[d] = false;
		choice(d + 1, num, sum);
	}

	static void dfs(int d, int n) {
		if (d == 2) {
			temp = 0;
			choice(0, 0, 0);
			int temp1 = temp;
			temp = 0;
			choice(0, 1, 0);
			int temp2 = temp;
			if (max < temp1 + temp2)
				max = temp1 + temp2;
			return;
		}
		for (int i = n; i < N * N; i++) {
			int y = i / N;
			int x = i % N;
			if (visited[y][x] == 0 && x + M - 1 < N) {
				for (int j = 0; j < M; j++) {
					visited[y][x + j] = d + 1;
					honey[d][j] = map[y][x + j];
				}
				dfs(d + 1, i);
				for (int j = 0; j < M; j++)
					visited[y][x + j] = 0;
			}
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int test = 0; test < T; test++) {
			N = sc.nextInt();
			M = sc.nextInt();
			C = sc.nextInt();
			visited = new int[N][N];
			map = new int[N][N];
			honey = new int[2][M];
			v = new boolean[M];
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					map[i][j] = sc.nextInt();
				}
			}
			dfs(0, 0);
			System.out.printf("#%d %d\n", test + 1, max);
			max = 0;
		}
	}
}
