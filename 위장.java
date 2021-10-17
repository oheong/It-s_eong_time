import java.util.*;
class Solution {
    static HashMap<String, List<String>> hashmap;
    static int answer;
    static int[] visited;
    List<List<String>> ans_list;
    
    static int combination(int n){
        int up = 1;
        int down = 1;
        for(int i = 1; i < n; i++){
            down *= i;
            up *= (n - i + 1);
        }
        return up/down;
    }
    
    void dfs(int d, int n){
        if(d == n){ 
            boolean flag = false;
            int gop = 1;
            for(int i = 0; i < n; i++){
                if(visited[i] == 1){
                    flag = true;
                    gop *= ans_list.get(i).size();
                }
            }
            if(flag == true)
                answer += gop;
            return;
        }
        visited[d]=1;
        dfs(d+1, n);
        visited[d]=0;
        dfs(d+1,n);
    }
    public int solution(String[][] clothes) {
        hashmap = new HashMap<String,List<String>>();
        
        for(int i = 0; i < clothes.length; i++){
            String type = clothes[i][1]; // key
            String item = clothes[i][0]; // value
            
            List<String> list;
            if(!hashmap.containsKey(type))
                list = new ArrayList<String>();
                
            else
                list = hashmap.get(type);
            
            list.add(item);
            hashmap.put(type, list);
        }
        if(hashmap.size() == 30) 
            return 1073741823;
        
        int[] num = new int[hashmap.size()];
        
        ans_list = new ArrayList<List<String>>(hashmap.values()); // 이자식 뭐냐 외워두기,,,아아아아아아ㅏ!!!!
        
        for(int i = 0; i < ans_list.size(); i++){
            num[i] = combination(ans_list.get(i).size());
        }
        
        visited = new int[ans_list.size()];
        dfs(0,ans_list.size());
        
        return answer;
    }
}
