import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class swea4534트리흑백색칠 {
	static int N;
	static List<Integer>[] map;
	static long[][] memo;
	static int MOD = 1_000_000_007;

	static long dfs(int d, int color, int parent) {
		// 이미 저장된 값이 있다면 다시 계산안하고 return;
		if (memo[color][d] != 0)
			return memo[color][d];
		long ret = -1;

		if (color == 0) { // 흰색이면
			for (int i = 0; i < map[d].size(); i++) {
				// 내랑 연결되어있는거 전부 다 돌면서 부모 노드가 아닌거만 골라가라
				if (map[d].get(i) != parent) {
					ret *= dfs(map[d].get(i), 0, d) + dfs(map[d].get(i), 1, d);
					ret %= MOD;
				}
			}
		}

		else {
			for (int i = 0; i < map[d].size(); i++) {
				// 내랑 연결되어있는거 전부 다 돌면서 부모 노드가 아닌거만 골라가라
				if (map[d].get(i) != parent) {
					ret *= dfs(map[d].get(i), 0, d);
					ret %= MOD;
				}
			}
		}
		memo[color][d] = ret % MOD;
		return ret % MOD;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int test = 0; test < T; test++) {
			N = sc.nextInt();
			map = new ArrayList[N];
			memo = new long[2][N];
			for (int i = 0; i < N; i++) {
				map[i] = new ArrayList<>();
			}
			for (int i = 0; i < N - 1; i++) {
				int a = sc.nextInt();
				int b = sc.nextInt();
				map[a - 1].add(b - 1);
				map[b - 1].add(a - 1);
			}

			long ans = (dfs(0, 0, -1) + dfs(0, 1, -1)) % MOD;
			System.out.println("#" + (test + 1) + " " + ans);
		}
	}
}
