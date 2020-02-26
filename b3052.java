import java.util.Scanner;

public class b3052 {
	static int[] map = new int[42];

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		for (int i = 0; i < 10; i++) {
			int a = sc.nextInt();
			map[a % 42]++;
		}
		int ans = 0;
		for (int i = 0; i < 42; i++) {
			if (map[i] != 0)
				ans++;
		}
		System.out.println(ans);
	}
}
