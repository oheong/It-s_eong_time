
public class kakao_20_자물쇠와열쇠 {

	static int abs(int a) {
		if (a < 0)
			return -1 * a;
		return a;
	}

	static int check(int N, int M, int[][] copy_map) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (copy_map[M + i - 1][M + j - 1] == 0)
					return 0;
			}
		}
		return 1;
	}

	static void print(int[][] map) {
		for (int i = 0; i < map.length; i++) {
			for (int j = 0; j < map.length; j++) {
				System.out.printf("%d ", map[i][j]);
			}
			System.out.println();
		}
		System.out.println("=============================");
	}

	static void copy(int[][] map, int[][] copy_map, int N, int M) {
		for (int ii = 0; ii < N + (M * 2) - 2; ii++) {
			for (int jj = 0; jj < N + (M * 2) - 2; jj++) {
				copy_map[ii][jj] = map[ii][jj];
			}
		}
	}

	static public boolean solution(int[][] key, int[][] lock) {
		boolean answer = false;

		int M = key.length;
		int N = lock.length;

		int[][] map = new int[N + (M * 2) - 2][N + (M * 2) - 2];
		int[][] copy_map = new int[N + (M * 2) - 2][N + (M * 2) - 2];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[M + i - 1][M + j - 1] = lock[i][j];
			}
		}
		int[][] temp_key = new int[M][M];
		for (int lotation = 0; lotation < 4; lotation++) {

			for (int i = 0; i < N + M - 1; i++) {
				for (int j = 0; j < N + M - 1; j++) { // key가 움직이는 좌표
					
					// copy
					copy(map, copy_map, N, M);

					for (int y = 0; y < M; y++) {
						for (int x = 0; x < M; x++) {
							copy_map[i + y][j + x] ^= key[y][x];
						}
					}

//					print(copy_map);
					if (check(N, M, copy_map) == 1)
						return true;
				}
			}

			// 키 회전
			for (int i = 0; i < M; i++) {
				for (int j = 0; j < M; j++) {
					temp_key[i][j] = key[i][j];
				}
			}
			for (int i = 0; i < M; i++) {
				for (int j = 0; j < M; j++) {
					key[j][abs(M - i) - 1] = temp_key[i][j];
				}
			}
		}
		return answer;
	}

	public static void main(String[] args) {
		int[][] key = { { 0, 0, 0 }, { 1, 0, 0 }, { 0, 1, 1 } };
		int[][] lock = { { 1, 1, 1 }, { 1, 1, 0 }, { 1, 0, 1 } };
		System.out.println(solution(key, lock));
	}
}
