import java.util.Scanner;

//런타임에러 쉬먀

public class swea9088 {
	public static void init(int arr[], int max) {
		for (int i = 0; i < max; i++)
			arr[i] = 0;
	}

	public static void main(String[] args) {
		int N, K;
		int[] dia = new int[10000];//

		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for (int test = 0; test < T; test++) {
			int max = 0, ans = 0;
			N = sc.nextInt();
			K = sc.nextInt();
			for (int i = 0; i < N; i++) {
				int temp = sc.nextInt();
				dia[temp]++;
				if (max < temp)
					max = temp;
			}
			max++;
			for (int i = 0; i < max; i++) {
				if (dia[i] == 0)
					continue;
				ans += dia[i];
				if (K == 0) {
					dia[i] = 0;
					continue;
				}
				for (int k = 1; k < K; k++) {
					if (i + k < max) {
						ans += (dia[i] * dia[k + i]);
					}
				}
				dia[i] = 0;
			}

			System.out.println(String.format("#%d %d", test + 1, ans));
			// init(dia, max);
		}
	}
}
