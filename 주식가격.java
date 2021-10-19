import java.util.*;
class Solution {
    static Queue<Integer> queue;
    public int[] solution(int[] prices) {
        int[] ans = new int[prices.length];
        
        for(int i = 0; i < prices.length - 1; i++){
            int now = prices[i];
            for(int j = i + 1; j < prices.length; j++){
                ans[i]++;
                if(now > prices[j])
                    break;
            }
        }
        
        return ans;
    }
}
