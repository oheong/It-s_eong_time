import java.util.*;
class Solution {
    static int[] visited;
    static Queue<Integer> queue, step;
    static ArrayList<ArrayList<Integer>> list;
    public int solution(int n, int[][] edge) {
        int answer = 0;
        
        // 이거 미쳤다 ㅎㅎ;ㅎ;ㅎㅎㅎ;ㅎ;ㅎ;ㅎ;ㅎ;ㅎ;ㅎ;ㅎㅎ;ㅎ;ㅎ
        // 어 근데 굳이 안해도될듯
        /*
        Arrays.sort(edge, new Comparator<int[]>(){
            public int compare(int[] a1, int[] a2){
                if(a1[0] == a2[0]){
                    return a1[1]-a2[1];
                }
                else return a1[0]-a2[0];
            }
        });
        */
        queue = new LinkedList<Integer>();
        step = new LinkedList<Integer>();
        list = new ArrayList<ArrayList<Integer>>();
        visited = new int[n + 1];
        
        for(int i = 0; i <= n; i++){
            list.add(new ArrayList<Integer>());
            visited[i] = 2123456789;
        }
        
        for(int i = 0; i < edge.length; i++){
            if(edge[i][0] == 1){
                queue.add(edge[i][1]);  
                step.add(1);
                visited[edge[i][1]] = 1;
            }
            list.get(edge[i][0]).add(edge[i][1]);
            if(edge[i][0] != 1)
                list.get(edge[i][1]).add(edge[i][0]);
        }
        
        int max = 0;
        
        while(!queue.isEmpty()){
            int num = queue.remove();
            int tstep = step.remove();
            
            for(int i = 0; i < list.get(num).size(); i++){
                if(visited[list.get(num).get(i)] > tstep + 1){
                    if(max < tstep + 1)max = tstep + 1;
                    visited[list.get(num).get(i)] = tstep + 1;        
                    queue.add(list.get(num).get(i));
                    step.add(tstep + 1);
                }
            }
            
        }

        for(int i = 0;i <= n; i++){
            if(visited[i] == max) answer++;
        }
        return answer;
    }
}
