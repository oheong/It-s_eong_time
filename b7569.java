import java.util.Scanner;

public class b7569 {
	static int N, M, H;
	static int[][][] map, visited;
	static int[] bz = { 1, -1, 0, 0, 0, 0 }, by = { 0, 0, 0, 0, -1, 1 }, bx = { 0, 0, -1, 1, 0, 0 };

	static class Queue {
		int y;
		int x;
		int z;
	}

	static Queue[] q;
	static int f = -1, r = -1;

	static void enQ(int z, int y, int x) {
		Queue t = new Queue();
		r++;
		t.y = y;
		t.x = x;
		t.z = z;
		q[r] = t;
	}
	static void deQ() {f++;}
	static int empty() {
		if(r==f)return 1;
		else return 0;
	}
	static Queue peek() {
		return q[f+1];
	}
	static void bfs() {
		int count = 0;
		while (empty() == 0) {
			int ty = peek().y;
			int tx = peek().x;
			int tz = peek().z;
			deQ();
			for (int i = 0; i < 6; i++) {
				int ny = ty + by[i];
				int nx = tx + bx[i];
				int nz = tz + bz[i];
				if (0 <= ny && ny < N && 0 <= nx && nx < M && 0 <= nz && nz < H&&map[nz][ny][nx] == 0 && visited[nz][ny][nx] == 0) {
					enQ(nz, ny, nx);
					visited[nz][ny][nx] = visited[tz][ty][tx] + 1;
				}
			}
		}
	}
	static int count() {
		int max = 0;
		for (int z = 0; z < H; z++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (map[z][i][j] == 1)continue;
					if (visited[z][i][j] > max)max = visited[z][i][j];
					if (map[z][i][j] == 0 && visited[z][i][j] == 0) return -1;
				}
			}
		}
		if (max > 0) return max - 1;
		else return max;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		M = sc.nextInt();
		N = sc.nextInt();
		H = sc.nextInt();
		map = new int[H][N][M];
		visited = new int[H][N][M];
		q = new Queue[N * M * H];
		for (int z = 0; z < H; z++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					map[z][i][j] = sc.nextInt();
					if (map[z][i][j] == 1) {
						enQ(z, i, j);
						visited[z][i][j] = 1;
					}
				}
			}
		}
		bfs();
		System.out.println(String.format("%d", count()));
	}
}
