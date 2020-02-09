import java.util.Scanner;

public class b2567 {
	static int[][] map = new int[102][102];
	static int y, x;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		for (int n = 0; n < N; n++) {
			x = sc.nextInt();
			y = sc.nextInt();

			for (int i = y; i < y + 10; i++) {
				for (int j = x; j < x + 10; j++) {
					map[i][j] = 1;
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < 102; i++) {
			for (int j = 0; j < 102; j++) {
				if (map[i][j] != 0) {
					int count = 0;
					if (map[i + 1][j] == 0) count++;
					if (map[i - 1][j] == 0) count++;
					if (map[i][j + 1] == 0) count++;
					if (map[i][j - 1] == 0) count++;
					if (count >= 1) {
						ans++;
					}
					if (count >= 2) {
						ans++;
					}
				}
			}
		}
		System.out.println(ans);
	}
}
