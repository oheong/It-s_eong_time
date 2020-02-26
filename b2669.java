import java.util.Scanner;

public class b2669 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[][] map = new int[102][102];
		for (int t = 0; t < 4; t++) {
			int a = sc.nextInt(); // y시작 2
			int b = sc.nextInt(); // x시작 3
			int c = sc.nextInt(); // y끝   5 
			int d = sc.nextInt(); // x끝   7

			for (int i = a; i <c; i++) {
				for (int j = b; j < d; j++) {
					map[i][j] = 1;
				}
			}
		}
		int sum = 0;
		for (int i = 0; i < map.length; i++) {
			for (int j = 0; j < map.length; j++) {
				if (map[i][j] == 1)
					sum++;
			}
		}
		System.out.println(sum);
	}
}
