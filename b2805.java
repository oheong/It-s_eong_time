import java.util.Arrays;
import java.util.Scanner;

public class b2805 {
	static int N, M;
	static long[] map;

	static long getNum(long num) {
		if (num <= 0)
			return 0;
		return num;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();

		map = new long[N];

		for (int i = 0; i < N; i++) {
			map[i] = sc.nextLong();
		}

		Arrays.sort(map);

		long min = 0;
		long max = map[N - 1];

		while (min <= max) {
			long mid = (max + min) / 2;

			long sum = 0;

			for (int i = 0; i < N; i++) {
				sum += getNum(map[i] - mid); // 자른 나무의 총 길이
			}

			if (M <= sum)
				min = mid + 1;
			else
				max = mid - 1;
		}

		System.out.println(max);
	}
}
