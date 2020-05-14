import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class swea5643 {
	static int N, M;
	static ArrayList<Integer>[] upList, downList;
	static int[] visited;
	static Queue<Integer> queue;

	static int upBFS(int start) {
		queue.add(start);
		int step = 0;
		while (!queue.isEmpty()) {
			int t = queue.peek();
			queue.remove();
			for (int i = 0; i < upList[t].size(); i++) {
				int n = (int) upList[t].get(i);
				if (visited[n] == 0) {
					step++;
					queue.add(n);
					visited[n] = 1;
				}
			}
		}
		return step;
	}

	static int downBFS(int start) {
		queue.add(start);
		int step = 0;
		while (!queue.isEmpty()) {
			int t = queue.peek();
			queue.remove();
			for (int i = 0; i < downList[t].size(); i++) {
				int n = (int) downList[t].get(i);
				if (visited[n] == 0) {
					step++;
					queue.add(n);
					visited[n] = 1;
				}
			}
		}
		return step;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int test = 0; test < T; test++) {
			N = sc.nextInt();
			M = sc.nextInt();
			upList = new ArrayList[N + 1];
			downList = new ArrayList[N + 1];
			visited = new int[N + 1];
			for (int i = 1; i <= N; i++) {
				upList[i] = new ArrayList<>();
				downList[i] = new ArrayList<>();
			}
			queue = new LinkedList<>();
			for (int i = 0; i < M; i++) {
				int small = sc.nextInt();
				int big = sc.nextInt();
				downList[small].add(big);
				upList[big].add(small);
			}
			int ans = 0;
			for (int i = 1; i <= N; i++) {
				// bfs 돌면서 up과 down 골라내기
				Arrays.fill(visited, 0);
				if (upBFS(i) + downBFS(i) == N - 1)
					ans++;
			}
			System.out.printf("#%d %d\n", test + 1, ans);
		}
	}
}
