class Solution {
    static int max = 0;
    static int[] visited;
    static void dfs(int d, int n, int power, int[][] dungeons){
        if(power < 0) return;
        if(max < d) max = d;
        
        for(int i = 0; i < dungeons.length; i++){
            if(visited[i] == 0 && dungeons[i][0] <= power){
                visited[i] = d + 1;
                dfs(d + 1, i, power - dungeons[i][1], dungeons);
                visited[i] = 0;
            }
        }
        
    }
    public int solution(int k, int[][] dungeons) {
        visited = new int[dungeons.length];
        dfs(0, 0, k, dungeons);        
        return max;
    }
}
