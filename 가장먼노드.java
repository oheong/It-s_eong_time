import java.util.*;
class Solution {
    static int[] visited;
    static Queue<Integer> queue;
    static ArrayList<ArrayList<Integer>> list;
    public int solution(int n, int[][] edge) {
        int answer = 0;

        queue = new LinkedList<Integer>();
        list = new ArrayList<ArrayList<Integer>>();
        visited = new int[n + 1];
        
        for(int i = 0; i <= n; i++){
            list.add(new ArrayList<Integer>());
            visited[i] = 2123456789;
        }
        
        for(int i = 0; i < edge.length; i++){
            list.get(edge[i][0]).add(edge[i][1]);
            list.get(edge[i][1]).add(edge[i][0]);
        }
        
//        for(int i=1;i<n;i++){
//            System.out.print(i+" : ");
//            for(int j=0;j<list.get(i).size();j++){
//                System.out.print(list.get(i).get(j)+" ");
//            }System.out.println();
//        }
        
        queue.add(1);
        visited[1] = 1;
        
        int max = 0;
        
        while(!queue.isEmpty()){
            int num = queue.remove();
            int tstep = visited[num];
            
            while(!list.get(num).isEmpty()){
                int next = list.get(num).remove(0);
                int index = list.get(next).indexOf(num);
                
                list.get(next).remove(index); // 중복되는거 제거
                
                if(visited[next] > tstep + 1){
                    if(max < tstep + 1)
                        max = tstep + 1;
                    visited[next] = tstep + 1;        
                    queue.add(next);
                }
            }
        }

        for(int i = 0;i <= n; i++){
            if(visited[i] == max) answer++;
        }
        return answer;
    }
}
