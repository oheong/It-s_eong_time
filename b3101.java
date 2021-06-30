package algorithm;

import java.util.HashMap;
import java.util.List;
import java.util.Scanner;

public class b3101 {
	static long ans, N, JUMP;
	static String str;
	static long half;

	static long makeNum(long y, long x) {
		long num = 0;

		long line = y + x + 1;// 내
		if (line <= N) {
			if (line % 2 == 0)
				num = (line * (line + 1) / 2) - x;
			else
				num = (line * (line - 1) / 2) + x + 1;
		}

		else {
			num = (N * (N - 1) / 2);
			long sadari = num;
			long samgak = (2 * N - line);

			if (samgak == 1)
				sadari--;
			else
				sadari -= samgak * (samgak + 1) / 2;
			num += sadari;
			num += N;
			if (line % 2 == 0)
				num += (y - (line - N - 1));
			else
				num += (x - (line - N - 1));
		}
		return num;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		JUMP = sc.nextInt();
		str = sc.next();
		long y = 0, x = 0;
		ans = 1;
		half = N * (N - 1) / 2 + N;
		for (int i = 0; i < JUMP; i++) {
			char c = str.charAt(i);
			if (c == 'U')
				ans += makeNum(--y, x);
			else if (c == 'R')
				ans += makeNum(y, ++x);
			else if (c == 'D')
				ans += makeNum(++y, x);
			else if (c == 'L')
				ans += makeNum(y, --x);
		}
		System.out.println(ans);
	}
}
// 7% 메모리초과 부들부들
// 시간초과 도랏나 
