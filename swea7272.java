import java.util.Scanner;

public class swea7272 {
	static int N;
	static String ans;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		for (int test = 0; test < N; test++) {
			String a = sc.next();
			String b = sc.next();

			char[] charA = a.toCharArray();
			char[] charB = b.toCharArray();
			ans = "SAME";
			if (charA.length != charB.length)
				ans = "DIFF";
			else {
				for (int i = 0; i < charA.length; i++) {
					if (charA[i] == 'B' && charB[i] == 'B') {
						continue;
					} else if ((charA[i] == 'A' || charA[i] == 'D' || charA[i] == 'O' || charA[i] == 'P' || charA[i] == 'Q'
							|| charA[i] == 'R')
							&& (charB[i] == 'A' || charB[i] == 'D' || charB[i] == 'O' || charB[i] == 'P'
									|| charB[i] == 'Q' || charB[i] == 'R')) {
						continue;
					} else if ((charA[i] == 'C' || charA[i] == 'E' || charA[i] == 'F' || charA[i] == 'G' || charA[i] == 'H'
							|| charA[i] == 'I' || charA[i] == 'J' || charA[i] == 'K' || charA[i] == 'L'
							|| charA[i] == 'M' || charA[i] == 'N' || charA[i] == 'S' || charA[i] == 'T'
							|| charA[i] == 'U' || charA[i] == 'V' || charA[i] == 'W' || charA[i] == 'X'
							|| charA[i] == 'Y' || charA[i] == 'Z')
							&& (charB[i] == 'C' || charB[i] == 'E' || charB[i] == 'F' || charB[i] == 'G'
									|| charB[i] == 'H' || charB[i] == 'I' || charB[i] == 'J' || charB[i] == 'K'
									|| charB[i] == 'L' || charB[i] == 'M' || charB[i] == 'N' || charB[i] == 'S'
									|| charB[i] == 'T' || charB[i] == 'U' || charB[i] == 'V' || charB[i] == 'W'
									|| charB[i] == 'X' || charB[i] == 'Y' || charB[i] == 'Z')) {
						continue;
					} else
						ans = "DIFF";
				}
			}
			System.out.println(String.format("#%d %s", test + 1, ans));
		}
	}
}
