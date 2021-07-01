package algorithm;

import java.util.Scanner;

public class b2576 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int sum = 0, min = 2123456789;
		for (int i = 0; i < 7; i++) {
			int temp = sc.nextInt();
			if (temp % 2 == 0)
				continue;
			if (temp < min)
				min = temp;
			sum += temp;
		}
		if (min != 2123456789) {
			System.out.println(sum);
			System.out.println(min);
		} else
			System.out.println(-1);
	}
}
