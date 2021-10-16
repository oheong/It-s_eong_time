import java.util.Arrays;
import java.util.Scanner;

public class b1654 {

	static int K, N;
	static int[] map;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		K = sc.nextInt();
		N = sc.nextInt();

		map = new int[K];

		for (int i = 0; i < K; i++) {
			map[i] = sc.nextInt();
		}

		Arrays.sort(map);

		long min = 1;
		long max = map[K - 1];

		while (min <= max) {

			long mid = (min + max) / 2;

			long sum = 0; // 나올수 있는 작대기 갯수

			for (int i = 0; i < map.length; i++) {
				sum += map[i] / mid;
			}

			if (N > sum)
				max = mid - 1;
			else
				min = mid + 1;
		}
		System.out.println(max);
	}
}
