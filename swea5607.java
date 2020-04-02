import java.util.Scanner;

public class swea5607 {
	static int N, R, SIZE = 1000000;
	static long modNum = 1234567891;
	static long[] fac = new long[SIZE + 1];
	static long[] ferma = new long[SIZE + 1];

	static long power(long x, long y) {
		long ret = 1;
		while (y > 0) {
			if (y % 2 == 1) {
				ret *= x;
				ret %= modNum;
			}
			x *= x;
			x %= modNum;
			y /= 2;
		}
		return ret;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		fac[1] = 1;
		for (int i = 2; i <= SIZE; i++)
			fac[i] = (fac[i - 1] * i) % modNum;
		ferma[SIZE] = power(fac[SIZE], modNum - 2);
		for (int i = SIZE - 1; 0 < i; i--)
			ferma[i] = (ferma[i + 1] * (i + 1)) % modNum;

		for (int test = 0; test < T; test++) {
			N = sc.nextInt();
			R = sc.nextInt();

			long r = (fac[N] * ferma[N - R]) % modNum;
			r = (r * ferma[R]) % modNum;
			System.out.println("#" + (test + 1) + " " + r);
		}
	}
}
