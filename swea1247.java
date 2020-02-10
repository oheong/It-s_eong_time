import java.util.Scanner;

public class swea1247 {
	static int N, T;
	static int homeY, homeX, workY, workX;
	static int[] visited;
	static Map[] m;
	static int min;

	static class Map {
		int y;
		int x;
	}

	static int abs(int a) {
		if (a < 0)
			return -1 * a;
		else
			return a;
	}

	static void dfs(int d, int y, int x, int distance) {
		if (d == N) {
			distance += abs(y - homeY);
			distance += abs(x - homeX);
			if (distance < min)
				min = distance;
			return;
		}
		for (int i = 0; i < N; i++) {
			if (visited[i] == 0) {
				visited[i] = d + 1;
				dfs(d + 1, m[i].y, m[i].x, distance + abs(y - m[i].y) + abs(x - m[i].x));
				visited[i] = 0;
			}
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		T = sc.nextInt();
		for (int test = 0; test < T; test++) {
			N = sc.nextInt();
			workX = sc.nextInt();
			workY = sc.nextInt();
			homeX = sc.nextInt();
			homeY = sc.nextInt();
			m = new Map[N];
			visited = new int[N];
			for (int i = 0; i < N; i++) {
				Map mm = new Map();
				mm.x = sc.nextInt();
				mm.y = sc.nextInt();
				m[i] = mm;
			}
			min = 2123456789;
			dfs(0, workY, workX, 0);
			System.out.println(String.format("#%d %d", test + 1, min));
		}
	}
}
