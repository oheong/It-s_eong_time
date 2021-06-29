package algorithm;

import java.util.HashMap;
import java.util.List;
import java.util.Scanner;

public class b3101 {
	static long ans, N, JUMP;
	static String str;
	static long half;
	static HashMap<Integer[], Integer> hashmap;

	static long makeNum(long y, long x) {
		long num = 0;
		long line = 0;
		if (y + x < N) {
			for (long i = 0; i < y + x; i++) {
				num += (i + 1);
				line = i + 1;
			}
			if ((y + x) % 2 == 0) // 올라오는
				num += (line - y + 1);
			else // 내려가는
				num += (y + 1);
		}

		else {
			num = half;
			for (long i = N + 1; i <= x + y; i++)
				num += (2 * N - i);
			if ((y + x) % 2 == 0) // 올라오는
				num += (N - y);
			else // 내려가는
				num += (N - x);
		}
		return num;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		JUMP = sc.nextInt();
		str = sc.next();
		hashmap = new HashMap<>();
		long y = 0, x = 0;
		ans = 1;
		half = N * (N - 1) / 2 + N;
		for (int i = 0; i < JUMP; i++) {
			char c = str.charAt(i);
			if (c == 'U') {
				y--;
				if(!hashmap.containsKey(sc)) {
					
				}
				ans += makeNum(y, x);
			}

			else if (c == 'R') {
				ans += makeNum(y, ++x);
			}

			else if (c == 'D') {
				ans += makeNum(++y, x);
			}

			else if (c == 'L') {
				ans += makeNum(y, --x);
			}
		}
		System.out.println(ans);
	}
}
// 7% 메모리초과 부들부들
// 시간초과 도랏나 
