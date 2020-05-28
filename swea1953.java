import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class swea1953 {
	static int N, M, R, C, L;
	static int[][] map, visited;
	static Queue<point> q;
	static int[] by = { -1, 0, 1, 0 }, bx = { 0, 1, 0, -1 };

	static class point {
		int y;
		int x;
		int time;

		public point(int y, int x, int time) {
			super();
			this.y = y;
			this.x = x;
			this.time = time;
		}
	}

	static int bfs(int y, int x) {
		int count = 1;
		q.add(new point(y, x, 1));
		visited[y][x] = 1;
		while (!q.isEmpty()) {
			int ty = q.peek().y;
			int tx = q.peek().x;
			int ttime = q.peek().time;
			q.remove();
			if (ttime == L) {
				return count;
			}
			for (int i = 0; i < 4; i++) {
				int ny = ty + by[i];
				int nx = tx + bx[i];
				if (0 <= ny && ny < N && 0 <= nx && nx < M && map[ny][nx] != 0 && visited[ny][nx] == 0) {
					if (map[ty][tx] == 1) {
						if (i == 0) {
							if (map[ny][nx] == 3 || map[ny][nx] == 4 || map[ny][nx] == 7)
								continue;
						} else if (i == 1) {
							if (map[ny][nx] == 2 || map[ny][nx] == 4 || map[ny][nx] == 5)
								continue;
						} else if (i == 2) {
							if (map[ny][nx] == 3 || map[ny][nx] == 5 || map[ny][nx] == 6)
								continue;
						} else if (i == 3) {
							if (map[ny][nx] == 2 || map[ny][nx] == 6 || map[ny][nx] == 7)
								continue;
						}
					}

					else if (map[ty][tx] == 2) {
						if (i % 2 == 1)
							continue;
						if (i == 0) {
							if (map[ny][nx] == 3 || map[ny][nx] == 4 || map[ny][nx] == 7)
								continue;
						} else if (i == 2) {
							if (map[ny][nx] == 3 || map[ny][nx] == 5 || map[ny][nx] == 6)
								continue;
						}
					}

					else if (map[ty][tx] == 3) {
						if (i % 2 == 0)
							continue;
						if (i == 1) {
							if (map[ny][nx] == 2 || map[ny][nx] == 4 || map[ny][nx] == 5)
								continue;
						} else if (i == 3) {
							if (map[ny][nx] == 2 || map[ny][nx] == 6 || map[ny][nx] == 7)
								continue;
						}
					}

					else if (map[ty][tx] == 4) {
						if (i == 2 || i == 3)
							continue;
						if (i == 0) {
							if (map[ny][nx] == 3 || map[ny][nx] == 4 || map[ny][nx] == 7)
								continue;
						} else if (i == 1) {
							if (map[ny][nx] == 2 || map[ny][nx] == 4 || map[ny][nx] == 5)
								continue;
						}
					}

					else if (map[ty][tx] == 5) {
						if (i == 0 || i == 3)
							continue;
						if (i == 1) {
							if (map[ny][nx] == 2 || map[ny][nx] == 4 || map[ny][nx] == 5)
								continue;
						} else if (i == 2) {
							if (map[ny][nx] == 3 || map[ny][nx] == 5 || map[ny][nx] == 6)
								continue;
						}
					}

					else if (map[ty][tx] == 6) {
						if (i == 0 || i == 1)
							continue;
						if (i == 2) {
							if (map[ny][nx] == 3 || map[ny][nx] == 5 || map[ny][nx] == 6)
								continue;
						} else if (i == 3) {
							if (map[ny][nx] == 2 || map[ny][nx] == 6 || map[ny][nx] == 7)
								continue;
						}
					}

					else if (map[ty][tx] == 7) {
						if (i == 1 || i == 2)
							continue;
						if (i == 0) {
							if (map[ny][nx] == 3 || map[ny][nx] == 4 || map[ny][nx] == 7)
								continue;
						} else if (i == 3) {
							if (map[ny][nx] == 2 || map[ny][nx] == 6 || map[ny][nx] == 7)
								continue;
						}
					}
					count++;
					q.add(new point(ny, nx, ttime + 1));
					visited[ny][nx] = ttime + 1;
				}
			}
		}
		return count;
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int T = scanner.nextInt();
		for (int test = 0; test < T; test++) {
			N = scanner.nextInt();
			M = scanner.nextInt();
			R = scanner.nextInt();
			C = scanner.nextInt();
			L = scanner.nextInt();
			map = new int[N][M];
			visited = new int[N][M];
			q = new LinkedList<point>();
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					map[i][j] = scanner.nextInt();
				}
			}
			System.out.printf("#%d %d\n", test + 1, bfs(R, C));
		}
	}
}
