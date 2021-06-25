package algorithm;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class b1339 {
	static int N, D, max;
	static int[] alph = new int[27];
	static List<Character> list = new ArrayList<Character>();
	static int[] visited = new int[27];
	static int[] num, ans;
	static String[] str;

	static void dfs(int d) {
		if (d == D) {
			// 여기서 계산하기
			for (int i = 0; i < N; i++) {
				ans[i] = 0;
				for (int j = 0; j < str[i].length(); j++) {
					char c = str[i].charAt(j);
					int temp = num[list.indexOf(c)];
					ans[i] += temp;
					if (j != str[i].length() - 1)
						ans[i] *= 10;
				}
			}

			int sum = 0;
			for (int i = 0; i < N; i++) {
				sum += ans[i];
			}
			if (max < sum)
				max = sum;
			return;
		}
		for (int i = 0; i < 10; i++) {
			if (visited[i] == 0) {
				visited[i] = 1;
				num[d] = i;
				dfs(d + 1);
				visited[i] = 0;
			}
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		N = sc.nextInt();
		ans = new int[N];
		str = new String[N];
		for (int i = 0; i < N; i++) {
			str[i] = sc.next();
			for (int j = 0; j < str[i].length(); j++) {
				char c = str[i].charAt(j);
				if (alph[c - 65] == 0) {
					list.add(c);
					D++;
				}
				alph[c - 65]++;
			}
		}
		num = new int[D];
		list.sort(null);
		dfs(0);
		System.out.println(max);
	}
}
