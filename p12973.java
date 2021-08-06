import java.util.*;
class Solution
{
    Stack<Character> stack;
    public int solution(String s)
    {
        stack = new Stack<Character>();
        int answer = -1;
        
        //stack.push(s.charAt(0));
        for(int i=0;i<s.length();i++){
            char c = s.charAt(i);
            if(!stack.isEmpty()&&stack.peek()==c)
                stack.pop();
            else
                stack.push(c);
        }
        if(stack.size()==0) answer=1;
        else answer=0;
        return answer;
    }
}
