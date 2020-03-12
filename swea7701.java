import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;
import java.util.Set;

public class swea7701 {
	static int N;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int test = 0; test < T; test++) {
			N = sc.nextInt();
			// 이름의 길이가 짧을수록 앞으로
			// 같은 길이면 사전 순으로
			ArrayList<String> list[] = new ArrayList[51];
			Set<String> set = new HashSet<String>();
			for (int i = 1; i < 51; i++)
				list[i] = new ArrayList<String>();

			// 중복제거 삽입
			for (int i = 0; i < N; i++) {
				String str = sc.next();
				set.add(str);
			}

			// 값 list에 복사
			Iterator<String> it = set.iterator();
			while (it.hasNext()) {
				String str = it.next();
				list[str.length()].add(str);
			}

			// 소팅
			StringBuffer sb = new StringBuffer();
			for (int i = 1; i < 51; i++) {
				int t = list[i].size();
				if (t == 0)
					continue;
				String[] tempStrings = new String[t];
				for (int j = 0; j < t; j++)
					tempStrings[j] = list[i].get(j);
				Arrays.sort(tempStrings);
				for (int j = 0; j < t; j++)
					sb.append(tempStrings[j] + "\n");
			}
			System.out.printf("#%d\n", test + 1);
			System.out.printf(sb.toString());
		}
	}
}
