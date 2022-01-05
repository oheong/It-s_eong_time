import java.util.*;
class Solution {
    static ArrayList<Integer> p, l;
    public int solution(int[] priorities, int location) {
        int answer = 0;
        p = new ArrayList<Integer>();
        l = new ArrayList<Integer>();
        for(int i = 0; i <priorities.length; i++){
            p.add(priorities[i]);
            l.add(i);
        }
        
        while(true){
            int max = p.get(0);
            int cnt = 0;
            
            for(int i = 0; i < p.size(); i++){
                if(max < p.get(i)){
                    max = p.get(i);
                    cnt = i;
                }
            }
            
            for(int i=0;i<cnt;i++){
                p.add(p.get(0));
                p.remove(0);
                l.add(l.get(0));
                l.remove(0);
            }
            
            answer++;
            
            if(l.get(0) == location)
                break;
            
            p.remove(0);
            l.remove(0);
        }

        return answer;
    }
}
