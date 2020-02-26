import java.util.Scanner;

public class b2804 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String A = sc.next(); // 가로
		String B = sc.next(); // 세로

		char cross;
		int sy = 0, sx = 0;
		int flag = 0;
		for (int i = 0; i < A.length(); i++) {
			for (int j = 0; j < B.length(); j++) {
				if (A.charAt(i) == B.charAt(j)) {
					cross = A.charAt(i);
					flag = 1;
					sy = j;
					sx = i;
					break;
				}
			}
			if (flag == 1)
				break;
		}
		char[][] map = new char[B.length()][A.length()];
		for (int i = 0; i < B.length(); i++) {
			for (int j = 0; j < A.length(); j++) {
				map[i][j] = '.';
			}
		}

		for (int i = 0; i < B.length(); i++)
			map[i][sx] = B.charAt(i);

		for (int i = 0; i < A.length(); i++)
			map[sy][i] = A.charAt(i);

		for (int i = 0; i < B.length(); i++) {
			for (int j = 0; j < A.length(); j++) {
				System.out.print(String.format("%c", map[i][j]));
			}
			System.out.println();
		}
	}
}
