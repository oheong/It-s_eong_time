import java.util.Scanner;

public class b11723 {
	static int M;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		M = sc.nextInt();
		String ss = "";
		int N = 0;
		int check = 0;
		StringBuffer sb = new StringBuffer();
		for (int m = 0; m < M; m++) {
			ss = sc.next();
			if (ss.equals("add")) {
				int num = sc.nextInt();
				if ((check & (1 << num)) == 0) {
					check = check | (1 << num);
				}
			}

			else if (ss.equals("remove")) {
				int num = sc.nextInt();
				if ((check & (1 << num)) != 0) {
					check = check ^ (1 << num);
				}
			}

			else if (ss.equals("check")) {
				int num = sc.nextInt();
				if ((check & (1 << num)) == 0) // 그 숫자가 없을때
					sb.append(0 + "\n");// System.out.println(0);
				else // 그 숫자가 있을 때
					sb.append(1 + "\n");// System.out.println(1);
			}

			else if (ss.equals("toggle")) {
				int num = sc.nextInt();
				if ((check & (1 << num)) != 0) // 제거하기
					check = check ^ (1 << num);
				else
					check = check | (1 << num);
			}

			else if (ss.equals("all")) {
				for (int i = 1; i <= 20; i++) {
					check = check | (1 << i);
				}
			}

			else if (ss.equals("empty")) {
				check = 0;
			}
		}
		System.out.println(sb);
	}
}
