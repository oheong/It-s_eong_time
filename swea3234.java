import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class swea3234 {
	static int N, ans;
	static int[] chu, visited;
	static List<Integer> right, left;
	static int nPm[] = new int[10];

	static void get_nPm() {
		nPm[0] = 1;
		for (int i = 1; i < nPm.length; i++) {
			nPm[i] = nPm[i - 1] * i;
		}
	}

	static void RightOrLeft(int d, int l, int r) {
		if (l < r)
			return;
		if (d == N) {
			ans++;
			return;
		}
		RightOrLeft(d + 1, l + chu[visited[d] - 1], r);
		RightOrLeft(d + 1, l, r + chu[visited[d] - 1]);
	}

	static void dfs(int d) {
		if (d == N) {
			RightOrLeft(0, 0, 0);
			return;
		}

		for (int i = N - 1; 0 <= i; i--) {
			if (visited[i] == 0) {
				visited[i] = d + 1;
				dfs(d + 1);
				visited[i] = 0;
			}
		}

	}

	static int sum() {
		int s = 0;
		for (int i = 0; i < N; i++)
			s += chu[i];
		return s;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		get_nPm();
		for (int test = 0; test < T; test++) {
			N = sc.nextInt();
			chu = new int[N];
			visited = new int[N];
			right = new ArrayList<Integer>();
			left = new ArrayList<Integer>();
			for (int i = 0; i < N; i++) {
				chu[i] = sc.nextInt();
			}
			ans = 0;
			Arrays.sort(chu);

			dfs(0);

			System.out.printf("#%d %d\n", test + 1, ans);
		}
	}
}
