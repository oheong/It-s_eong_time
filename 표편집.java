import java.util.Stack;

public class 표편집 {

	static Stack<Integer> del_index;

	static public String solution(int n, int k, String[] cmd) {
		int table = n;
		del_index = new Stack<Integer>(); // 삭제된 행 스택

		for (int i = 0; i < cmd.length; i++) {
			if (cmd[i].charAt(0) == 'U')
				k -= Integer.parseInt(cmd[i].split(" ")[1]);

			else if (cmd[i].charAt(0) == 'D')
				k += Integer.parseInt(cmd[i].split(" ")[1]);

			else if (cmd[i].charAt(0) == 'C') {
				del_index.push(k); // 인덱스
				table--;
				if (k == table)
					k--;
			}

			else if (cmd[i].charAt(0) == 'Z') {
				if (del_index.peek() <= k)
					k++;
				del_index.pop();
				table++;
			}
		}

		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < table; i++)
			sb.append("O");
		while (!del_index.isEmpty())
			sb.insert(del_index.pop(), "X");
		return sb.toString();

	}

	public static void main(String[] args) {
		String[] cmd = { "D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z" };
//		String[] cmd = { "D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z", "U 1", "C" };
		System.out.println(solution(8, 2, cmd));
	}
}
