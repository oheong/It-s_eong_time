import java.util.Scanner;

public class swea4012 {
	static int N, min;
	static int[][] map;
	static int[] visited;

	static int abs(int a) {
		if (a < 0)
			return -1 * a;
		else
			return a;
	}

	static int get_sum(int what) {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i] == what && visited[j] == what) {
					sum += map[i][j];
				}
			}
		}
		return sum;
	}

	static void dfs(int d, int n) {
		if (d == N / 2) {
//			for(int i=0;i<N;i++)System.out.printf("%d ",visited[i]);
//			System.out.println();
			int team1 = get_sum(1);
			int team0 = get_sum(0);

			int temp = abs(team0 - team1);
			if (temp < min)
				min = temp;

			return;
		}
		for (int i = n; i < N; i++) {
			if (visited[i] == 0) {
				visited[i] = 1;
				dfs(d + 1, i);
				visited[i] = 0;
			}
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int test = 0; test < T; test++) {
			min = 2123456789;
			N = sc.nextInt();
			map = new int[N][N];
			visited = new int[N];
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					map[i][j] = sc.nextInt();
				}
			}

			dfs(0, 0);

			System.out.printf("#%d %d\n",test+1,min);
		}
	}
}
