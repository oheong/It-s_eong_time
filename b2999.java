import java.util.Scanner;

public class b2999 {
	static int N;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String str = sc.next();

		N = str.length();
		int R = 0, C = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = i; j <= N; j++) {
				if (i * j == N) {
					R = i;
					C = j;
				}
			}
		}

		char[][] map = new char[R][C];

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				map[i][j] = str.charAt(j * R + i);
			}
		}
		StringBuffer sb = new StringBuffer();
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				//System.out.printf("%c ", map[i][j]);
				sb.append(map[i][j]);
			}
			//System.out.println();
		}
		System.out.println(sb);
	}
}
//66ÆÛ?