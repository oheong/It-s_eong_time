import java.util.Scanner;

public class b2023 {
	static int N, s_count;
	static int[] visited;

	static int get_num(int depth) {
		int sum = visited[0];
		for (int i = 1; i < depth; i++) {
			sum *= 10;
			sum += visited[i];
		}
		return sum;
	}

	static int is_sosu(int num) {
		if (num == 1) return -1;
		if (num == 2) return 1;
		for (int i = 2; i < num; i++) {
			if (num % i == 0) return -1;
		}
		return 1;
	}

	static void dfs(int d) {
		if (d == N) {
			// 최종 소수인지 아닌지 검사해보고 소수가 맞으면 프린트하기
			int temp = get_num(d);
			if (is_sosu(temp) == 1)
				System.out.println(temp);
			return;
		}
		for (int i = 1; i < 10; i++) {
			visited[d] = i;
			if (is_sosu(get_num(d)) == 1)
				dfs(d + 1);
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		visited = new int[N];
		dfs(0);
	}
}
