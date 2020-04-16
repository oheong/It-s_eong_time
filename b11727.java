import java.util.Scanner;

public class b11727 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] map = new int[n + 1];
		map[0] = 1;
		map[1] = 1;
		for (int i = 2; i <= n; i++) {
			map[i] = map[i - 1] % 10007 + (map[i - 2] * 2) % 10007;
		}
		System.out.println(map[n] % 10007);
	}
}
