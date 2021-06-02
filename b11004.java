import java.util.Scanner;

public class b11004 {
	static int[] list;
	static int N, K;

	static void swap(int a, int b) {
		int temp = list[a];
		list[a] = list[b];
		list[b] = temp;
	}

	static void qsort(int l, int r) {
		if (l < r) {
			int p = partition(l, r, (l + r) / 2);
			qsort(l, p);
			qsort(p + 1, r);
		}
	}

	static int partition(int l, int r, int p) {
		int left = l;
		int right = r;
		int pivot = list[p];
		while (left < right) {
			while (list[left] < pivot)
				left++;
			while (pivot < list[right])
				right--;
			swap(left, right);
		}
		return right;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		K = sc.nextInt();
		list = new int[N];
		for (int i = 0; i < N; i++) {
			list[i] = sc.nextInt();
		}
		qsort(0, list.length - 1);
		System.out.println(list[K - 1]);
	}
}
