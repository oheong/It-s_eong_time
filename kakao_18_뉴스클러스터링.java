import java.util.ArrayList;
import java.util.List;

public class kakao_18_뉴스클러스터링 {
	static int isOk(char a) {
		if (65 <= a && a < 91)
			return 2; // 대문자
		else if (97 <= a && a < 123)
			return 1; // 소문자

		else
			return 0;
	}

	static public int solution(String str1, String str2) {
		int answer = 0;
		char tempChar[] = new char[2];
		List<String> list1 = new ArrayList<String>(), list2 = new ArrayList<String>();
		for (int i = 0; i < str1.length() - 1; i++) {
			char c1, c2;
			c1 = str1.charAt(i);
			c2 = str1.charAt(i + 1);
			if (isOk(c1) != 0 && isOk(c2) != 0) {
				// 특수 문자 없이 둘다 알파벳
				if (isOk(c1) == 1)
					c1 = (char) (c1 - 32);
				if (isOk(c2) == 1)
					c2 = (char) (c2 - 32);
				tempChar[0] = c1;
				tempChar[1] = c2;
				list1.add(String.valueOf(tempChar));
			}
		}
		for (int i = 0; i < str2.length() - 1; i++) {
			char c1, c2;
			c1 = str2.charAt(i);
			c2 = str2.charAt(i + 1);
			if (isOk(c1) != 0 && isOk(c2) != 0) {
				// 특수 문자 없이 둘다 알파벳
				if (isOk(c1) == 1)
					c1 = (char) (c1 - 32);
				if (isOk(c2) == 1)
					c2 = (char) (c2 - 32);
				tempChar[0] = c1;
				tempChar[1] = c2;
				list2.add(String.valueOf(tempChar));
			}
		}
		if (list1.size() == 0 || list2.size() == 0)
			answer = 65536;
		else {
			int hap = 0;
			for (int i = 0; i < list1.size(); i++) {
				if (list1.get(i).contains("*"))
					continue;
				for (int j = 0; j < list2.size(); j++) {
					if (list2.get(j).contains("*"))
						continue;
					if (list1.get(i).contains(list2.get(j))) {
						list1.remove(i);
						list1.add(i, "*");
						list2.remove(j);
						list2.add(j, "*");
					}
				}
			}
			int gyo = list1.size() + list2.size();
			for (int i = 0; i < list1.size(); i++)
				if (list1.get(i).contains("*"))
					hap++;
			gyo -= hap;
			float tempNum = (float) hap / (float) gyo;
			answer = (int) (tempNum * 65536);
		}
		return answer;
	}

	public static void main(String[] args) {
		System.out.println(solution("E=M*C^2", "e=m*c^2"));
	}
}
