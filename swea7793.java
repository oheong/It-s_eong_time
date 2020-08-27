import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

public class swea7793 {
	static int T, N, M, ans;
	static char map[][];
	static int visited[][];
	static Queue<point> q;
	static int by[] = { 0, 0, 1, -1 }, bx[] = { 1, -1, 0, 0 };

	public static void bfs() {
		while (!q.isEmpty()) {
			int ty = q.peek().y;
			int tx = q.peek().x;
			char tc = q.peek().c;
			int tstep = q.peek().step;
			q.remove();
			if (map[ty][tx] == 'D' && tc == 'S') {
				ans = tstep;
				return;
			}
			for (int i = 0; i < 4; i++) {
				int ny = ty + by[i];
				int nx = tx + bx[i];
				if (0 <= ny && ny < N && 0 <= nx && nx < M && visited[ny][nx] != 2 && map[ny][nx] != 'X') {
					if (tc == 'S') {
						if (visited[ty][tx] == 2)
							continue;
						if (visited[ny][nx] == 0) {
							q.add(new point(ny, nx, 'S', tstep + 1));
							visited[ny][nx] = 1;
						}
					} else if (tc == '*') {
						if (map[ny][nx] == 'D')
							continue;
						q.add(new point(ny, nx, '*', 0));
						visited[ny][nx] = 2;
					}
				}
			}
		}
	}

	static class point {
		int y, x, step;
		char c;

		public point(int y, int x, char c, int step) {
			this.y = y;
			this.x = x;
			this.step = step;
			this.c = c;
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		T = sc.nextInt();
		for (int test = 0; test < T; test++) {
			N = sc.nextInt();
			M = sc.nextInt();
			map = new char[N][M];
			visited = new int[N][M];
			q = new LinkedList<point>();
			ArrayList<point> t = new ArrayList<point>();
			ans = -1;
			for (int i = 0; i < N; i++) {
				String temp = sc.next();
				for (int j = 0; j < M; j++) {
					map[i][j] = temp.charAt(j);
					if (map[i][j] == 'S') {
						q.add(new point(i, j, 'S', 0));
						visited[i][j] = 1;
					} else if (map[i][j] == '*') {
						t.add(new point(i, j, '*', 0));
						visited[i][j] = 2;
					}
				}
			}
			for (int i = 0; i < t.size(); i++) {
				q.add(new point(t.get(i).y, t.get(i).x, t.get(i).c, t.get(i).step));
			}
			bfs();
			if (ans == -1)
				System.out.printf("#%d GAME OVER\n", test + 1);
			else
				System.out.printf("#%d %d\n", test + 1, ans);
		}
	}

}
