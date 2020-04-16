import java.util.Scanner;

public class b9095 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] memo = new int[12];

		memo[1] = 1;
		memo[2] = 2;
		memo[3] = 4;
		for (int i = 4; i < 12; i++) {
			memo[i] = memo[i - 1] + memo[i - 2] + memo[i - 3];
		}
		int T = sc.nextInt();
		for (int test = 0; test < T; test++) {
			int n=sc.nextInt();
			System.out.println(memo[n]);
		}
	}
}
