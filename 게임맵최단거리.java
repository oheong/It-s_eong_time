import java.util.*;

class Solution {
    static int N, M;
    static int[] by={-1,0,1,0}, bx={0,1,0,-1};
    static int[][] visited;
    static Queue<Point> queue;
    static class Point{
        int y;
        int x;
        int step;
        public Point(int y, int x, int step){
            this.y = y;
            this.x = x;
            this.step = step;
        }
    }
    static void bfs(int[][] map){
        
        queue.add(new Point(0, 0, 1));
        visited[0][0] = 1;
        
        System.out.println(queue.size());
        
        while(!queue.isEmpty()){
            int ty = queue.peek().y;
            int tx = queue.peek().x;
            int tstep = queue.peek().step;
            
            queue.remove();
            
            for(int i = 0; i < 4; i++){
                int ny = ty + by[i];
                int nx = tx + bx[i];
                if(0 <= ny && ny < N && 0 <= nx && nx < M && map[ny][nx] == 1 && visited[ny][nx] == 0){
                    //System.out.println(ny+ " "+nx);
                    visited[ny][nx] = tstep + 1;
                    queue.add(new Point(ny, nx, tstep + 1));
                }
            }
        }
    }
    public int solution(int[][] maps) {
        int answer = -1;
        N = maps.length;
        M = maps[0].length;
        
        queue = new LinkedList<Point>();
        visited = new int[N][M];
        
        bfs(maps);

        return visited[N - 1][M - 1] == 0? -1: visited[N - 1][M - 1];
    }
}
