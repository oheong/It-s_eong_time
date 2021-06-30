package algorithm;

import java.util.Scanner;

public class b14719 {
	static int H, W, ans;
	static int[] wall;
	static int[][] map;
	static boolean flag;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		H = sc.nextInt();
		W = sc.nextInt();
		wall = new int[W];
		map = new int[H][W];
		for (int i = 0; i < W; i++) {
			wall[i] = sc.nextInt();
		}
		for (int j = 0; j < W; j++) {
			for (int i = 0; i < wall[j]; i++) {
				map[H - i - 1][j] = 1;
			}
		}
		for (int i = H - 1; 0 <= i; i--) {
			flag = false;
			int cnt = 0;
			for (int j = 0; j < W; j++) {
				if (map[i][j] == 1 && flag == false)
					flag = true;

				else if (map[i][j] == 0 && flag == true)
					cnt++;

				else if (map[i][j] == 1 && flag == true) {
					ans += cnt;
					cnt = 0;
				}
			}
		}
		System.out.println(ans);
	}
}
