import java.util.*;
class Solution {
    static HashMap<String, Integer> hash;
    static int turn(int n, int num){
        if(num == 0) return n;
        return num;
    }
    public int[] solution(int n, String[] words) {
        int[] answer = {0, 0};
        hash = new HashMap<String, Integer>();
        
        String str = words[0];
        hash.put(str, 1);
        
        for(int i = 1; i < words.length; i++){
            char end = str.charAt(str.length() - 1);
            char start = words[i].charAt(0);
            
            if(start == end && !hash.containsKey(words[i])){
                str = words[i];
                hash.put(str, 1);
            }
            else{
                i++;
                answer[0] = turn(n, i % n);
                answer[1] = (int)Math.ceil((double)i / (double)n);
                break;
            }
        }
        
        return answer;
    }
}
