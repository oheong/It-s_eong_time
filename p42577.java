import java.util.*;
class Solution {
    HashMap<String, Integer> hash;
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        hash = new HashMap<String, Integer>();
        
        Arrays.sort(phone_book);
        
        hash.put(phone_book[0], 1);
        
        for(int i = 1; i < phone_book.length; i++){
            if(phone_book[i].startsWith(phone_book[i - 1]))
                return false;
            
        }
        
        return answer;
    }
}
