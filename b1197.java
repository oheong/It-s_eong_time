import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class b1197 {
	static int V, E;
	static int[] p;

	static void setting() {
		for (int i = 1; i <= V; i++)
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
			p[j] = d;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		V = sc.nextInt();
		E = sc.nextInt();
		p = new int[V + 1];
		int[][] map = new int[E][3];
		for (int i = 0; i < E; i++) {
			map[i][0] = sc.nextInt();
			map[i][1] = sc.nextInt();
			map[i][2] = sc.nextInt();
		}
		setting();
		Arrays.sort(map, new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2) {
				return o1[2] - o2[2];
			}
		});

		long ans = 0;
		int count = 0;
		for (int i = 0; i < E; i++) {
			int a = findSet(map[i][0]);
			int b = findSet(map[i][1]);
			if (a == b)
				continue;

			count++;
			ans += map[i][2];
			union(a, b);
			if (count == V - 1)
				break;
		}
		System.out.println(ans);
	}
} // 9%????????????????????????
