import java.util.*;

class Solution {
	static int[][] map;
	static int[] by = { 1, 0, -1 }, bx = { 0, 1, -1 };

	public int[] solution(int n) {

		map = new int[n][n];

		int cnt = 1;
		int N = n;
		int y = 0, x = 0;
		int dir = 0;

		while (cnt <= N * (N + 1) / 2) {
			for (int i = 0; i < n; i++) {
				map[y][x] = cnt++;
				if (i != n - 1) {
					y += by[dir % 3];
					x += bx[dir % 3];
				} else {
					if (dir % 3 == 0)
						x += bx[1];
					else if (dir % 3 == 1) {
						y += by[2];
						x += bx[2];
					} else
						y += by[0];
				}
			}
			dir++;
			n--;
		}

		int[] answer = new int[N * (N + 1) / 2];
		cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= i; j++) {
				answer[cnt++] = map[i][j];
			}
		}
		return answer;
	}
}
