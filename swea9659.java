import java.util.Scanner;

public class swea9659 {
	static int mod = 998244353;
	static int N, M;
	static int[][] is;
	static int[] x;
	static long[] f;

	static void init() {
		for (int i = 0; i <= N; i++)
			f[i] = 0;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int test = 0; test < T; test++) {
			N = sc.nextInt();
			is = new int[N + 5][3];
			f = new long[N + 5];
			for (int i = 2; i <= N; i++) {
				is[i][0] = sc.nextInt();
				is[i][1] = sc.nextInt();
				is[i][2] = sc.nextInt();
			}

			M = sc.nextInt();
			x = new int[M + 5];
			for (int i = 1; i <= M; i++)
				x[i] = sc.nextInt();

			System.out.print("#" + (test + 1));
			for (int m = 1; m <= M; m++) {
				f[0] = 1;
				f[1] = x[m];
				for (int n = 2; n <= N; n++) {
					if (is[n][0] == 1) {
						f[n] = f[is[n][1]] % mod + f[is[n][2]] % mod;
					}

					else if (is[n][0] == 2) {
						f[n] = is[n][1] % mod * f[is[n][2]] % mod;
					}

					else if (is[n][0] == 3) {
						f[n] = f[is[n][1]] % mod * f[is[n][2]] % mod;
					}
				}
				System.out.print(" " + f[N] % mod);
				init();
			}
			System.out.println();
		}
	}
}

// 11/14 런타임에러
