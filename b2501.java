import java.util.Scanner;

public class b2501 {
	static int N, K, ans;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		K = sc.nextInt();
		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			if (N % i == 0)
				cnt++;
			if (cnt == K) {
				ans = i;
				break;
			}
		}
		System.out.println(ans);
	}
}