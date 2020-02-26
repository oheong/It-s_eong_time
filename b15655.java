import java.util.Arrays;
import java.util.Scanner;

public class b15655 {
	static int N, M;
	static int[] map, visited;

	static void dfs(int d, int n) {
		if (d == M) {
			for (int i = 0; i < N; i++) {
				if (visited[i] == 1)
					System.out.print(String.format("%d ", map[i]));
			}
			System.out.println();
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
		N = sc.nextInt();
		M = sc.nextInt();
		map = new int[N];
		visited = new int[N];
		for (int i = 0; i < N; i++) {
			map[i] = sc.nextInt();
		}
		Arrays.sort(map);
		dfs(0, 0);
	}
}
