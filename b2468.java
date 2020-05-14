import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Point {
	int y;
	int x;

	public Point(int y, int x) {
		this.y = y;
		this.x = x;
	}
}

public class b2468 {
	static int N, height, max;
	static int[][] map, visited;
	static Queue<Point> q;
	static int[] by = { 0, 0, 1, -1 }, bx = { 1, -1, 0, 0 };

	static void init() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visited[i][j] = 0;
			}
		}
	}

	static void bfs(int y, int x, int rain) {
		q.add(new Point(y, x));
		visited[y][x] = 1;
		while (!q.isEmpty()) {
			int ty = q.peek().y;
			int tx = q.peek().x;
			q.remove();
			for (int i = 0; i < 4; i++) {
				int ny = ty + by[i];
				int nx = tx + bx[i];
				if (0 <= ny && ny < N && 0 <= nx && nx < N && rain < map[ny][nx] && visited[ny][nx] == 0) {
					q.add(new Point(ny, nx));
					visited[ny][nx] = 1;
				}
			}
		}
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		N = scanner.nextInt();
		map = new int[N][N];
		visited = new int[N][N];
		q = new LinkedList<Point>();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] = scanner.nextInt();
				if (map[i][j] > height)
					height = map[i][j];
			}
		}
		for (int rain = 0; rain <= height; rain++) {
			int count = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (map[i][j] > rain && visited[i][j] == 0) {
						bfs(i, j, rain);
						count++;
					}
				}
			}
			if (max < count)
				max = count;
			init();
		}
		System.out.println(max);
	}
}
