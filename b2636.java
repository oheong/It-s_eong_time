import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class b2636 {
	static class Point {
		int y;
		int x;

		public Point(int y, int x) {
			this.y = y;
			this.x = x;
		}
	}

	static int N, M, cheese;
	static Queue<Point> queue;
	static int[][] map, visited;
	static int[] by = { 0, 0, 1, -1 }, bx = { 1, -1, 0, 0 };

	static int bfs(int y, int x) {
		int cnt = 1;
		queue.add(new Point(y, x));
		visited[y][x] = 1;
		while (!queue.isEmpty()) {
			int ty = queue.peek().y;
			int tx = queue.peek().x;
			queue.remove();
			for (int i = 0; i < 4; i++) {
				int ny = ty + by[i];
				int nx = tx + bx[i];
				if (0 <= ny && ny < N && 0 <= nx && nx < M && visited[ny][nx] == 0) {
					if (map[ny][nx] == 0) {
						queue.add(new Point(ny, nx));
						visited[ny][nx] = 1;
						cnt++;
					} else {
						visited[ny][nx] = 9;
					}
				}
			}
		}
		return cnt;
	}

	static int init() {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (visited[i][j] == 9) {
					cnt++;
					map[i][j] = 0;
				}
				visited[i][j] = 0;
			}
		}
		return cnt;
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		N = scanner.nextInt();
		M = scanner.nextInt();
		map = new int[N][M];
		visited = new int[N][M];
		queue = new LinkedList<Point>();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				map[i][j] = scanner.nextInt();
			}
		}
		int time = 0;
		while (true) {
			if (bfs(0, 0) == N * M)
				break;
			cheese = init();
			time++;
		}
		System.out.printf("%d\n%d\n", time, cheese);
	}
}
