import java.util.Arrays;

public class 입국심사 {

	static public long solution(int n, int[] times) {
		Arrays.sort(times);

		long nn = n; // ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋint * long 방지
		long low = 0;
		long high = times[times.length - 1] * nn; // 제일 오래 걸리는 시간

		while (low != high) {
			long mid = (low + high) / 2; // 시간 평균
			long sum = 0;
			for (int i = 0; i < times.length; i++) {
				sum += mid / times[i]; // i번째 심사위원이 mid 시간동안 심사할 수 있는 사람 수★
			}
			// 전체 심사위원이 mid 시간동안 심사할 수 있는 사람의 수가 전체 사람의 수(n)과 같아지는 mid를 찾는게 정답.
			if (nn <= sum)
				high = mid;
			else
				low = mid + 1;
		}

		return low;
	}

	public static void main(String[] args) {
		int[] times = { 7, 10 };
		System.out.println(solution(6, times));
	}
}
