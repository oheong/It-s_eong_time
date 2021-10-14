
public class 행렬테두리회전하기 {

	static int[][] map;

	static void copy(int rows, int columns) {
		map = new int[rows][columns];
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				map[i][j] = i * columns + j + 1;
			}
		}
	}

	static public int[] solution(int rows, int columns, int[][] queries) {
		int[] answer = new int[queries.length];

		copy(rows, columns);

		for (int index = 0; index < queries.length; index++) {
			int min = 2123456789;
			int y1 = queries[index][0] - 1;
			int x1 = queries[index][1] - 1;
			int y2 = queries[index][2] - 1;
			int x2 = queries[index][3] - 1;

			int temp = map[y1][x1];
			for (int i = y1 + 1; i <= y2; i++) {
				map[i - 1][x1] = map[i][x1];
				if (map[i - 1][x1] < min)
					min = map[i - 1][x1];
			}
			for (int j = x1 + 1; j <= x2; j++) {
				map[y2][j - 1] = map[y2][j];
				if (map[y2][j - 1] < min)
					min = map[y2][j - 1];
			}
			for (int i = y2 - 1; y1 <= i; i--) {
				map[i + 1][x2] = map[i][x2];
				if (map[i + 1][x2] < min)
					min = map[i + 1][x2];
			}
			for (int j = x2 - 1; x1 <= j; j--) {
				map[y1][j + 1] = map[y1][j];
				if (map[y1][j + 1] < min)
					min = map[y1][j + 1];
			}
			map[y1][x1 + 1] = temp;
			if (map[y1][x1 + 1] < min)
				min = map[y1][x1 + 1];

			answer[index] = min;
		}

		return answer;
	}

	public static void main(String[] args) {

		int[][] q = { { 2, 2, 5, 4 }, { 3, 3, 6, 6 }, { 5, 1, 6, 3 } };
		int rows = 6;
		int columns = 6;

		int[] ans = solution(rows, columns, q);
		for (int i = 0; i < ans.length; i++)
			System.out.println(ans[i]);
	}
}
