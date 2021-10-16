import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class 불량사용자 {

	static ArrayList<ArrayList<String>> list;
	static ArrayList<String> ansList;

	static int isContain(String str, String id) {
		String[] splitStr = str.split(",");
		for (int i = 0; i < splitStr.length; i++) {
			if (id.equals(splitStr[i]))
				return 0;
		}
		return 1;
	}

	static int isContainName(String str) {
		String[] splitStr = str.split(",");

		Arrays.sort(splitStr);

		for (int idx = 0; idx < ansList.size(); idx++) {
			String[] ansSplit = ansList.get(idx).split(",");
			Arrays.sort(ansSplit);

			int num = 0;
			for (int i = 0; i < ansSplit.length; i++) {
				if (ansSplit[i].equals(splitStr[i]))
					num++;
			}

			if (num == ansSplit.length)
				return 0;
		}

		return 1;
	}

	static void dfs(int d, int n, String str) {
		if (d == n) {

			boolean flag = false;
			for (int i = 0; i < ansList.size(); i++) {
				if (isContainName(str) == 0) {
					flag = true;
					break;
				}
			}
			if (flag == false)
				ansList.add(str);
			return;
		}

		for (int i = 0; i < list.get(d).size(); i++) {
			if (isContain(str, list.get(d).get(i)) == 1) {
				dfs(d + 1, n, str + "," + list.get(d).get(i));
			}
		}
	}

	static public int solution(String[] user_id, String[] banned_id) {

		list = new ArrayList<ArrayList<String>>();
		ansList = new ArrayList<String>();

		for (int i = 0; i < banned_id.length; i++) {
			ArrayList<String> newList = new ArrayList<String>();
			list.add(newList);
		}

		for (int i = 0; i < banned_id.length; i++) {
			for (int j = 0; j < user_id.length; j++) {
				if (banned_id[i].length() == user_id[j].length()) {
					// 길이 같으면 일단 하고 봄

					String bann = banned_id[i];
					String user = user_id[j];
					boolean flag = false;

					for (int len = 0; len < bann.length(); len++) {
						if (bann.charAt(len) == '*')
							continue;

						if (bann.charAt(len) != user.charAt(len)) {
							flag = true;
							break;
						}
					}

					if (flag == false)
						list.get(i).add(user);
				}
			}
		}

		for (int i = 0; i < list.size(); i++) {
			Collections.sort(list.get(i));
		}

		// 순열 구하기
		dfs(0, banned_id.length, "");

		return ansList.size();
	}

	public static void main(String[] args) {
		String[] user_id = { "frodo", "fradi", "crodo", "abc123", "frodoc" };
		String[] banned_id = { "fr*d*", "abc1**" };
//		String[] banned_id = { "*rodo", "*rodo", "******" };
//		String[] banned_id = { "fr*d*", "*rodo", "******", "******" };

		System.out.println(solution(user_id, banned_id));
	}
}
