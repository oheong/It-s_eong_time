import java.util.*;

class Solution {
	static int[] visited;
	static List<String> list;

	static void dfs(int d, int n, String str, String[][] tickets) {
		if (d == n) {
			list.add(str);

			return;
		}
		for (int i = 0; i < n; i++) {
			String tempStr = str.substring(str.length() - 3, str.length());
			if (visited[i] == 0 && tempStr.equals(tickets[i][0])) {
				visited[i] = 1;
				dfs(d + 1, n, str + tickets[i][1], tickets);
				visited[i] = 0;
			}
		}
	}

	public String[] solution(String[][] tickets) {

		visited = new int[tickets.length];
		list = new ArrayList<String>();

		dfs(0, tickets.length, "ICN", tickets);

		Collections.sort(list, new Comparator<String>() {
			public int compare(String s1, String s2) {
				return s1.compareTo(s2);
			}
		});

		String str = list.get(0);

		String[] answer = new String[str.length() / 3];

		for (int i = 0; i < answer.length; i++) {
			answer[i] = str.substring(i * 3, (i + 1) * 3);
		}

		return answer;
	}
}
