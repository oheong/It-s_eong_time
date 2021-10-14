
public class 없는숫자더하기 {

	static public int solution(int[] numbers) {
		int answer = 45;

		for (int i = 0; i < numbers.length; i++) {
			answer -= numbers[i];
		}

		return answer;
	}

	public static void main(String[] args) {
		int[] numbers = { 5,8,4,0,6,7,9};

		System.out.println(solution(numbers));
	}
}
