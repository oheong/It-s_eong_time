import java.util.*;
class Solution {
    boolean solution(String s) {
        Stack<Character> stack = new Stack<Character>();
        if(s.length() == 0) return true;
        if(s.charAt(0) == ')' || s.charAt(s.length() - 1) == '(' || s.length()%2 == 1) return false;

        for(int i = 0; i < s.length(); i++){
            Character c = s.charAt(i);
            if(!stack.isEmpty() && c == ')' && stack.peek() == '(')
                stack.pop();
            
            else
                stack.push(c);
        }
        return stack.isEmpty();
    }
}
