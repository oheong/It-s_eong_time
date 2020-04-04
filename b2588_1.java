import java.util.Scanner;

public class b2588_1 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] ansArr = new int[3];
		String A = sc.next();
		String B = sc.next();
		int ans = 0;
		for (int b = 0; b < B.length(); b++) {
			ans *= 10;
			int sum = 0;
			for (int a = 0; a < A.length(); a++) {
				sum *= 10;
				int u = A.charAt(a) - '0';
				int d = B.charAt(b) - '0';
				int temp = u * d;
				sum += temp;
			}
			// System.out.println(sum);
			ansArr[A.length() - b - 1] = sum;
			ans += sum;
		}
		for (int i = 0; i < A.length(); i++)
			System.out.println(ansArr[i]);
		System.out.println(ans);
	}
}
