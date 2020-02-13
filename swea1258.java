import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class swea1258 {
	static int N, T;
	static int[][] map, visited;

	static class JP {
		int y;
		int x;
	}

	static void getJP(int realY, int realX, int y, int x) {
		for (int i = 0; i < y; i++) {
			for (int j = 0; j < x; j++) {
				visited[realY + i][realX + j] = 1;
			}
		}
	}

	static void sort(JP[] jp, int num) {
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num - 1 - i; j++) {
				if (jp[j].y * jp[j].x > jp[j + 1].y * jp[j + 1].x) {
					JP temp1 = new JP();
					JP temp2 = new JP();
					temp1.y = jp[j].y;
					temp1.x = jp[j].x;
					temp2.y = jp[j + 1].y;
					temp2.x = jp[j + 1].x;

					jp[j] = temp2;
					jp[j + 1] = temp1;
				} else if (jp[j].y * jp[j].x == jp[j + 1].y * jp[j + 1].x) {
					if (jp[j].y > jp[j + 1].y) {
						JP temp1 = new JP();
						JP temp2 = new JP();
						temp1.y = jp[j].y;
						temp1.x = jp[j].x;
						temp2.y = jp[j + 1].y;
						temp2.x = jp[j + 1].x;

						jp[j] = temp2;
						jp[j + 1] = temp1;
					}
				}
			}
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		T = sc.nextInt();
		for (int test = 0; test < T; test++) {
			N = sc.nextInt();
			map = new int[N][N];
			visited = new int[N][N];
			JP[] jp = new JP[25];
			int jpCount = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					map[i][j] = sc.nextInt();
				}
			}

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (map[i][j] != 0 && visited[i][j] == 0) {
						int y = 0;
						int x = 0;
						for (y = 0; y < N; y++) {
							if (y + i >= N || map[i + y][j] == 0)
								break;
						}

						for (x = 0; x < N; x++) {
							if (x + j >= N || map[i][x + j] == 0)
								break;
						}
						getJP(i, j, y, x);
						JP temp = new JP();
						temp.y = y;
						temp.x = x;
						jp[jpCount++] = temp;
					}
				}
			}
			System.out.print(String.format("#%d %d ", test + 1, jpCount));
			sort(jp, jpCount);

			for (int i = 0; i < jpCount; i++) {
				System.out.printf("%d %d ", jp[i].y, jp[i].x);
			}
			System.out.println();
		}
	}
}