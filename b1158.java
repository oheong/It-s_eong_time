import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

public class b1158 {
	static int N, K;
	static Queue<Integer> q;
	static List<Integer> list;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		K = sc.nextInt();
		q = new LinkedList<Integer>();
		list = new ArrayList<Integer>();
		for (int i = 0; i < N; i++) {
			q.add(i + 1);
		}
		int cnt = 0;
		while (!q.isEmpty()) {
			int temp = q.remove();
			cnt++;
			if (cnt % K == 0) {
				list.add(temp);
			} else {
				q.add(temp);
			}
		}
		System.out.printf("<");
		for (int i = 0; i < list.size(); i++) {
			System.out.printf("%d", list.get(i));
			if (i != list.size() - 1)
				System.out.printf(", ");
		}
		System.out.printf(">");
		System.out.println();
	}
}