import java.util.LinkedList;
import java.util.Queue;

public class kakao_1 {
	static String step1(String id) {
		// 1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
		String returnIDString = "";
		for (int i = 0; i < id.length(); i++) {
			char c = id.charAt(i);
			if (65 <= c && c <= 90) {
				c += 32;
			}
			returnIDString += c;
		}
		return returnIDString;
	}

	static String step2(String id) {
//		2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
		String returnIdString = "";
		for (int i = 0; i < id.length(); i++) {
			char c = id.charAt(i);
			if ((97 <= c && c <= 122) || (0 <= c - '0' && c - '0' < 10) || c == '-' || c == '_' || c == '.') {
				returnIdString += c;
			}
		}
		return returnIdString;
	}

	static String step3(String id) {
//		3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
		Queue<Character> queue = new LinkedList<Character>();
		String returnIdString = "";
		for (int i = 0; i < id.length(); i++) {
			queue.add(id.charAt(i));
		}
		while (!queue.isEmpty()) {
			char c = queue.peek();
			queue.remove();
			if (c == '.') {
				while (!queue.isEmpty()) {
					if (queue.peek() == '.') {
						queue.remove();
						continue;
					} else
						break;
				}
			}
			returnIdString += c;
		}
		return returnIdString;
	}

	static String step4(String id) {
//		4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
		int len = id.length();
		if (id.charAt(len - 1) == '.')
			id = id.substring(0, len - 1);
		if (id.length() == 0)
			return id;
		len = id.length();
		if (id.charAt(0) == '.')
			id = id.substring(1, len);
		return id;
	}

	static String step5(String id) {
//		5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
		if (id.length() == 0)
			return "a";
		return id;
	}

	static String step6(String id) {
//		6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
//	     만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
		if (15 < id.length()) {
			id = id.substring(0, 15);
			id = step4(id);
		}
		return id;
	}

	static String step7(String id) {
//		7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
		if (id.length() < 3) {
			int len = id.length();
			char c = id.charAt(id.length() - 1);
			for (int i = 0; i < 3 - len; i++) {
				id += c;
			}
		}
		return id;
	}

	static public String solution(String new_id) {
		new_id = step1(new_id);
		new_id = step2(new_id);
		new_id = step3(new_id);
		new_id = step4(new_id);
		new_id = step5(new_id);
		new_id = step6(new_id);
		new_id = step7(new_id);
		return new_id;
	}

	public static void main(String[] args) {
		System.out.println(solution("abcdefghijklmn.p"));
	}
}
