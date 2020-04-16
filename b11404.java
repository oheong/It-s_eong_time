import java.util.Scanner;

public class b11404 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int max = 2123456789;
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[][] map = new int[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j)
					continue;
				map[i][j] = max;
			}
		}
		for (int i = 0; i < m; i++) {
			int s = sc.nextInt();
			int e = sc.nextInt();
			int c = sc.nextInt();
			if (c < map[s - 1][e - 1])
				map[s - 1][e - 1] = c;
		}

		for (int k = 0; k < n; k++) { // 경유
			for (int i = 0; i < n; i++) { // 시작
				if (k == i)
					continue;
				for (int j = 0; j < n; j++) { // 도착
					if (k == j || j == i)
						continue;

					if (map[i][k] != max && map[k][j] != max && map[i][j] > map[i][k] + map[k][j]) {
						map[i][j] = map[i][k] + map[k][j];
					}
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 2123456789)
					map[i][j] = 0;
				System.out.printf("%d ", map[i][j]);
			}
			System.out.println();
		}
	}
}
