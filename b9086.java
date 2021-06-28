package algorithm;

import java.util.Scanner;

public class b9086 {
	static int N;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		for (int i = 0; i < N; i++) {
			String str = sc.next();
			System.out.println(str.charAt(0) + "" + str.charAt(str.length() - 1));
		}
	}
}
