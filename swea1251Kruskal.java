import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class swea1251Kruskal {
	static int N;
	static double E;
	static int[] p;
	static long[][] map;

	static void setting() {
		for (int i = 0; i < N; i++)
			p[i] = i;
	}

	static int findSet(int x) {
		if (p[x] == x)
			return x;
		return findSet(p[x]);
	}

	static void union(int d, int j) {
		d = findSet(d);
		j = findSet(j);
		if (d != j)
			p[j] = p[d];
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int test = 0; test < T; test++) {
			N = sc.nextInt();
			p = new int[N];
			map = new long[N * (N - 1) / 2][3];
			long[][] temp = new long[2][N];
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < N; j++) {
					temp[i][j] = sc.nextInt();
				}
			}
			E = sc.nextDouble();
			int cnt = 0;
			for (int i = 0; i < N; i++) {
				for (int j = i + 1; j < N; j++) {
					map[cnt][0] = i;
					map[cnt][1] = j;
					map[cnt++][2] = (long) (Math.pow(temp[0][i] - temp[0][j], 2)
							+ Math.pow(temp[1][i] - temp[1][j], 2));
				}
			}
			Arrays.sort(map, new Comparator<long[]>() {
				public int compare(long[] o1, long[] o2) {
					return Long.compare(o1[2], o2[2]); // 이런거도있구나,,
				}
			});
			setting();
			long ans = 0;
			int count = 0;
			for (int i = 0; i < map.length; i++) {
				int a = findSet((int) map[i][0]);
				int b = findSet((int) map[i][1]);
				if (a == b)
					continue;
				count++;
				union(a, b);
				ans += map[i][2];
				if (count == N - 1)
					break;
			}
			System.out.println("#" + (test + 1) + " " + Math.round(ans * E)); // ha,,
		}
	}
}
