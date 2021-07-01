package algorithm;

import java.util.Scanner;

public class b10808 {
	static int[] map = new int[26];

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();
		for (int i = 0; i < str.length(); i++) {
			map[str.charAt(i) - 'a']++;
		}
		for (int i = 0; i < map.length; i++)
			System.out.print(map[i] + " ");
	}
}
