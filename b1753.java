import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;

class Map implements Comparable<Map> {
	int v;
	int w;

	public Map(int v, int w) {
		this.v = v;
		this.w = w;
	}

	@Override
	public int compareTo(Map o) {
		return Integer.compare(this.w, o.w);
	}
}

public class b1753 {
	static int V, E, K;
	static int[] D, visited;
	static List<Map>[] map;

	static void Dijkstra(int start) {
		PriorityQueue<Map> q = new PriorityQueue<Map>();
		q.add(new Map(start, 0));
		D[start] = 0;

		while (!q.isEmpty()) {
			Map curMap = q.poll();

			int now = curMap.v;
			if (visited[now] == 1)
				continue;
			visited[now] = 1;
			for (Map m : map[now]) {
				if (D[m.v] > D[now] + m.w) {
					D[m.v] = D[now] + m.w;
					q.add(new Map(m.v, D[m.v]));
				}
			}
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		V = sc.nextInt();
		E = sc.nextInt();
		K = sc.nextInt();
		map = new ArrayList[V + 1];
		D = new int[V + 1];
		visited = new int[V + 1];
		for (int i = 1; i <= V; i++)
			map[i] = new ArrayList<>();
		for (int i = 0; i < E; i++) {
			int start = sc.nextInt();
			int end = sc.nextInt();
			int value = sc.nextInt();
			map[start].add(new Map(end, value));
		}
		Arrays.fill(D, 2123456789);
		Dijkstra(K);
		for (int i = 1; i <= V; i++)
			System.out.println(D[i] == 2123456789 ? "INF" : D[i]);
	}
}

// 4%에서 메모리 초과
