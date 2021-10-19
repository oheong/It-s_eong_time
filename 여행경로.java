import java.util.*;
class Solution {
    
    static int[] visited;
    static String[] answer;
    static HashMap<String, Integer> hashmap;
    
    static void dfs(int d, int n, int start, String[][] tickets, String str){
        if(d == n){
            for(int i = 0; i < answer.length; i++)
                System.out.print(answer[i] + " ");
            System.out.println();
            return;
        }
        
        int i = start;
        
        System.out.println(d+" "+start+" "+str);
        System.out.println(tickets[i][0]);
        System.out.println(tickets[start][0]);
        System.out.println("========");
        
        while(tickets[i][0].equals(tickets[start][0]) && i < tickets.length){
            System.out.println("들어오니? "+i);
            if(visited[i] == 0){
                visited[i] = 1;
                dfs(d + 1, n, hashmap.get(tickets[i][1]), tickets, str + tickets[i][1]);
            }
            i++;
        }
    }
    public String[] solution(String[][] tickets) {
        
        // 내가해냄!!!! 좀 더 기억하기
        Arrays.sort(tickets, new Comparator<String[]>(){
           public int compare(String[] s1, String[] s2){
               if(s1[0].equals(s2[0])){
                   return s1[1].compareTo(s2[1]);
               }
               else return s1[0].compareTo(s2[0]);
           } 
        });
        
        hashmap = new HashMap<String, Integer>();
        HashMap<String, Integer> site = new HashMap<String, Integer>();
        
        for(int i = 0; i < tickets.length; i++){
            if(!hashmap.containsKey(tickets[i][0]))
                hashmap.put(tickets[i][0], i);
            if(!site.containsKey(tickets[i][0]))
                site.put(tickets[i][0], 1);
            else if(!site.containsKey(tickets[i][1]))
                site.put(tickets[i][1], 1);
        }
        
            
        visited = new int[tickets.length];
        answer = new String[site.size()];

        dfs(0, tickets.length, hashmap.get("ICN"), tickets, "ICN");
        return answer;
    }
    
    // SIBAL
}
