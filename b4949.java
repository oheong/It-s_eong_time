package algorithm;

import java.util.Scanner;
import java.util.Stack;

public class b4949 {
	static Stack<Character> stack;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		stack = new Stack<Character>();
		while (true) {
			boolean flag = false;
			String str = sc.nextLine();
			if (str.equals("."))
				break;
			for (int i = 0; i < str.length(); i++) {
				char c = str.charAt(i);
				if (c == '(' || c == '[') {
					stack.push(c);
					continue;
				}
				if (c == ')') {
					if (stack.isEmpty() || stack.peek() != '(') {
						System.out.println("no");
						flag = true;
						break;
					} else
						stack.pop();
					continue;
				}
				if (c == ']') {
					if (stack.isEmpty() || stack.peek() != '[') {
						System.out.println("no");
						flag = true;
						break;
					} else
						stack.pop();
					continue;
				}
			}
			if (flag == false) {
				if (stack.isEmpty())
					System.out.println("yes");
				else
					System.out.println("no");
			}
			stack.removeAll(stack);
		}
	}
}
