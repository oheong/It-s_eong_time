import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

class VIRUS {
	int y;
	int x;
	int step;

	public VIRUS(int y, int x, int step) {
		this.y = y;
		this.x = x;
		this.step = step;
	}
}

public class b17142 {
	static int N, M, min;
	static int[][] map, copyMap, visited;
	static int[] virus_visited;
	static List<VIRUS> virus;
	static int[] by = { 0, 0, 1, -1 }, bx = { 1, -1, 0, 0 };
	static Queue<VIRUS> q;

	static int counting() {
		int count = 0;
		int flag = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] != 1 && visited[i][j] == 0) {
					count = 2123456789;
					flag = 1;
				}
				if (count < visited[i][j] && flag == 0)
					count = visited[i][j];
				visited[i][j] = 0;
			}
		}
		return count;
	}

	static void bfs() {
		while (!q.isEmpty()) {
			int ty = q.peek().y;
			int tx = q.peek().x;
			int step = q.peek().step;
			q.remove();
			for (int i = 0; i < 4; i++) {
				int ny = ty + by[i];
				int nx = tx + bx[i];
				if (0 <= ny && ny < N && 0 <= nx && nx < N && visited[ny][nx] == 0 && map[ny][nx] != 1) {
					if (map[ny][nx] == 2) {
						visited[ny][nx] = -1;
					} else {
						visited[ny][nx] = step + 1;

					}
					q.add(new VIRUS(ny, nx, step + 1));
				}
			}
		}
	}

	static void copy() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				copyMap[i][j] = map[i][j];
			}
		}
	}

	static void dfs(int d, int n) {
		if (d == M) {
			copy();
			for (int i = 0; i < virus.size(); i++) {
				if (virus_visited[i] == 1) {
					q.add(new VIRUS(virus.get(i).y, virus.get(i).x, 0));
					visited[virus.get(i).y][virus.get(i).x] = -1;
				} else {
					copyMap[virus.get(i).y][virus.get(i).x] = 0;
				}
			}
			bfs();
			int cnt = counting();
			if (cnt < min)
				min = cnt;
			return;
		}
		for (int i = n; i < virus.size(); i++) {
			if (virus_visited[i] == 0) {
				virus_visited[i] = 1;
				dfs(d + 1, i);
				virus_visited[i] = 0;
			}
		}
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		N = scanner.nextInt();
		M = scanner.nextInt();
		map = new int[N][N];
		copyMap = new int[N][N];
		visited = new int[N][N];
		min = 2123456789;
		virus = new ArrayList<VIRUS>();
		q = new LinkedList<VIRUS>();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] = scanner.nextInt();
				if (map[i][j] == 2) {
					virus.add(new VIRUS(i, j, 0));
				}
			}
		}
		virus_visited = new int[virus.size()];
		dfs(0, 0);
		if (min == 2123456789)
			System.out.println(-1);
		else
			System.out.println(min);
	}
}
