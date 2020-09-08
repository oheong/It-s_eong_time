import java.util.LinkedList;
import java.util.Queue;

public class kakao_18_프렌즈4블록 {
	static private class Point {
		int y;
		int x;
		char c;

		public Point(int y, int x, char c) {
			super();
			this.y = y;
			this.x = x;
			this.c = c;
		}
	}

	static char[][] map;

	static int falling(int n, int m) {
		int count = 0; // 터진애들이 있는지 없는지 체크
		Queue<Point> q = new LinkedList<Point>();
		for (int j = 0; j < m; j++) {
			for (int i = n - 1; 0 <= i; i--) { // 밑에서부터 훑어서 올라옴
				if (map[i][j] == '*')
					count++;
				else
					q.add(new Point(i, j, map[i][j]));
				map[i][j] = ' ';
			}
			// 다 했으니까 다시 넣어주기
			int y = n - 1;
			while (!q.isEmpty()) {
				int x = q.peek().x;
				char c = q.peek().c;
				q.remove();
				map[y--][x] = c;
			}
		}
		return count;
	}

	static void bomb(int n, int m, int[][] check) {
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < m - 1; j++) {
				if (map[i][j] == ' ')
					continue;
				if (map[i][j] == map[i][j + 1] && map[i][j] == map[i + 1][j] && map[i][j] == map[i + 1][j + 1]) {
					check[i][j] = 1;
					check[i][j + 1] = 1;
					check[i + 1][j] = 1;
					check[i + 1][j + 1] = 1;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (check[i][j] == 1) {
					map[i][j] = '*';
				}
				check[i][j] = 0;
			}
		}
	}

	static public int solution(int m, int n, String[] board) {
		int answer = 0;
		map = new char[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				map[i][j] = board[i].charAt(j);
			}
		} // 맵에 매핑 다 했음

		int[][] check = new int[n][m];
		while (true) {
			bomb(n, m, check);
			int tempNum = falling(n, m);
			if (tempNum != 0)
				answer += tempNum;
			else
				break;
		}
		return answer;
	}

	public static void main(String[] args) {
		int n = 5;
		int m = 4;
		String[] board = { "CCBDE", "AAADE", "AAABF", "CCBBF"};
//		String[] board = { "TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ" };
		System.out.println(solution(m, n, board));
	}
}
