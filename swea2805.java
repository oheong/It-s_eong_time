import java.util.Scanner;

public class swea2805 {
	static int TC, N;
	static int[][] map;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		TC = sc.nextInt();
		for (int test = 0; test < TC; test++) {
			N = sc.nextInt();
			map = new int[N][N];
			for (int i = 0; i < N; i++) {
				String temp = sc.next();
				for (int j = 0; j < N; j++) {
					map[i][j] = temp.charAt(j) - '0';
				}
			}
			int start = N / 2;
			int end = N / 2;
			int ans = 0;
			for (int i = 0; i < N; i++) {
				for (int j = start; j <= end; j++) {
					ans += map[i][j];
				}
				if (i < N / 2) {
					start--;
					end++;
				}

				else {
					start++;
					end--;
				}
			}
			System.out.println(String.format("#%d %d", test + 1, ans));
		}
	}
}
