import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class b13549 {
	static int K, N;
	static int SIZE = 100;// 001;
	static int[] bx = { -1, 1 };

	static int bfs() {
		int[] visited = new int[SIZE];
		Queue<Integer> q = new LinkedList<Integer>();
		Arrays.fill(visited, -1);
		q.add(N);
		visited[N] = 0;
		while (!q.isEmpty()) {
			int tx = q.peek();
			q.remove();

			if (tx == K)
				return visited[K];
			int temp = tx * 2;
			while (temp < SIZE&&visited[temp] == -1) {
				visited[temp] = visited[tx];
				q.add(temp);
				temp *= 2;
			}

			for (int i = 0; i < 2; i++) {
				int nx = tx + bx[i];
				if (0 <= nx && nx < SIZE && visited[nx] == -1) {
					q.add(nx);
					visited[nx] = visited[tx] + 1;
				}
			}
		}
		return 0;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		K = sc.nextInt();
		if (K <= N)
			System.out.println(N - K);
		else {
			System.out.println(bfs());
//			for (int i = 0; i < SIZE; i++)
//				System.out.println(i+" "+visited[i]);
		}
	}
}
