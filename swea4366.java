import java.util.Scanner;

public class swea4366 {

	static long ans;
	static long bNum = 0;
	static long tNum = 0;
	static long[] bNumArr = new long[41];
	static long[] tNumArr = new long[41];
	static char[] binary, triple;

	static long getAns() {
		for (int i = 0; i < binary.length; i++) {
			if (binary[i] == '1')
				bNum -= bNumArr[i];
			else
				bNum += bNumArr[i];
			for (int j = 0; j < triple.length; j++) {
				if (triple[j] == '0') {
					tNum += tNumArr[j];
					if (tNum == bNum)
						return bNum;
					tNum += tNumArr[j];
					if (tNum == bNum)
						return bNum;
					tNum -= tNumArr[j];
					tNum -= tNumArr[j];
				}

				else if (triple[j] == '1') {
					tNum -= tNumArr[j];
					if (tNum == bNum)
						return bNum;
					tNum += tNumArr[j];
					tNum += tNumArr[j];
					if (tNum == bNum)
						return bNum;
					tNum -= tNumArr[j];
				}

				else {
					tNum -= tNumArr[j];
					tNum -= tNumArr[j];
					if (tNum == bNum)
						return bNum;
					tNum += tNumArr[j];
					if (tNum == bNum)
						return bNum;
					tNum += tNumArr[j];
				}
			}
			if (binary[i] == '1')
				bNum += bNumArr[i];
			else
				bNum -= bNumArr[i];
		}
		return -1;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		bNumArr[0] = 1;
		tNumArr[0] = 1;
		for (int i = 1; i <= 40; i++) {
			bNumArr[i] = bNumArr[i - 1] * 2;
			tNumArr[i] = tNumArr[i - 1] * 3;
		}
		int T = sc.nextInt();
		for (int test = 0; test < T; test++) {
			String b = sc.next();
			String t = sc.next();

			binary = new char[b.length()];
			triple = new char[t.length()];

			int tempB = b.length();
			int tempT = t.length();
			for (int i = 0; i < tempB; i++)
				binary[i] = b.charAt(tempB - 1 - i);
			for (int i = 0; i < tempT; i++)
				triple[i] = t.charAt(tempT - 1 - i);

			bNum = 0;
			tNum = 0;
			for (int i = 0; i < binary.length; i++)
				bNum += ((binary[i] - '0') * bNumArr[i]);
			for (int i = 0; i < triple.length; i++)
				tNum += ((triple[i] - '0') * tNumArr[i]);

			System.out.printf("#%d %d\n", test + 1, getAns());
		}
	}
}
