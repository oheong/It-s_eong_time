import java.util.Scanner;

public class b7576 {
	static int N, M;
	static int[][] map, visited;
	static int[] by = { 0, 0, -1, 1 }, bx = { -1, 1, 0, 0 };

	static class Queue {
		int y;
		int x;
	}

	static Queue[] q;
	static int f = -1, r = -1;

	static void enQ(int y, int x) {
		Queue t = new Queue();
		r++;
		t.y = y;
		t.x = x;
		q[r] = t;
	}

	static void deQ() {
		f++;
	}

	static int empty() {
		if (r == f)
			return 1;
		else
			return 0;
	}

	static Queue peek() {
		return q[f + 1];
	}

	static void bfs() {
		while (empty() == 0) {
			int ty = peek().y;
			int tx = peek().x;
			deQ();
			for (int i = 0; i < 4; i++) {
				int ny = ty + by[i];
				int nx = tx + bx[i];
				if (0 <= ny && ny < N && 0 <= nx && nx < M && map[ny][nx] == 0 && visited[ny][nx] == 0) {
					enQ(ny, nx);
					visited[ny][nx] = visited[ty][tx] + 1;
				}
			}
		}
	}

	static int count() {
		int max = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 1)
					continue;
				if (visited[i][j] > max)
					max = visited[i][j];
				if (map[i][j] == 0 && visited[i][j] == 0)
					return -1;
			}
		}

		if (max > 0)
			return max - 1;
		else
			return max;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		M = sc.nextInt();
		N = sc.nextInt();
		map = new int[N][M];
		visited = new int[N][M];
		q = new Queue[N * M];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				map[i][j] = sc.nextInt();
				if (map[i][j] == 1) {
					enQ(i, j);
					visited[i][j] = 1;
				}
			}
		}

		bfs();
		System.out.println(String.format("%d", count()));
	}
}
