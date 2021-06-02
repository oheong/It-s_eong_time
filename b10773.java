import java.util.Scanner;
import java.util.Stack;

public class b10773 {
	static int K;
	static Stack<Integer> stack;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		K = sc.nextInt();
		stack = new Stack<Integer>();
		int tempNum = 0;
		for (int i = 0; i < K; i++) {
			tempNum = sc.nextInt();
			if (tempNum == 0)
				stack.pop();
			else
				stack.push(tempNum);
		}
		int sum = 0;
		while (!stack.isEmpty())
			sum += stack.pop();
		System.out.println(sum);
	}
}
