import java.util.Scanner;
import java.util.Stack;

public class swea1234 {
	static int N;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		for (int test = 0; test < 10; test++) {
			N = sc.nextInt();
			Stack<Character> st = new Stack<Character>();
			String s = sc.next();
			st.push(s.charAt(0));
			for (int i = 1; i < N; i++) {
				char num = s.charAt(i);
				if (st.empty()) {
					st.push(num);
					continue;
				}
				if (st.peek().equals(num)) st.pop();
				else st.push(num);
			}
			StringBuffer str = new StringBuffer();
			while (!st.empty()) str.insert(0, st.pop());

			System.out.println(String.format("#%d %s", test + 1, str));
		}
	}
}
