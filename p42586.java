import java.util.*;
class Solution {
    static Queue<Integer> queue;
    public int[] solution(int[] progresses, int[] speeds) {
        queue = new LinkedList<Integer>();
        for(int i=0;i<progresses.length;i++){
            int temp = 100-progresses[i];
            if(temp%speeds[i]==0)
                queue.add(temp/speeds[i]);
            else
                queue.add((temp/speeds[i])+1);
        }
        int cnt=1;
        List<Integer> list = new ArrayList<Integer>();
        while(!queue.isEmpty()){
            int temp = queue.remove();
            if(queue.size()!=0&&temp>=queue.peek()){
                while(!queue.isEmpty()){
                    if(queue.peek()<=temp){
                        queue.remove();
                        cnt++;
                    }
                    else break;
                }
            }
            list.add(cnt);
            cnt=1;
        }
        int[] answer = new int[list.size()];
        for(int i=0;i<list.size();i++){
            answer[i]=list.get(i);
        }
        return answer;
    }
}
