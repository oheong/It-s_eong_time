package algorithm;

import java.util.Scanner;

public class b1748 {
	static int N;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		long sum = 0;
		for (int i = 1; i <= N; i++) {
			if (i < 10)
				sum += 1;
			else if (10 <= i && i < 100)
				sum += 2;
			else if (100 <= i && i < 1000)
				sum += 3;
			else if (1000 <= i && i < 10000)
				sum += 4;
			else if (10000 <= i && i < 100000)
				sum += 5;
			else if (100000 <= i && i < 1000000)
				sum += 6;
			else if (1000000 <= i && i < 10000000)
				sum += 7;
			else if (10000000 <= i && i < 100000000)
				sum += 8;
			else if (i == 100000000)
				sum += 9;
		}
		System.out.println(sum);
	}
}
