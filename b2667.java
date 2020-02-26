import java.util.Arrays;
import java.util.Scanner;

public class b2667 {
	static int N;
	static int[][] map;
	static int[] ans, dy = { 0, 0, 1, -1 }, dx = { 1, -1, 0, 0 };

	static void dfs(int y, int x, int cnt) {
		if (y < 0 || N <= y || x < 0 || N <= x)
			return;
		if (map[y][x] == cnt || map[y][x] == 0)
			return;
		ans[cnt]++;
		// System.out.println(ans[cnt-2]);
		map[y][x] = cnt;
		for (int i = 0; i < 4; i++) {
			dfs(y + dy[i], x + dx[i], cnt);
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		map = new int[N][N];
		ans = new int[N * N];
		for (int i = 0; i < N; i++) {
			String str = sc.next();
			for (int j = 0; j < N; j++) {
				map[i][j] = str.charAt(j) - '0';
			}
		}
		int count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 1) {
					dfs(i, j, count + 2);
					count++;
				}
			}
		}
		Arrays.sort(ans);
		System.out.println(count);
		for (int i = ans.length - count; i < ans.length; i++) {
			if (ans[i] == 0)
				continue;
			System.out.println(ans[i]);
		}
	}
}
