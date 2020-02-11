import java.util.Scanner;

public class b2991 {
	static int A, B, C, D, E, P, M, N;

	static void init(int num, int[][] map, int s, int e) {
		int count = 1;
		while (true) {
			for (int i = 0; i < s; i++) {
				map[num][count++] = 1;
				if (count == map[0].length)
					return;
			}
			for (int i = 0; i < e; i++) {
				map[num][count++] = 2;
				if (count == map[0].length)
					return;
			}
		}
	}

	static int count(int[][] map, int num) {
		int cnt = 0;
		if (map[0][num] == 1)
			cnt++;
		if (map[1][num] == 1)
			cnt++;
		return cnt;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		A = sc.nextInt();
		B = sc.nextInt();
		C = sc.nextInt();
		D = sc.nextInt();
		P = sc.nextInt();
		M = sc.nextInt();
		N = sc.nextInt();
		int max = 0;
		if (max < P)
			max = P;
		if (max < M)
			max = M;
		if (max < N)
			max = N;
		int[][] map = new int[2][max *2];
		init(0, map, A, B);
		init(1, map, C, D);

		System.out.println(count(map, P));
		System.out.println(count(map, M));
		System.out.println(count(map, N));
	}
}
