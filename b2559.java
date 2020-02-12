import java.util.Scanner;

public class b2559 {
	static int N, K;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		N = sc.nextInt();
		K = sc.nextInt();

		int[] map = new int[N];

		for (int i = 0; i < N; i++) {
			map[i] = sc.nextInt();
		}
		int max = -2123456789;
		for (int i = 0; i < N - K + 1; i++) {
			int sum = 0;
			for (int k = 0; k < K; k++) {
				sum += map[i + k];
			}
			if (max < sum)
				max = sum;
		}
		System.out.println(max);
	}
}
