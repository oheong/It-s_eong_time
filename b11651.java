import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

// priority Queue 연습문제

public class b11651 {
	static class Point implements Comparable<Point> {
		int y;
		int x;

		@Override
		public int compareTo(Point o) {
			if (this.x == o.x) {
				return this.y < o.y ? -1 : 1;
			} else {
				return this.x < o.x ? -1 : 1;
			}
		}

	}

	public static void main(String[] args) {
		int N;
		Scanner scanner = new Scanner(System.in);
		N = scanner.nextInt();
		PriorityQueue<Point> pq = new PriorityQueue<Point>();
		for (int i = 0; i < N; i++) {
			Point point = new Point();
			point.y = scanner.nextInt();
			point.x = scanner.nextInt();
			pq.add(point);
		}

		for (int i = 0; i < N; i++) {
			System.out.println(pq.peek().y + " " + pq.peek().x);
			pq.remove();
		}
	}
}
