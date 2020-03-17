import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

public class swea1812 {
	static class Rectangle implements Comparable<Rectangle> {
		int max, min;

		public Rectangle(int width, int heignt) {
			if (width < heignt) {
				min = width;
				max = heignt;
			}

			else {
				min = heignt;
				max = width;
			}
		}

		@Override
		public int compareTo(Rectangle o) {
			// TODO Auto-generated method stub
			// return this.min - o.min; // 오름차순
			return o.min - this.min; // 내림차순
		}
	}

	static int N, M, cnt;
	static int[] size;
	static PriorityQueue<Rectangle> queue;

	private static void go(int size) {
		// queue에서 poll() : min값이 최대인 직사각형이 뽑혀짐
		// 직사각형의 최소변의 길이가 size보다 길거나 크면 : 원하는 크기의 정사각형을 만들 수 있음.
		Rectangle r = queue.poll();
		if (r.min >= size) {
			queue.offer(new Rectangle(r.min - size, size));
			queue.offer(new Rectangle(r.min, r.max - size));
		}
		// 아니면 : 원하는 크기의 정사각형을 만들 수 없음.
		else {
			queue.offer(r);
			queue.offer(new Rectangle(M - size, size));
			queue.offer(new Rectangle(M, M - size));
			cnt++;
		}
	}

	private static void cut() {
		// 가장 큰 크기의 정사각형부터 만들기
		Arrays.sort(size);
		queue = new PriorityQueue<Rectangle>();
		queue.offer(new Rectangle(M, M));
		cnt++;
		for (int i = N - 1; 0 <= i; i--) {
			go(1 << size[i]); // 2의 n승
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int test = 0; test < T; test++) {
			N = sc.nextInt();
			M = sc.nextInt();
			size = new int[N];

			for (int i = 0; i < N; i++) {
				size[i] = sc.nextInt();
			} // 만들고자 하는 정사각형 크기 2^k입력 (k)

			cut();

			System.out.printf("#%d %d\n", test + 1, cnt);
			cnt = 0;
		}
	}
}
