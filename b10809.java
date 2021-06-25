package algorithm;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;

public class b10809 {
	static String str;
	static List<Character> list = new ArrayList<>();
	static HashMap<Character, Integer> hashmap = new HashMap<>();

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		str = sc.next();
		for (int i = 0; i < str.length(); i++) {
			if (!hashmap.containsKey(str.charAt(i))) {
				hashmap.put(str.charAt(i), i);
			}
		}

		for (int i = 0; i < 26; i++) {
			char c = (char) (i + 97);
			if (hashmap.containsKey(c))
				System.out.print(hashmap.get(c) + " ");
			else
				System.out.print("-1 ");
		}
	}
}
