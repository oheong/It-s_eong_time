import java.util.Scanner;

public class b17135 {
	static int N, M, D, max;
	static int[][] realMap, map, visited;
	static int f = -1, r = -1;
	static int[] by = { 0, -1, 0 }, bx = { -1, 0, 1 };

	static class Queue {
		int y;
		int x;
		int step;
	}

	static Queue[] q;

	static void enQ(int y, int x, int step) {
		r++;
		Queue temp = new Queue();
		temp.y = y;
		temp.x = x;
		temp.step = step;
		q[r] = temp;
	}

	static void deQ() {
		f++;
	}

	static Queue peek() {
		return q[f + 1];
	}

	static int empty() {
		if (r == f)
			return 1;
		else
			return 0;
	}

	static void falling(int turn) { // 한 턴 끝나고 적들이 떨어지는 것
		for (int i = N - 1; turn < i; i--) {
			for (int j = 0; j < M; j++) {
				map[i][j] = map[i - 1][j];
			}
		}
		for (int j = 0; j < M; j++)
			map[turn][j] = 0;
	}

	static void copy() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++)
				map[i][j] = realMap[i][j];
		}
	}

	static void init() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				visited[i][j] = 0;
			}
		}
	}

	static void print() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				System.out.printf("%d ", visited[i]);
			}
			System.out.println();
		}
	}

	static void bfs(int y, int x) {
		f = r = -1;
		enQ(y, x, 0);
		while (empty() == 0) {
			int ty = peek().y;
			int tx = peek().x;
			int tstep = peek().step;
			deQ();
			if (tstep == D)
				return;
			for (int i = 0; i < 3; i++) {
				int ny = ty + by[i];
				int nx = tx + bx[i];
				if (0 <= ny && ny < N && 0 <= nx && nx < M && visited[ny][nx] == 0) {
					if (map[ny][nx] == 1 || map[ny][nx] == 9) { // 적이다
						map[ny][nx] = 9;
						return;
					}

					else { // 적이 아니다
						visited[ny][nx] = 1;
						enQ(ny, nx, tstep + 1);
					}
				}
			}
		}
	}

	static int counting() {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 9) {
					cnt++;
					map[i][j] = 0;
				}
			}
		}
		return cnt;
	}

	static void dfs(int d, int n) {
		if (d == 3) {
			int temp = 0;
			copy();
			for (int turn = 0; turn < N; turn++) {
				for (int i = 0; i < M; i++) {
					if (realMap[N][i] == 1) { // 공격 시작
						bfs(N, i);
						init();
					}
				}
				temp += counting();
				falling(turn);
			}
			if (max < temp)
				max = temp;
			return;
		}
		for (int i = n; i < M; i++) {
			if (realMap[N][i] == 0) {
				realMap[N][i] = 1;
				dfs(d + 1, i + 1);
				realMap[N][i] = 0;
			}
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		N = sc.nextInt();
		M = sc.nextInt();
		D = sc.nextInt();
		realMap = new int[N + 1][M];
		map = new int[N][M];
		visited = new int[N][M];
		q = new Queue[N * M * D];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				realMap[i][j] = sc.nextInt();
			}
		}
		dfs(0, 0);
		System.out.println(max);
	}
}