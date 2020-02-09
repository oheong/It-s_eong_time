import java.util.Scanner;

public class b1706 {
	static int R, C;
	static char[][] map;
	static String ans = "zzzzzzzzzzzzzzzzzzzz";
	static String temp = "";
	static int count = 0;
	static int flag = 0;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		R = sc.nextInt();
		C = sc.nextInt();
		map = new char[R][C];
		for (int i = 0; i < R; i++) {
			String temp = sc.next();
			for (int j = 0; j < C; j++) {
				map[i][j] = temp.charAt(j);
			}
		}
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (map[i][j] == '#') {
					flag = 1;
					if (temp == "") {
						flag = 0;
						continue;
					}
					if (ans.compareTo(temp) > 0 && count > 1) { // ans 가 크면 양수
						ans = temp;
					}
					temp = "";
					count = 0;
				}
				if (flag != 1) {
					temp += map[i][j];
					count++;
				}
			}
			if (flag == 0) {
				if (ans.compareTo(temp) > 0 && count > 1) {
					ans = temp;
				}
				count = 0;
				temp = "";
			}
			flag = 0;
		}
		// 가로로 보면서 내려옴
		for (int j = 0; j < C; j++) {
			for (int i = 0; i < R; i++) {
				if (map[i][j] == '#') {
					flag = 1;
					if (temp == "") {
						flag = 0;
						continue;
					}
					if (ans.compareTo(temp) > 0 && count > 1) {
						ans = temp;
					}
					temp = "";
					count = 0;
				}
				if (flag == 0) {
					temp += map[i][j];
					count++;
				}
			}
			if (flag == 0) {
				if (ans.compareTo(temp) > 0 && count > 1) {
					ans = temp;
				}
				temp = "";
				count = 0;
			}
			flag = 0;
		}
		System.out.println(String.format("%s", ans));
	}
}
//한개짜리는 패스해야함