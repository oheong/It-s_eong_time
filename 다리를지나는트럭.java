import java.util.*;
class Solution {
    static class Truck{
        int bridge;
        int weight;
        int time;
        public Truck(int bridge, int weight, int time){
            this.bridge = bridge;
            this.weight = weight;
            this.time = time;
        }
    }
    Queue <Truck> queue;
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;
        int[] time = new int[truck_weights.length];
        
        queue = new LinkedList<Truck>();
        
        for(int i = 0; i < truck_weights.length; i++){
            Truck t = new Truck(0, truck_weights[i], 0);
            queue.add(t);
        }
        int total_weight = 0;
        
        while(!queue.isEmpty()){
            int tb = queue.peek().bridge;
            int tw = queue.peek().weight;
            int tt = queue.peek().time;
            queue.remove();
            
            System.out.println(tw + " " + answer);
            
            if(tb == bridge_length){
                // 다리길이만큼 갔음
                answer++;
                total_weight -= tw;
            }
            else{
                if(total_weight + tw <= weight){ // 다리에 새롭게 진입한 트럭
                    total_weight += tw ;
                    Truck nTruck = new Truck(tb + 1, tw, tt);
                    queue.add(nTruck);  
                }
                else{ // 다리에 이미 다른 차가 있음                    
                    // 그 다른차가 나임
                    if(tb != 0){
                        answer++;
                        Truck nTruck = new Truck(tb + 1, tw, tt);
                        queue.add(nTruck);
                    }
                    // 그 다른차가 내가 아님
                    else{
                        Truck nTruck = new Truck(tb, tw, tt);
                        queue.add(nTruck);
                    }
                }
            }
        }
        return answer;
    }
}
