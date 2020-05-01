import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class b15686 {
	static class HOUSE {
		int y;
		int x;
	}

	static int N, M, ans = 2123456789;
	static int[][] map;
	static List<HOUSE> house, chicken;
	static int[] ho, ci;

	static int abs(int a) {
		if (a < 0)
			return -1 * a;
		else
			return a;
	}

	static int sum() {
		int s = 0;
		for (int i = 0; i < ho.length; i++) {
			if (ho[i] == 2123456789)
				continue;
			s += ho[i];
		}
		return s;
	}

	static void dfs(int d, int n) {
		if (d == M) {
			Arrays.fill(ho, 2123456789);
			for (int j = 0; j < house.size(); j++) {
				int min = 2123456789;
				for (int i = 0; i < chicken.size(); i++) {
					if (ci[i] == 1) {
						int cy = chicken.get(i).y;
						int cx = chicken.get(i).x;
						int hy = house.get(j).y;
						int hx = house.get(j).x;
						int temp = abs(cy - hy) + abs(cx - hx);
						if (temp < min)
							min = temp;
					}
				}
				if (min < ho[j])
					ho[j] = min;
			}

			int t = sum();
			if (t < ans)
				ans = t;
			return;
		}
		for (int i = n; i < chicken.size(); i++) {
			if (ci[i] == 0) {
				ci[i] = 1;
				dfs(d + 1, i);
				ci[i] = 0;
			}
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		map = new int[N][N];
		house = new ArrayList<HOUSE>();
		chicken = new ArrayList<HOUSE>();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] = sc.nextInt();
				if (map[i][j] == 1) {
					// 집
					HOUSE h = new HOUSE();
					h.y = i;
					h.x = j;
					house.add(h);
				}

				else if (map[i][j] == 2) {
					// 치킨집
					HOUSE h = new HOUSE();
					h.y = i;
					h.x = j;
					chicken.add(h);
				}
			}
		}
		ho = new int[house.size()];
		ci = new int[chicken.size()];
		dfs(0, 0);
		System.out.println(ans);
	}
}
