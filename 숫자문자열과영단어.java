
public class 숫자문자열과영단어 {
	static public int solution(String s) {
		String answer = "";

		while (s.length() != 0) {
			char c = s.charAt(0);

			if ('0' <= c && c <= '9') {
				answer += c;
				s = s.substring(1);
			}

			else if (c == 'z') {
				answer += '0';
				s = s.substring(4);
			}

			else if (c == 'o') {
				answer += '1';
				s = s.substring(3);
			}

			else if (c == 't') {
				if (s.charAt(1) == 'w') {
					answer += '2';
					s = s.substring(3);
				} else {
					answer += '3';
					s = s.substring(5);
				}
			}

			else if (c == 'f') {
				if (s.charAt(1) == 'o') {
					answer += '4';
					s = s.substring(4);
				} else {
					answer += '5';
					s = s.substring(4);
				}

			}

			else if (c == 's') {
				if (s.charAt(1) == 'i') {
					answer += '6';
					s = s.substring(3);
				} else {
					answer += '7';
					s = s.substring(5);
				}
			}

			else if (c == 'e') {
				answer += '8';
				s = s.substring(5);
			}

			else if (c == 'n') {
				answer += '9';
				s = s.substring(4);
			}
		}

		return Integer.parseInt(answer);
	}

	public static void main(String[] args) {
		System.out.println(solution("2three45sixseven"));
	}
}
