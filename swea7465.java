import java.util.Scanner;

public class swea7465 {
	static int N, M;
	static int[] map;

	static void setting() {
		for (int i = 0; i <= N; i++) {
			map[i] = i;
		}
	}

	static int findSet(int x) {
		if (x == map[x])
			return x;
		else
			return map[x] = findSet(map[x]);
	}

	static void union(int y, int x) {
		x = findSet(x); // 앞으로 x 쓸 일 없으니까 재활용 할 수 있음
		y = findSet(y);
		if (x == y)
			return;
		map[y] = x;
	}

	static int counting(int[] temp) {
		int count = 0;
		for (int i = 1; i <= N; i++) {
			if (temp[i] != 0)
				count++;
		}
		return count;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int test = 0; test < T; test++) {
			N = sc.nextInt();
			M = sc.nextInt();
			map = new int[N + 1];
			setting();
			for (int i = 0; i < M; i++) {
				int a = sc.nextInt();
				int b = sc.nextInt();
				union(a, b);
				//앞에꺼가 포함된것을 뒤에꺼에 포함시킨다
			}

			int[] temp = new int[N + 1];
			for (int i = 1; i <= N; i++) {
				temp[findSet(map[i])]++;
			}
			System.out.println(String.format("#%d %d", test + 1, counting(temp)));
		}
	}
}
