import java.util.Scanner;

public class b15683 {
	static int[][] map = new int[8][8];
	static int[][] copy_map = new int[8][8];
	static int N, M, min = 2123456789, how_many_cctv = 0;

	
	
	static void run_cctv(int cctv) {
		// cctv°¡µ¿
	}

	static void dfs(int d) {
	}

	static void copy() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				copy_map[i][j] = map[i][j];
			}
		}
	}

	static int counting() {
		int count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (copy_map[i][j] == 0)
					count++;
			}
		}
		return count;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				map[i][j] = sc.nextInt();
				if (1 <= map[i][j] && map[i][j] <= 5)
					how_many_cctv++;
			}
		}

	}
}
