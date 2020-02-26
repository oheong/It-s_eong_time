import java.util.Scanner;

public class b2851 {
	static int[] map = new int[11];

	static int abs(int a) {
		if (a < 0)
			return -1 * a;
		else
			return a;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		for (int i = 1; i <= 10; i++) {
			int temp = sc.nextInt();
			map[i] = map[i - 1] + temp;
		}
		int ans = 0, min = 2123456789;
		for (int i = 0; i < 11; i++) {
			if (abs(map[i] - 100) <= min) {
				min = abs(map[i] - 100);
				ans = map[i];
			}
		}
		System.out.println(ans);
	}
}
