import java.util.*;
class Solution {
    static int[] visited;
    static ArrayList<Integer> list;
    static ArrayList<String> ans;
    static void dfs(int d, int N, int n, String[][] relation){
        if(d == N){
            HashMap<String, Integer> hash = new HashMap<String, Integer>();
            
            for(int i = 0; i < relation.length; i++){
                String str = "";
                for(int j = 0; j < list.size(); j++){
                    str += relation[i][list.get(j)];
                }
                int cnt = 1;
                if(hash.containsKey(str)){ // 키가 있다!
                    cnt = hash.get(str) + 1;
                }
                hash.put(str, cnt);
            }
            for(String key : hash.keySet()){
                if(1 < hash.get(key))
                    return; // 유일성 만족하지 못함
            } 
            // 유일성 만족 끝
            
            // 최소성 시작 ans, list            
            String str = "";
            for(int i = 0; i < list.size(); i++){
                str += Integer.toString(list.get(i));
            }
              
            for(int i = 0; i < ans.size(); i++){
                if(str.contains(ans.get(i))) // 지금 뽑아놓은게 이미 키에 포함되어있으면 return
                    return;
            }   
            // 후처리 한번 더
            for(int a = 0; a < ans.size(); a++){
                String[] temp = ans.get(a).split("");
                int cnt = 0;
                for(int i = 0; i < temp.length; i++){
                    for(int j = 0; j < str.length(); j++){
                        if(temp[i].equals(str.charAt(j)+"")){ // 같은게 있다!
                            cnt++;
                            break;
                        }
                    }
                }
                if(cnt == temp.length) return;
            }
            ans.add(str);
            return;
        }
        
        for(int i = n; i < visited.length; i++){
            if(visited[i] == 0){
                visited[i] = 1;
                list.add(i);
                dfs(d + 1, N, i + 1, relation);
                visited[i] = 0;
                list.remove(d);
            }
        }
    }
    public int solution(String[][] relation) {
        visited = new int[relation[0].length];
        
        list = new ArrayList<Integer>();
        ans = new ArrayList<String>();
        
        for(int i = 1; i <= visited.length; i++){
            dfs(0, i, 0, relation);
        }
        return ans.size();
    }
}