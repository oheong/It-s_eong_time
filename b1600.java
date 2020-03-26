import java.util.Scanner;

class Queue {
	int y;
	int x;
	int step;
	int k;

	Queue(int y, int x, int step, int k) {
		this.y = y;
		this.x = x;
		this.step = step;
		this.k = k;
	}
}

public class b1600 {
	static int K, W, H, f, r, min;
	static int[][] map;
	static int[][][] visited;
	static int[] by = { 0, 0, 1, -1 }, bx = { 1, -1, 0, 0 };
	static int[] mal_by = { -2, -2, -1, 1, 2, 2, 1, -1 }, mal_bx = { -1, 1, 2, 2, 1, -1, -2, -2 };
	static Queue[] q;

	static void enQ(Queue qu) {
		r++;
		q[r] = qu;
	}

	static void deQ() {
		f++;
	}

	static int empty() {
		if (f == r) return 1;
		else return 0;
	}

	static Queue peek() {
		return q[f + 1];
	}

	static void bfs(int y, int x) {
		enQ(new Queue(y, x, 0, 0));
		visited[y][x][0] = 1;
		while (empty() == 0) {
			int ty = peek().y;
			int tx = peek().x;
			int tstep = peek().step;
			int tk = peek().k;
			deQ();
			for (int i = 0; i < 4; i++) {
				int ny = ty + by[i];
				int nx = tx + bx[i];
				if (0 <= ny && ny < H && 0 <= nx && nx < W && map[ny][nx] == 0 && visited[ny][nx][tk] == 0) {
					visited[ny][nx][tk] = tstep + 1;
					enQ(new Queue(ny, nx, tstep + 1, tk));
				}
			}
			if (tk + 1 < K) {
				for (int j = 0; j < 8; j++) {
					int ny = ty + mal_by[j];
					int nx = tx + mal_bx[j];
					if (0 <= ny && ny < H && 0 <= nx && nx < W && map[ny][nx] == 0 && visited[ny][nx][tk + 1] == 0) {
						enQ(new Queue(ny, nx, tstep + 1, tk + 1));
						visited[ny][nx][tk + 1] = tstep + 1;
					}
				}
			}
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		K = sc.nextInt();
		W = sc.nextInt();
		H = sc.nextInt();
		map = new int[H][W];
		K++;
		visited = new int[H][W][K];
		q = new Queue[W * H * K * 8];
		min = 2123456789;
		f = r = -1;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				map[i][j] = sc.nextInt();
			}
		}
		bfs(0, 0);
		for (int i = 0; i < K; i++) {
			int temp = visited[H - 1][W - 1][i];
			if (temp == 0) continue;
			if (temp < min)
				min = temp;
		}
		if (min == 2123456789) min = -1;
		System.out.println(min);
	}
}
// 100%인데 틀렸다고?? 얼탱,,
