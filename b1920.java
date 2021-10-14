import java.util.Arrays;
import java.util.Scanner;

public class b1920 {
	static int N, M;
	static int[] num;

	static int binarySearch(int left, int right, int n) {
		int mid = (left + right) / 2;

		if (n == num[mid])
			return 1;
		if (left > right)
			return 0;

		if (num[mid] < n)
			return binarySearch(mid + 1, right, n);

		else
			return binarySearch(left, mid - 1, n);
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();

		num = new int[N];

		for (int i = 0; i < N; i++) {
			num[i] = sc.nextInt();
		}
		Arrays.sort(num);

		M = sc.nextInt();

		for (int i = 0; i < M; i++) {
			int n = sc.nextInt();

			System.out.println(binarySearch(0, N - 1, n));
		}
	}
}
