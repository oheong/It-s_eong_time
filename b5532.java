import java.util.Scanner;

public class b5532 {
	static int L, A, B, C, D, ans;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		L = sc.nextInt();
		A = sc.nextInt();
		B = sc.nextInt();
		C = sc.nextInt();
		D = sc.nextInt();

		double kor = A / C;
		double math = B / D;

		if (kor < math) {
			if (B % D == 0)
				ans = (int) math;
			else
				ans = (int) math + 1;
		} else {
			if (A % C == 0)
				ans = (int) kor;
			else
				ans = (int) kor + 1;
		}
		System.out.println(L - ans);
	}
}
// 50퍼 틀림 뭐지?