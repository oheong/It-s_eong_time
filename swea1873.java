import java.util.Scanner;

public class swea1873 {
	static int W, H;

	static int isOk(int y, int x) {
		if (0 <= y && y < H && 0 <= x && x < W)
			return 1;
		return 0;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int test = 0; test < T; test++) {
			H = sc.nextInt();
			W = sc.nextInt();

			char[][] map = new char[H][W];

			int y = 0, x = 0;
			int dir = 5;

			for (int i = 0; i < H; i++) {
				String str = sc.next();
				for (int j = 0; j < W; j++) {
					map[i][j] = str.charAt(j);
					if (map[i][j] == '<' || map[i][j] == '^' || map[i][j] == 'v' || map[i][j] == '>') {
						y = i;
						x = j;
						if (map[i][j] == '<')
							dir = 3;
						else if (map[i][j] == '^')
							dir = 0;
						else if (map[i][j] == 'v')
							dir = 2;
						else if (map[i][j] == '>')
							dir = 1;
					}
				}
			}
			int[] by = { -1, 0, 1, 0 }, bx = { 0, 1, 0, -1 };
			int commandLine = sc.nextInt();
			String temp = sc.next();
			for (int line = 0; line < commandLine; line++) {
				char choice = temp.charAt(line);

				if (choice == 'U') {
					map[y][x] = '^';
					dir = 0;
					if (isOk(y - 1, x) == 1 && map[y - 1][x] == '.') {
						map[y--][x] = '.';
						map[y][x] = '^';
					}
				}

				else if (choice == 'D') {
					map[y][x] = 'v';
					dir = 2;
					if (isOk(y + 1, x) == 1 && map[y + 1][x] == '.') {
						map[y++][x] = '.';
						map[y][x] = 'v';
					}
				}

				else if (choice == 'L') {
					map[y][x] = '<';
					dir = 3;
					if (isOk(y, x - 1) == 1 && map[y][x - 1] == '.') {
						map[y][x--] = '.';
						map[y][x] = '<';
					}
				}

				else if (choice == 'R') {
					map[y][x] = '>';
					dir = 1;
					if (isOk(y, x + 1) == 1 && map[y][x + 1] == '.') {
						map[y][x++] = '.';
						map[y][x] = '>';
					}
				}

				else if (choice == 'S') {
					int ny = y;
					int nx = x;
					while (true) {
						ny += by[dir];
						nx += bx[dir];
						if (isOk(ny, nx) == 0 || map[ny][nx] == '#')
							break;

						else if (map[ny][nx] == '*') {
							map[ny][nx] = '.';
							break;
						}
					}
				}
			}
			System.out.print(String.format("#%d ", test + 1));
			for (int i = 0; i < H; i++) {
				for (int j = 0; j < W; j++) {
					System.out.print(String.format("%c", map[i][j]));
				}
				System.out.println();
			}
		}
	}
}
