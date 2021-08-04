import java.util.*;
class Solution {
    HashMap<String, Integer> count = new HashMap<String, Integer>();
    public int[] solution(String[] genres, int[] plays) {      
        for(int i=0;i<genres.length;i++){
            if(!count.containsKey(genres[i])){ // 대소문자 잘 기억하기
                count.put(genres[i], plays[i]);
            }
            else{
                int temp = count.get(genres[i]);
                count.replace(genres[i], temp + plays[i]); // 이거 잘 기억해두기
            }
        }
        int max = 0;
        String str="";
        List<String> g = new ArrayList<String>();
        while(!count.isEmpty()){
            for(String key : count.keySet()){
                if(max<count.get(key)){
                    max=count.get(key);
                    str=key;
                }
            }
            g.add(str);
            max = 0;
            count.remove(str);
        }

        int index=0, cnt=0;
        int[] visited = new int[genres.length];
        List<Integer> a = new ArrayList<Integer>();
        for(int i = 0; i < g.size(); i++){ // 장르 정렬
            String string = g.get(i);
            for(int k=0;k<2;k++){
                max = 0;
                for(int j=0;j<genres.length;j++){
                    if(visited[j]==0&&genres[j].equals(string)){
                        if(max<plays[j]){
                            max=plays[j];
                            index=j;
                        }
                    }
                }
                if(max!=0){
                    visited[index]=1;
                    a.add(index);
                }
            }
        }
       int[] answer = new int[a.size()];
        for(int i=0;i<a.size();i++)
            answer[i]=a.get(i);
        return answer;
    }
}
