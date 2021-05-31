import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class b1316 {
	static int N, ans;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		for (int n = 0; n < N; n++) {
			String temp = sc.next();

			Queue<Character> q = new LinkedList<Character>();
			HashMap<Character, Integer> hash = new HashMap<Character, Integer>();
			for (int i = 0; i < temp.length(); i++)
				q.add(temp.charAt(i));

			boolean flag = false;

			char c = q.remove();
			hash.put(c, 1);

			while (!q.isEmpty()) {
				if (c == q.peek())
					q.remove();
				else {
					c = q.remove();
					if (hash.containsKey(c)) {
						flag = true;
						while (!q.isEmpty())
							q.remove();
					} else {
						hash.put(c, 1);
					}
				}
			}
			if (flag == false)
				ans++;
		}
		System.out.println(ans);
	}
}
