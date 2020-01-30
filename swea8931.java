import java.util.Scanner;
import java.util.Stack;

public class swea8931 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int test = 0; test < T; test++) {
			int K = sc.nextInt();
			int num;
			Stack<Integer> st = new Stack<Integer>();
			for (int i = 0; i < K; i++) {
				num = sc.nextInt();
				if (num == 0)
					st.pop();
				else
					st.push(num);
			}
			int ans = 0;
			while (!st.isEmpty()) {
				ans += st.peek();
				st.pop();
			}
			System.out.println(String.format("#%d %d", test + 1, ans));
		}
	}
}
