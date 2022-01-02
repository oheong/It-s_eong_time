import java.util.*;
class Solution {
    
    static HashMap<String, Integer> hash;
    
    static void dfs(int d, int num, int n, String str, String menu){
        if(d == num){
            if(hash.containsKey(str)){ // str을 포함하고 있으면
                int cnt = hash.get(str);
                hash.put(str, cnt + 1);
            }
            else
                hash.put(str, 1);
            return;
        }
        for(int i = n; i < menu.length(); i++){
            dfs(d + 1, num, i + 1, str + menu.split("")[i], menu);
        }
    }
    
    public String[] solution(String[] orders, int[] course) {
        hash = new HashMap<String, Integer>();
        
        for(int i = 0; i < orders.length; i++){
            String[] temp = orders[i].split("");
            Arrays.sort(temp);
            String str = "";
            for(int j = 0;j < temp.length; j++){
                str += temp[j];
            }
            orders[i] = str;
        } // orders 정렬
        
        for(int c = 0; c < course.length; c++){
            for(int o = 0; o < orders.length; o++){
                if(course[c] <= orders[o].length()){
                    dfs(0, course[c], 0, "", orders[o]);
                }
            }
        } // 각 메뉴별 주문 횟수 카운팅

        ArrayList<String> removeStr = new ArrayList<String>();
        for(String key : hash.keySet()){
            if(hash.get(key) < 2)
                removeStr.add(key);
        } 
        for(int i = 0; i < removeStr.size(); i++)
            hash.remove(removeStr.get(i));
        // 주문횟수 2회 이하 삭제
        
        int[] count = new int[course[course.length - 1] + 1];
        for(int i = 0; i < course.length; i++){
            for(String key : hash.keySet()){
                if(key.length() == course[i]){
                    if(count[course[i]] < hash.get(key))
                        count[course[i]] = hash.get(key);
                }
            }
        } // 카운트 max 찾기

        ArrayList<String> keys = new ArrayList<String>(hash.keySet());
        Collections.sort(keys, new Comparator<String>(){
           public int compare(String s1, String s2){
               return s1.compareTo(s2);
           } 
        });
        
        ArrayList<String> list = new ArrayList<String>();
        for(int i = 0; i < keys.size(); i++){
            if(hash.get(keys.get(i)) == count[keys.get(i).length()]){
                list.add(keys.get(i));
            }
        }
        
        String[] answer = new String[list.size()];
        for(int i = 0; i < list.size(); i++){
            answer[i] = list.get(i);
        }
        
        /*
        for(String key : hash.keySet()) { // 나 이거 기억 너무 잘 하고있네 뿌듯하다 ㅎㅎ
            System.out.println(key+" " +hash.get(key));
        } 
        */
        return answer;
    }
}
