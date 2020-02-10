import java.util.Arrays;
import java.util.Scanner;

public class b15654 {
	static int N, M;
	static int[] map, visited, ans;

	static void dfs(int d) {
		if (d == M) {
			for (int i = 0; i < M; i++) {
				System.out.print(String.format("%d ", ans[i]));
			}
			System.out.println();
			return;
		}
		for (int i = 0; i < N; i++) {
			if (visited[i] == 0) {
				visited[i] = 1;
				ans[d] = map[i];
				dfs(d + 1);
				visited[i] = 0;
			}
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		N = sc.nextInt();
		M = sc.nextInt();
		map = new int[N];
		visited = new int[N];
		ans = new int[M];
		for (int i = 0; i < N; i++) {
			map[i] = sc.nextInt();
		}
		Arrays.sort(map);

		dfs(0);

	}
}
