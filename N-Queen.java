class Solution {
    static int ans;
    static int check(int y, int x, int N, int[][] map){
        // 세로
        for(int i = 0; i < y; i++){
            if(map[i][x] == 1) return 0;
        }
        
        // 가로
        for(int j = 0; j < x; j++){
            if(map[y][j] == 1) return 0;
        }
        
        // 대각선
        int yy = y - 1;
        int xx = x - 1;    
        while(true){
            if(yy == -1||xx == -1)break;
            if(map[yy--][xx--] == 1) return 0;
        }
        yy = y - 1; xx = x + 1;
        while(true){
            if(yy == -1||xx == N)break;
            if(map[yy--][xx++] == 1) return 0;
        }
        return 1;
    }
    static void dfs(int d, int N, int n, int[][] map){
        if(d == N){
            ans++;
            return;
        }
        for(int i = 0; i < N; i++){
            if(check(d, i, N, map) == 1){
                map[d][i] = 1;
                dfs(d + 1, N, i, map);
                map[d][i] = 0;
            }
        }
    }
    public int solution(int n) {
        int[][] map = new int[n][n];
        dfs(0, n, 0, map);
        return ans;
    }
}
