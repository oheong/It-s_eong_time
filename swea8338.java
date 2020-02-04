import java.util.Scanner;

public class swea8338 {
	static int N, max;
	static int[] num;
	static int[] calc;

	static void dfs(int d, int ans) {
		if (d == N) {
			if(max<ans)max=ans;
			return;
		}
		dfs(d + 1, ans + num[d]);
		dfs(d + 1, ans * num[d]);
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int TC = sc.nextInt();
		for (int test = 1; test <= TC; test++) {
			N = sc.nextInt();
			num = new int[N];
			calc = new int[N];
			for (int i = 0; i < N; i++) {
				num[i] = sc.nextInt();
			}
			dfs(1, num[0]);
			System.out.println(String.format("#%d %d", test, max));
			max = 0;
		}
	}
}
