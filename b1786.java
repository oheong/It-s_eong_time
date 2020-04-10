// KMP 문자열 알고리즘
import java.util.Scanner;

public class b1786 {
	static String T, P;
	static int total;
	static int[] ans, pi;

	static void get_Pi() {
		char[] pt = P.toCharArray();
		int j = 0;
		for (int i = 1; i < P.length(); i++) {
			while (0 < j && pt[i] != pt[j])
				j = pi[j - 1];
			if (pt[i] == pt[j])
				pi[i] = ++j;
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		T = sc.nextLine();
		P = sc.nextLine();
		pi = new int[P.length()];
		ans = new int[T.length()];

		get_Pi();

		char[] tempT = T.toCharArray();
		char[] tempP = P.toCharArray();
		int j = 0;
		for (int i = 0; i < T.length(); i++) {
			while (0 < j && tempT[i] != tempP[j])
				j = pi[j - 1];
			if (tempT[i] == tempP[j]) {
				if (j == P.length() - 1) {
					ans[total++] = i - P.length() + 2;
					j = pi[j];
				} else
					j++;
			}
		}
		System.out.println(total);
		for (int i = 0; i < total; i++)
			System.out.println(ans[i]);
	}
}
