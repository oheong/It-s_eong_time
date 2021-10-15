import java.util.HashMap;

public class 다단계칫솔판매 {

	static public int[] solution(String[] enroll, String[] referral, String[] seller, int[] amount) {
		int[] answer = new int[enroll.length];

		HashMap<String, Integer> index = new HashMap<String, Integer>();

		for (int i = 0; i < enroll.length; i++) {
			index.put(enroll[i], i); // 인덱스 저장
		}

		for (int i = 0; i < seller.length; i++) {
			String name = seller[i]; // 판 사람
			int money = amount[i] * 100;

			while (!"-".equals(name)) {
				int idx = index.get(name);

				int toParent = money / 10; // 위로 줄거
				int myMoney = money - toParent; // 내가 가지고 있을거

				answer[idx] += myMoney;

				if (money * 0.1 < 1)
					break;

				name = referral[idx];

				money = toParent;
			}

		}

		return answer;
	}

	public static void main(String[] args) {

		String[] enroll = { "john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young" }; // 후임
		String[] referral = { "-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward" }; // 선임
		String[] seller = { "young", "john", "tod", "emily", "mary" };
		int[] amount = { 12, 4, 2, 5, 10 };
		System.out.println(solution(enroll, referral, seller, amount));
	}
}
