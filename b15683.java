import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class CCTV {
	int y;
	int x;
	int num;

	public CCTV(int y, int x, int num) {
		this.y = y;
		this.x = x;
		this.num = num;
	}
}

public class b15683 {
	static int N, M, min = 2123456789;
	static int[] by = { -1, 0, 1, 0 }, bx = { 1, 0, -1, 0 };
	static int[][] map, copy_map;
	static int[] visited;
	static List<CCTV> list, list5;

	static void copy() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				copy_map[i][j] = map[i][j];
			}
		}
	}

	static int counting() {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (copy_map[i][j] == 0)
					cnt++;
			}
		}
		return cnt;
	}

	static void coloring5(int y, int x) {
		for (int i = y - 1; 0 <= i; i--) {
			if (map[i][x] == 6)
				break;
			else if (1 <= map[i][x] && map[i][x] <= 4 || map[i][x] == 9)
				continue;
			map[i][x] = 9;
		}

		for (int j = x + 1; j < M; j++) {
			if (map[y][j] == 6)
				break;
			else if (1 <= map[y][j] && map[y][j] <= 4 || map[y][j] == 9)
				continue;
			map[y][j] = 9;
		}

		for (int i = y + 1; i < N; i++) {
			if (map[i][x] == 6)
				break;
			else if (1 <= map[i][x] && map[i][x] <= 4 || map[i][x] == 9)
				continue;
			map[i][x] = 9;
		}

		for (int j = x - 1; 0 <= j; j--) {
			if (map[y][j] == 6)
				break;
			else if (1 <= map[y][j] && map[y][j] <= 4 || map[y][j] == 9)
				continue;
			map[y][j] = 9;
		}
	}

	static void coloring(int y, int x, int dir) {
		if (dir == 0) {
			for (int i = y - 1; 0 <= i; i--) {
				if (copy_map[i][x] == 6)
					break;
				else if (1 <= copy_map[i][x] && copy_map[i][x] <= 4 || copy_map[i][x] == 9)
					continue;
				copy_map[i][x] = 9;
			}
		} else if (dir == 1) {
			for (int j = x + 1; j < M; j++) {
				if (copy_map[y][j] == 6)
					break;
				else if (1 <= copy_map[y][j] && copy_map[y][j] <= 4 || copy_map[y][j] == 9)
					continue;
				copy_map[y][j] = 9;
			}
		} else if (dir == 2) {
			for (int i = y + 1; i < N; i++) {
				if (copy_map[i][x] == 6)
					break;
				else if (1 <= copy_map[i][x] && copy_map[i][x] <= 4 || copy_map[i][x] == 9)
					continue;
				copy_map[i][x] = 9;
			}
		} else if (dir == 3) {
			for (int j = x - 1; 0 <= j; j--) {
				if (copy_map[y][j] == 6)
					break;
				else if (1 <= copy_map[y][j] && copy_map[y][j] <= 4 || copy_map[y][j] == 9)
					continue;
				copy_map[y][j] = 9;
			}
		}
	}

	static void dfs(int d) {
		if (d == list.size()) {
			copy();
			for (int i = 0; i < d; i++) {
				int y = list.get(i).y;
				int x = list.get(i).x;
				int num = list.get(i).num; // cctv 종류
				if (num == 1) {
					coloring(y, x, visited[i]);
				} else if (num == 2) {
					if (visited[i] % 2 == 0) {
						coloring(y, x, 1);
						coloring(y, x, 3);
					} else {
						coloring(y, x, 0);
						coloring(y, x, 2);
					}
				} else if (num == 3) {
					coloring(y, x, visited[i]);
					coloring(y, x, (visited[i] + 1) % 4);
				} else if (num == 4) {
					coloring(y, x, visited[i]);
					coloring(y, x, (visited[i] + 1) % 4);
					coloring(y, x, (visited[i] + 2) % 4);					
				}
			}
			int temp = counting();
			if (temp < min)
				min = temp;
			return;
		}

		for (int i = 0; i < 4; i++) {
			visited[d] = i;
			dfs(d + 1);
		}
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		N = scanner.nextInt();
		M = scanner.nextInt();
		map = new int[N][M];
		copy_map = new int[N][M];
		list = new ArrayList<CCTV>();
		list5 = new ArrayList<CCTV>();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				map[i][j] = scanner.nextInt();
				if (1 <= map[i][j] && map[i][j] <= 4) {
					list.add(new CCTV(i, j, map[i][j]));
				} else if (map[i][j] == 5) {
					list5.add(new CCTV(i, j, map[i][j]));
				}
			}
		}
		for (int i = 0; i < list5.size(); i++) {
			coloring5(list5.get(i).y, list5.get(i).x);
		}
		visited = new int[list.size()];
		dfs(0);
		System.out.println(min);
	}
}
