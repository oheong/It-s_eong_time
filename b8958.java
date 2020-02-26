import java.util.Scanner;

public class b8958 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int test = 0; test < T; test++) {
			String str = sc.next();
			int ans = 0, count = 0;
			for (int i = 0; i < str.length(); i++) {
				if (str.charAt(i) == 'O') {
					count++;
					ans += count;
				} else
					count = 0;
			}
			System.out.println(ans);
		}
	}
}
