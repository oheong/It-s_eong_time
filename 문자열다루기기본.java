
public class 문자열다루기기본 {

	static public boolean solution(String s) {
		boolean answer = true;

		if (s.length() == 4 || s.length() == 6) {
			for (int i = 0; i < s.length(); i++) {
				char c = s.charAt(i);
				if (!('0' <= c && c <= '9')) // ㄴㅇㄱ 0도 숫자였던거임
					return false;
			}
		} 
		
		else
			return false;
		return answer;
	}

	public static void main(String[] args) {
		System.out.println(solution("1234"));
	}
}
