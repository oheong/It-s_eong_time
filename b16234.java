import java.util.Scanner;

public class b16234 {
	static int N, L, R, f, r, ans, flag;
	static int[][] map, visited;
	static int[] by = { 0, 0, 1, -1 }, bx = { 1, -1, 0, 0 };

	static class Queue {
		int y;
		int x;
	}

	static Queue[] q;

	static void enQ(int y, int x) {
		r++;
		Queue temp = new Queue();
		temp.y = y;
		temp.x = x;
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

	static int abs(int a) {
		if (a < 0)
			return -1 * a;
		else
			return a;
	}

	static void spread(int avg) {
		flag = 1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j] == 1) {
					map[i][j] = avg;
					visited[i][j] = 2;
				}
			}
		}
	}

	static void bfs(int y, int x) {
		f = r = -1;
		enQ(y, x);
		visited[y][x] = 1;
		int count = 1;
		int sum = map[y][x];
		while (empty() == 0) {
			int ty = peek().y;
			int tx = peek().x;
			deQ();
			for (int i = 0; i < 4; i++) {
				int ny = ty + by[i];
				int nx = tx + bx[i];
				if (0 <= ny && ny < N && 0 <= nx && nx < N && visited[ny][nx] == 0
						&& L <= abs(map[ty][tx] - map[ny][nx]) && abs(map[ty][tx] - map[ny][nx]) <= R) {
					enQ(ny, nx);
					visited[ny][nx] = 1;
					count++;
					sum += map[ny][nx];
				}
			}
		}
		if (count > 1) {
			spread(sum / count);
		} else
			visited[y][x] = 2;
	}

	static void init() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visited[i][j] = 0;
			}
		}
	}

	static void dfs(int d) {
		if (2000 < d)
			return;
		if (ans < d)
			ans = d;
		flag = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j] == 0) {
					bfs(i, j);
				}
			}
		}
		if (flag == 0)
			return;
		else {
			init();
			dfs(d + 1);
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		L = sc.nextInt();
		R = sc.nextInt();
		map = new int[N][N];
		visited = new int[N][N];
		q = new Queue[N * N];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] = sc.nextInt();
			}
		}
		dfs(0);
		System.out.println(String.format("%d", ans));
	}
}
