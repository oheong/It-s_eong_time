import java.util.Scanner;

public class b1592 {
	static int N, M, L;
	static int[] map;
	static int count, ans;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		L = sc.nextInt();

		map = new int[N];
		while (true) {
			int temp = count % N;
			map[temp]++;
			if (map[temp] == M)
				break;

			if (map[temp] % 2 == 0)
				count += L;
			else {
				count -= L;
				if (count < 0)
					count += N;
			}
			ans++;
		}
		System.out.println(ans);
	}
}
