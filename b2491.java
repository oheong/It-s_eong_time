import java.util.Scanner;

public class b2491 {
	static int N;
	static int[] map;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		map = new int[N];
		for (int i = 0; i < N; i++)
			map[i] = sc.nextInt();

		int ansUp = 1, ansDown = 1;
		int max = 0;

		for (int i = 0; i < N - 1; i++) {
			if (map[i] <= map[i + 1])
				ansUp++;
			else
				ansUp = 1;
			
			if (map[i] >= map[i + 1])
				ansDown++;
			else
				ansDown = 1;
			
			if (max < ansUp)
				max = ansUp;
			if (max < ansDown)
				max = ansDown;
		}
		System.out.println(max);
	}
}
