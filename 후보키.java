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
            
            ArrayList<String> tempList = new ArrayList<String>();
            
            //list에 int형으로 들어가있음
            for(int i=0;i<ans.size();i++){
                String[] ansStr = ans.get(i).split(""); // ans에 있는것들 전부다 짤라줌
                
                for(int j=0;j<ansStr.length;j++){
                    for(int t=0;t<tempList.size();t++){
                        tempList.add(Integer.toString(list.get(t)));
                    }
                    for(int t=0;t<tempList.size();t++){
                        if(tempList.get(t).equals(ansStr[j])){
                            tempList.remove(t);
                            break;
                        }
                    }
                }
            }  
            
            String str = "";
            for(int i = 0; i < list.size(); i++){
                str += Integer.toString(list.get(i));
            }
            /* 
            for(int i = 0; i < ans.size(); i++){
                if(str.contains(ans.get(i))) return;
            }   
            // 후처리 한번 더
            ArrayList<Integer> map = new ArrayList<Integer>();
            for(int i=0;i<list.size();i++){
                String[] strArr = str.split("");
                for(int j=0;j<str.length();j++){
                    if(list.get(i).equals(strArr[j])){
                        map.add(1);
                        break;
                    }
                }
            }
            if(list.size() == map.size())
                return;
            */
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
