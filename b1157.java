package algorithm;

import java.util.Scanner;

public class b1157 {
	static int[] map = new int[27];

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();
		for (int i = 0; i < str.length(); i++) {
			char c = str.charAt(i);
			if ('A' <= c && c <= 'Z') {
				map[c - 'A']++;
			} else if ('a' <= c && c <= 'z') {
				map[c - 'a']++;
			}
		}
		int max = -2123456789, jungbok = 0;
		char c = '&';
		for (int i = 0; i < map.length; i++) {
			if (max == map[i]) {
				jungbok++;
			} else if (max < map[i]) {
				max = map[i];
				jungbok = 0;
				c = (char) (i + 'A');
			}
		}
		if (jungbok == 0)
			System.out.println(c);
		else
			System.out.println("?");
	}
}
//51퍼 틀림 뭐냐이ㅓㄱ?!