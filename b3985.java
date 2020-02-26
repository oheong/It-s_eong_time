import java.util.Scanner;

public class b3985 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int people = sc.nextInt();
		int[] map = new int[N + 1];
		int wantMax = 0, realMax = 0;
		int wantP = 0, realP = 0;
		for (int i = 0; i < people; i++) {
			int s = sc.nextInt();
			int e = sc.nextInt();
			int count = 0;
			if (wantMax < e - s + 1) {
				wantMax = e - s + 1;
				wantP = i + 1;
			}
			for (int j = s; j <= e; j++) {
				if (map[j] == 0) {
					map[j] = i + 1;
					count++;
				}
			}
			if (realMax < count) {
				realMax = count;
				realP = i + 1;
			}
		}
		System.out.printf("%d\n%d", wantP, realP);
	}
}
