import java.util.Arrays;
import java.util.Scanner;

public class swea4408 {
	static int N;

	static int ban(int n) {
		if (n % 2 == 0)
			return n / 2;
		else
			return (n + 1) / 2;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		int[] map = new int[201];
		for (int test = 0; test < T; test++) {
			N = sc.nextInt();
			for (int i = 0; i < N; i++) {
				int s = sc.nextInt();
				int e = sc.nextInt();
				if (e < s) {
					int temp = s;
					s = e;
					e = temp;
				}
				s = ban(s);
				e = ban(e);
				for (int j = s; j <= e; j++)
					map[j]++;
			}
			Arrays.sort(map);
			System.out.println(String.format("#%d %d", test + 1, map[200]));
		}
	}
}
