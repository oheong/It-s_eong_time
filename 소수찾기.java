import java.util.*;
class Solution {
    static String[] number;
    static HashMap<Integer, Integer> hashmap;
    static int[] visited;
    
    static int prime(int n){
        for(int i = 2; i*i <= n; i++){ // 소수구하는 공식 잘 알아놓기
            if(n % i == 0)
                return 0;
        }
        return 1;
    }
    static void dfs(int d, int depth, int n, String str){
        if(d == depth){
            if(str.equals("")) return;    
            
            int total = Integer.parseInt(str);
            
            if(total == 0 || total == 1) // 0이랑 1은 소수아님 소수는 2부터
                return;
            
            if(prime(total) == 1){
                if(!hashmap.containsKey(total)){
                    hashmap.put(total, 1);
                }
            }
            
            return;
        }
        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                visited[i] = 1;
                dfs(d+1, depth, n, str + number[i]);
                visited[i] = 0;
            }
        }
    }
    public int solution(String numbers) {
        
        hashmap = new HashMap<Integer, Integer>();
        number = numbers.split("");
        visited = new int[number.length];

        for(int i = 1; i <= number.length; i++)
        dfs(0, i, number.length, "");
        
        // List<Integer> list = new ArrayList<Integer>(hashmap.keySet()); // 이거 알아두기 value는 hashmap.values()
        // for(int i=0;i<list.size();i++)System.out.println(list.get(i));
        
        return hashmap.size();
    }
}
